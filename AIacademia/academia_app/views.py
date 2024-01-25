from django.contrib.auth import authenticate, login
from django.contrib.auth.decorators import login_required
from django.http import Http404 , JsonResponse
from django.shortcuts import redirect, render
from django.contrib import messages
from .models import BaseUser, Course, School, Message   # Import Course and School models


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
