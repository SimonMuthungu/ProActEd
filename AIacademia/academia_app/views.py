from django import forms
import logging
import sys
from django.http import Http404 , JsonResponse
from django.contrib import messages
from django.contrib.auth import authenticate, login
from django.contrib.auth.decorators import login_required
from django.http import Http404 , JsonResponse
from django.shortcuts import redirect, render
from python_scripts.proacted_recommender2024 import proacted2024
from python_scripts.sbert_recommender import sbert_proactedrecomm2024
from django.shortcuts import render, redirect
from django.http import HttpResponseRedirect
from django.contrib import messages
from python_scripts.recommender_engine import load_model
from .forms import UserProfileForm
from .models import BaseUser,UserProfile,Course,School,Performance,Student,Message, probabilitydatatable
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.contrib.auth.decorators import login_required
from .forms import UserProfileForm
from django.core.mail import send_mail
from sre_constants import BRANCH
from telnetlib import LOGOUT
from django.shortcuts import render, redirect
from django.contrib.auth.views import LoginView
from django.contrib.auth import authenticate ,login
from django.urls import reverse_lazy
from django.contrib.auth import authenticate
from django.contrib.auth import authenticate ,login , logout
from django.contrib.auth import login
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
from django.http import HttpRequest
from .models import Course, School # Import Course and School models
from django.contrib.auth.models import User
from django.contrib import messages
import os


import joblib
from .models import Course, School, Recommender_training_data  # Import Course and School models
import tensorflow as tf
import numpy as np


logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')


def login_view(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        user = authenticate(request, username=username, password=password)
        

        if user is not None:

            if user.is_active:
                login(request, user)
                # Redirect based on user type
                if user.is_superuser or user.is_staff:
                    return redirect('/admin/')
                else:
                    return redirect('student_page')
            else:
                # User is not active
                return render(request, 'academia_app/login.html', {'error': 'Account is inactive.'})
        else:
            # Authentication failed
            return render(request, 'academia_app/login.html', {'error': 'Invalid username or password.'})

    return render(request, 'academia_app/login.html')



def course_recommendation_page(request):
    return render (request,"academia_app/course_recommendation_page.html")

def intervention (request):
    return render (request, "academia_app/intervention.html")

def intervention_page (request):
    return render (request, "academia_app/intervention_page.html")

def admin_page(request):
    return render(request, "academia_app/admin_page.html")

def admin_login_view(request):
    # Your view logic for admin login goes here
    return render(request, "admin_login.html")  # Replace "admin_login.html" with the actual template
def predict(request):
    return render(request, 'academia_app/predict.html')
    

# loading the script and generating output
def recommend_courses(request):
    if request.method == 'POST':
        # Getting selected subjects with name
        user_subjects_done = request.POST.getlist('subjects[]')
        user_subjects_done = ' '.join(user_subjects_done).lower() 


        # Getting values from the interests field
        user_activities_enjoyed = request.POST.getlist('interests[]')
        user_activities_enjoyed = ' '.join(user_activities_enjoyed).lower() 


        # textarea
        user_description_about_interests = request.POST.getlist('additionalInfo')
        user_description_about_interests = ''.join(user_description_about_interests).lower() 
        #user_description_about_interests = ''.join(user_activities_enjoyed).lower() 
        print(user_description_about_interests)
        try: 
            # Load the model and get the output
            print("\nBeginning to run the recommender script")
            logging.info("Beginning to run the proacted recommender script")
            proacted_recommendations = proacted2024(user_description_about_interests, user_activities_enjoyed)
            print(f"here are the proacted_recommendations: {proacted_recommendations}")
            print(f"Done with proacted, proceeding to sbert recommender")
            sbert_recommendations = sbert_proactedrecomm2024(user_description_about_interests, user_activities_enjoyed)
            print(f"here are the sbert_recommendations: {sbert_recommendations}") 
            context = {'proacted_recommendations': proacted_recommendations}
            return render(request, 'academia_app/recommended_courses.html', context)
        except:
            print('Something came up, please rerun the system...')
            logging.critical('Something came up, please rerun the system...')
        # Pass proacted_recommendations to the template
        finally:
            logging.info('Recommender system has run')
    else:
        return render(request, 'academia_app/login.html')        

            
        
        
def predict_probability(request):
    # model = joblib.load(r'C:\Users\Hp\Desktop\ProActEd\AIacademia\trained_models\no_bias_trainedw_100000_10288genii.joblib')
    # logging.info('Probability model loaded')
    try:
        model_path = r'C:\Users\Hp\Desktop\ProActEd\AIacademia\trained_models\no_bias_trainedw_100000_10288genii.joblib'
        model = joblib.load(model_path)
        logging.info('Probability model loaded with joblib.')
    except Exception as e:
        logging.error(f"Error loading model: {e}")
        return HttpResponse(f"Error loading model: {e}", status=500)

    student_id = 6

    try:
        student_data = probabilitydatatable.objects.get(id=student_id) 
        lessonsattended = student_data.Lessons_Attended
        aggrpoints = student_data.Aggregate_points

    except probabilitydatatable.DoesNotExist:
        # the student doesnt exist
        pass

    input_data = [[lessonsattended, aggrpoints]]

    # Predict probabilities
    prediction = model.predict(input_data)

    context = {'prediction': prediction[0]} 
    return HttpResponse(f'Calculated Probability: {prediction[0]} for inputs {input_data} of student {student_id}') 


    

@login_required
def dashboard(request):
    # Redirect users based on their type
    if request.user.is_superuser or request.user.is_staff:
        return redirect('/admin/')  # Superadmin and Staff to Django admin
    else:
        return redirect('student_page')  # Students to student page

@login_required
def student_page(request):
    if request.user.groups.filter(name='Student Users').exists():
        return render(request, "academia_app/student_page.html",context ={ 'text': 'Hello world'})
    else:
        if request.user.is_superuser or request.user.is_staff:
            return redirect('/admin/')
        return redirect('login') 

def course_recommendation(request):
    return render(request, 'academia_app/course_recommendation_page.html',)


@login_required
def school_list(request):
    if request.user.is_staff:
        schools = School.objects.all()
        courses = Course.objects.all()
        return render(request, 'academia_app/school_list.html', {'schools': schools, 'courses': courses})
    else:
        return redirect('login')

@login_required
def get_courses(request, school_id):
    if request.user.is_authenticated:
        courses = Course.objects.filter(school_id=school_id).values('id', 'name')
        course_list = list(courses)
        return JsonResponse(course_list, safe=False)
    else:
        return JsonResponse({"error": "Not authorized"}, status=403)

@login_required
def inbox(request):
    received_messages = Message.objects.filter(recipient=request.user)
    sent_messages = Message.objects.filter(sender=request.user)
    users = BaseUser.objects.exclude(id=request.user.id)
    return render(request, 'academia_app/inbox.html', {'received_messages': received_messages, 'sent_messages': sent_messages, 'users': users})

@login_required
def send_message(request, recipient_id):
    if request.method == 'POST':
        recipient = BaseUser.objects.get(id=recipient_id)
        content = request.POST.get('content', '')
        message = Message.objects.create(sender=request.user, recipient=recipient, content=content)
        return render(request, 'academia_app/send_message.html', {'message_sent': True, 'recipient_id': recipient_id})

    # Added the following for debugging
    print("Recipient ID:", recipient_id)

    return render(request, 'academia_app/send_message.html', {'recipient_id': recipient_id})

@login_required
def inbox(request):
    received_messages = Message.objects.filter(recipient=request.user)
    sent_messages = Message.objects.filter(sender=request.user)
    users = BaseUser.objects.exclude(id=request.user.id)
    return render(request, 'academia_app/inbox.html', {'received_messages': received_messages, 'sent_messages': sent_messages, 'users': users})

@login_required
def send_message(request, recipient_id):
    if request.method == 'POST':
        recipient = BaseUser.objects.get(id=recipient_id)
        content = request.POST.get('content', '')
        message = Message.objects.create(sender=request.user, recipient=recipient, content=content)
        return render(request, 'academia_app/send_message.html', {'message_sent': True, 'recipient_id': recipient_id})

    # Added the following for debugging
    print("Recipient ID:", recipient_id)

    return render(request, 'academia_app/send_message.html', {'recipient_id': recipient_id})
@login_required
def Profile(request):
    return render(request, 'academia_app/Profile.html', {'user': request.user})