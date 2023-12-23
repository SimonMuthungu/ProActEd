from django.contrib.auth import authenticate, login
from django.contrib.auth.decorators import login_required
from django.http import HttpResponse, JsonResponse
from django.shortcuts import redirect, render

from .models import Course, School  # Import Course and School models


def login_view(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        user = authenticate(request, username=username, password=password)
        
        if user is not None:
            login(request, user)
            # Redirect based on user type
            if user.is_superuser:
                return redirect('/admin/')  # Superadmin to Django admin
            elif user.is_staff:
                return redirect('admin_page')  # Admin to custom admin page
            else:
                return redirect('student_page')  # Students to student page
        else:
            # Handle invalid login
            return render(request, 'login.html', {'error': 'Invalid credentials.'})

    return render(request, 'login.html')


@login_required
def dashboard(request):
    # Redirect users based on their type
    if request.user.is_superuser:
        # Superadmin users
        return redirect('/admin/')
    elif request.user.is_staff:
        # Admin users
        return render(request, "academia_app/admin_page.html")
    else:
        # Student users
        return render(request, "academia_app/student_page.html")


def student_page(request):
    # Ensure only logged in students can access this page
    if request.user.is_authenticated and not request.user.is_staff:
        return render(request, "academia_app/student_page.html")
    else:
        return redirect('login')


def course_recommendation(request):
    return render(request, 'academia_app/course_recommendation_page.html')

def admin_page(request):
    # Ensure only logged in admins can access this page
    if request.user.is_authenticated and request.user.is_staff:
        return render(request, "academia_app/admin_page.html")
    else:
        return redirect('login')


def admin_login_view(request):
    # Your view logic for admin login goes here
    return render(request, "academia_app/admin_login.html")  # Updated to point to the correct template


def school_list(request):
    # Ensure only logged in admins can access this page
    if request.user.is_authenticated and request.user.is_staff:
        schools = School.objects.all()
        courses = Course.objects.all()
        return render(request, 'academia_app/school_list.html', {'schools': schools, 'courses': courses})
    else:
        return redirect('login')


def get_courses(request, school_id):
    # Ensure only logged in users can access this page
    if request.user.is_authenticated:
        courses = Course.objects.filter(school_id=school_id).values('id', 'name')
        course_list = list(courses)
        return JsonResponse(course_list, safe=False)
    else:
        return JsonResponse({"error": "Not authorized"}, status=403)
