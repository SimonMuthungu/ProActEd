from academia_app.models import Department
from django.http import (  # Import JsonResponse for AJAX responses
    HttpResponse, JsonResponse)
from django.shortcuts import render

# Other imports

def department_list(request):
    all_departments = Department.objects.all()
    return render(request, 'template_name.html', {'departments': all_departments})
def admin_login_view(request):
    return render (request ,"academia_app/ admin_login-view.html" )

def login(request):
    return render(request, "academia_app/login.html")

def student_page(request):
    return render(request, "academia_app/student_page.html")

def course_recommendation_page(request):
    return render (request,"academia_app/course_recommendation_page.html")


def admin_page(request):
    return render(request, "academia_app/admin_page.html")

from .models import Course, Department, School


def school_list(request):
    schools = School.objects.all()
    departments = Department.objects.all()
    return render(request, 'admin_page.html', {'schools': schools, 'departments': departments})

def get_courses(request, department_id):
    # Retrieve courses for the selected department
    courses = Course.objects.filter(department_id=department_id).values('id', 'name')
    
    # Convert courses to a list of dictionaries
    course_list = list(courses)

    # Return courses as JSON response
    return JsonResponse(course_list, safe=False)
