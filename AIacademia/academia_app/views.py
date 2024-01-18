from django import forms
from django.contrib.auth import authenticate, login
from django.contrib.auth.decorators import login_required
from django.http import HttpResponse, JsonResponse
from django.shortcuts import redirect, render
from django.shortcuts import render, redirect




from .forms import UserProfileForm
from .models import UserProfile
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.contrib.auth.decorators import login_required
from .forms import UserProfileForm
from .models import Course, School  # Import Course and School models
from django.core.mail import send_mail

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
            return render(request, 'academia_app/login.html', {'error': 'Invalid username or password.'})

    return render(request, 'academia_app/login.html')


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
        return render(request, "academia_app/student_page.html")
    else:
        if request.user.is_superuser or request.user.is_staff:
            return redirect('/admin/')
        return redirect('login')

def course_recommendation(request):
    return render(request, 'academia_app/course_recommendation_page.html')

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
def edit_profile(request):
    try:
        profile = request.user.userprofile
    except UserProfile.DoesNotExist:
        UserProfile.objects.create(user=request.user)
        profile = request.user.userprofile

    if request.method == 'POST':
        form = UserProfileForm(request.POST, instance=profile)
        if form.is_valid():
            form.save()
            
            
            return redirect('profile_view')  # Redirect to a profile view
    else:
        form = UserProfileForm(instance=profile)

        if form.is_valid():
            subject = form.cleaned_data["subject"]
    message = form.cleaned_data["message"]
    sender = form.cleaned_data["sender"]
    cc_myself = form.cleaned_data["cc_myself"]

    recipients = ["info@example.com"]
    if cc_myself:
        recipients.append(sender)

    send_mail(subject, message, sender, recipients)
    return HttpResponseRedirect("/thanks/")

    return render(request, 'Student_Page.html', {'form': form})

def index(request):
    form = forms()
    rendered_form = form.render("Student_Page.html")
    context = {"form": rendered_form}
    return render(request, "index.html", context)
def student (request):
    return render (request, 'Student_Page.html', context ={ 'text': 'Hello world'})

def forms ( request):
    return render (request, 'forms.html',{})