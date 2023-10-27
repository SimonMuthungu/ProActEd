from django.http import HttpResponse, JsonResponse
from django.shortcuts import render

from .models import Course, School  # Import Course and School models


def login(request):
    return render(request, "academia_app/login.html")

def student_page(request):
    return render(request, "academia_app/student_page.html")

def course_recommendation_page(request):
    return render(request, "academia_app/course_recommendation_page.html")

def admin_page(request):
    return render(request, "academia_app/admin_page.html")

def admin_login_view(request):
    # Your view logic for admin login goes here
    return render(request, "admin_login.html")  # Replace "admin_login.html" with the actual template

def school_list(request):
    schools = School.objects.all()
    # Retrieve courses for all schools (you may need to adjust this based on your use case)
    courses = Course.objects.all()
    return render(request, 'academia_app/admin_page.html', {'schools': schools, 'courses': courses})

def get_courses(request, school_id):
    # Retrieve courses for the selected school
    courses = Course.objects.filter(school_id=school_id).values('id', 'name')
    
    # Convert courses to a list of dictionaries
    course_list = list(courses)

    # Return courses as a JSON response
    return JsonResponse(course_list, safe=False)
