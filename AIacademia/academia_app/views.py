#vies.py
import logging
import os
import sys
from sre_constants import BRANCH
from telnetlib import LOGOUT

import joblib
import numpy as np
import tensorflow as tf
from django import forms
from django.contrib import messages
from django.contrib.auth import authenticate, get_user_model, login, logout
from django.contrib.auth.decorators import login_required
from django.contrib.auth.models import User
from django.contrib.auth.views import LoginView
from django.core.mail import send_mail
from django.db.models import Q
from django.http import (Http404, HttpRequest, HttpResponse,
                         HttpResponseRedirect, JsonResponse)
from django.shortcuts import get_object_or_404, redirect, render
from python_scripts.recommender_engine import load_model
from django.urls import reverse_lazy
# from python_scripts.proacted_recommender2024 import proacted2024
# from python_scripts.sbert_recommender import sbert_proactedrecomm2024
from .models import StudentUser, Attendance, Performance, Course, School, Recommender_training_data 
from .models import BaseUser,UserProfile,Course,School,Performance,Message, ProbabilityDataTable, NewMessageNotification

from .forms import UpdateStudentProfileForm
from .models import (Attendance, BaseUser, Course, Message, Performance,
                     Recommender_training_data, School, StudentUser,
                     UserProfile, ProbabilityDataTable)

logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')
# logging.basicConfig(filename=r'C:\Users\user\proacted\AIacademia\mainlogfile.log', level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')

# C:\Users\user\proacted\AIacademia\mainlogfile.log

def login_view(request):
    print("Visited Login")
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        user = authenticate(request, username=username, password=password)

        if user is not None:
            if user.is_active:
                login(request, user)
                if user.is_superuser or user.is_staff:
                    return redirect('/admin/')
                else:
                    return redirect('student_page')
            else:
                return render(request, 'auth/login.html', {'error': 'Account is inactive.'})
        else:
            return render(request, 'auth/login.html', {'error': 'Invalid username or password.'})

    return render(request, 'auth/login.html')



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

@login_required
def admin_dashboard(request):
    user_group = None
    if request.user.groups.filter(name='SuperAdminUser').exists():
        user_group = 'SuperAdminUser'
    elif request.user.groups.filter(name='StaffUser').exists():
        user_group = 'StaffUser'
    elif request.user.groups.filter(name='StudentUser').exists():
        user_group = 'StudentUser'
    else:
        user_group = 'Unauthorized'
    context = {
        'user_group': user_group,
    }

    return render(request, 'admin/base.html', context)

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
            from python_scripts.proacted_recommender2024 import proacted2024
            from python_scripts.sbert_recommender import sbert_proactedrecomm2024 # importing form here to avoid running anytime the view file is touched.
            # Load the model and get the output
            print("\nBeginning to run the recommender script")
            logging.info("Proacted recommender initialized...")
            proacted_recommendations = proacted2024(user_description_about_interests, user_activities_enjoyed)
            print(f"\n\nhere are the proacted_recommendations:\n\n{proacted_recommendations}\n\n")
            print(f"Done with proacted, proceeding to sbert recommender")
            sbert_recommendations = sbert_proactedrecomm2024(user_description_about_interests, user_activities_enjoyed)
            print(f"\n\nhere are the sbert_recommendations:\n\n{sbert_recommendations}\n\n") 
            context = {'proacted_recommendations': proacted_recommendations}
            return render(request, 'academia_app/recommended_courses.html', context)
        except Exception as exc:
            print(f'Something came up, please rerun the system...\n{exc}\n\n')
            logging.critical('Something came up, please rerun the system...')
        # Pass proacted_recommendations to the template
        finally:
            logging.info('Recommender system has run')
    else:
        return render(request, 'academia_app/recommended_courses.html')       

            
        
        
def predict_probability(request, student_id=3): 
    try: 
        # model_path = r'C:\Users\user\ProActEd\AIacademia\trained_models\proacted_model_2.2_with5morefeatures.joblib'
        model_path = r'C:\Users\Simon\proacted\AIacademia\trained_models\proacted_model_2.2_with5morefeatures.joblib'
        # model_path = r'C:\Users\Simon\proacted\AIacademia\trained_models\proacted_prob_model2.joblib'
        model = joblib.load(model_path)
        logging.info('Probability model proacted_prob_model2 loaded') 

        student_data = ProbabilityDataTable.objects.get(id=student_id) 
        lessonsattended = student_data.Lessons_Attended
        aggrpoints = student_data.Aggregate_points
        pcnt_of_lessons_attended = student_data.pcnt_of_lessons_attended 
        homework_submission_rates = student_data.homework_submission_rates
        activity_on_learning_platforms = student_data.activity_on_learning_platforms
        CAT_1_marks = student_data.CAT_1_marks
        CAT_2_marks = student_data.CAT_2_marks
        activity_on_elearning_platforms = student_data.activity_on_elearning_platforms

    except ProbabilityDataTable.DoesNotExist:
        # the student doesnt exist
        print('the student doesnt exist')
        return render(request, "academia_app/student_page.html")

    input_data = [[lessonsattended, aggrpoints, pcnt_of_lessons_attended, homework_submission_rates, CAT_1_marks, CAT_2_marks, activity_on_elearning_platforms]] 
    # input_data = [[lessonsattended, aggrpoints]] 

    # Predict probabilities
    prediction = model.predict(input_data)

    context = {'prediction': prediction[0][0], 'refined_prediction': f"{prediction[0][0]*100:.3f}"}
    print(f"\n\nStudent {student_id} with lessonsattended: {lessonsattended} and aggrpoints: {aggrpoints}, lessons_attended: {pcnt_of_lessons_attended}, homework_submission_rates: {homework_submission_rates}, activity_on_learning_platforms: {activity_on_learning_platforms}, CAT_1_marks: {CAT_1_marks}, CAT_2_marks: {CAT_2_marks}, activity_on_elearning_platforms: {activity_on_elearning_platforms} ; 'prediction': {prediction[0][0]}, 'refined_prediction': {prediction[0][0]*100:.3f}\n\n")

    return render(request, "academia_app/student_page.html",context = context)


from django.http import HttpResponse
from .models import StudentUser
import joblib


def realtimestudentprob(request):
    """This function will run every student's probability metrics and update the student table and other relevant tables, then the admin page will be caused to read the db again, ultimately reflecting on the admin interface as fresh and new manna. """

    try:
        # Getting the list of student IDs from the query parameters
        student_ids = request.GET.getlist('baseuser_ptr_id')

        for baseuser_ptr_id in student_ids:
            # Get their student data
            student_data = StudentUser.objects.get(id=baseuser_ptr_id) 

            lessonsattended = student_data.Lessons_Attended
            aggrpoints = student_data.Aggregate_points
            pcnt_of_lessons_attended = student_data.pcnt_of_lessons_attended 
            homework_submission_rates = student_data.homework_submission_rates
            activity_on_learning_platforms = student_data.activity_on_learning_platforms
            CAT_1_marks = student_data.CAT_1_marks
            CAT_2_marks = student_data.CAT_2_marks
            activity_on_elearning_platforms = student_data.activity_on_elearning_platforms

            # Load the machine learning model
            model_path = r'C:\Users\Simon\proacted\AIacademia\trained_models\proacted_model_2.2_with5morefeatures.joblib'
            model = joblib.load(model_path)

            # Prepare input data for prediction
            input_data = [[lessonsattended, aggrpoints, pcnt_of_lessons_attended, homework_submission_rates, CAT_1_marks, CAT_2_marks, activity_on_elearning_platforms]] 

            # Predict student real-time probabilities
            prediction = model.predict(input_data)

            # Write the probability to the table
            student_data.graduation_probability = prediction[0][0] * 100
            student_data.save()


        return HttpResponse("Success")
    except StudentUser.DoesNotExist:
        return HttpResponse("Student not found")
    except Exception as e:
        print(f"Error: {e}")
        return HttpResponse("An error occurred")



@login_required
def dashboard(request):
    print("Visited Dashboard")
    
    # Redirect users based on their type
    if request.user.is_superuser or request.user.is_staff:
        total_students = StudentUser.objects.count()
        total_staff = AdminUser.objects.count()
        total_admins = SuperAdminUser.objects.count()
        total_schools = School.objects.count()
        total_courses = Course.objects.count()

        context = {
            'total_students': total_students,
            'total_staff': total_staff,
            'total_admins': total_admins,
            'total_schools': total_schools,
            'total_courses': total_courses,
        }

        return render(request, 'admin/profile.html', context)
    else:
        return redirect('student_page')  # Students to student page

@login_required
def student_page(request):
    print("Visited Student Page")
    print(f"User: {request.user}, Groups: {request.user.groups.all()}")
    if request.user.groups.filter(name='Student Users').exists():
        return render(request, "academia_app/student_page.html", context={'text': 'Hello world'})
    else:
        if request.user.is_superuser or request.user.is_staff:
            return redirect('/admin/')
        return redirect('login')

def course_recommendation(request):
    print("visited course recommendation page")
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

# this below is for the messages

BaseUser = get_user_model()

@login_required
def inbox(request):
    users = BaseUser.objects.exclude(id=request.user.id)
    notifications = NewMessageNotification.objects.filter(user=request.user, is_new=True)

    # Mark all notifications as read
    notifications.update(is_new=False)

    for user in users:
        user.has_new_messages = NewMessageNotification.objects.filter(user=user, is_new=True).exists()

    return render(request, 'academia_app/inbox.html', {'users': users, 'notifications': notifications})

def check_new_messages(request):
    has_new_messages = NewMessageNotification.objects.filter(user=request.user, is_new=True).exists()
    return JsonResponse({'has_new_messages': has_new_messages})

@login_required
def chat(request, user_id):
    other_user = get_object_or_404(BaseUser, id=user_id)
    messages = Message.objects.filter(
        (Q(sender=request.user) & Q(recipient=other_user)) |
        (Q(sender=other_user) & Q(recipient=request.user))
    ).order_by('timestamp')
    return render(request, 'academia_app/chat.html', {'messages': messages, 'other_user': other_user})

@login_required
def send_message(request, user_id):
    if request.method == 'POST':
        recipient = get_object_or_404(BaseUser, id=user_id)
        content = request.POST.get('content', '')
        message = Message.objects.create(sender=request.user, recipient=recipient, content=content)
        data = {
            'content': message.content,
            'timestamp': message.timestamp.strftime('%Y-%m-%d %H:%M:%S')
        }
        return JsonResponse(data)
    else:
        return redirect('inbox')

@login_required
def profile(request):
    student_user = get_object_or_404(StudentUser, username=request.user.username)

    attendance_records = Attendance.objects.filter(student=student_user)
    performance_records = Performance.objects.filter(student=student_user)

    if request.method == 'POST':
        form = UpdateStudentProfileForm(request.POST, request.FILES, instance=student_user)
        if form.is_valid():
            form.save()
            messages.success(request, 'Your profile was updated successfully.')
            return redirect('profile')
        else:
            messages.error(request, 'Please correct the error below.')
    else:
        form = UpdateStudentProfileForm(instance=student_user)

    context = {
        'student': student_user,
        'attendance_records': attendance_records,
        'performance_records': performance_records,
        'form': form,
    }

    return render(request, 'academia_app/Profile.html', context)