from sre_constants import BRANCH
from telnetlib import LOGOUT
from academia_app.models import Department
# from django.http import git BRANCH(  # Import JsonResponse for AJAX responses
#     HttpResponse, JsonResponse)
from django.shortcuts import render, redirect
# from .forms import UserLoginForm
from django.contrib.auth.views import LoginView
from django.contrib.auth import authenticate ,login
from django.urls import reverse_lazy
from django.contrib.auth import authenticate
# Other imports
from django.contrib.auth import authenticate ,login , logout
from django.contrib.auth import login
from django.http import HttpResponse, JsonResponse
from django.shortcuts import render
from django.http import HttpRequest
from .models import Course, School # Import Course and School models
from django.contrib.auth.models import User
from django.contrib import messages

# Other imports

def department_list(request):
    all_departments = Department.objects.all()
    return render(request, 'template_name.html', {'departments': all_departments})
def admin_login_view(request):
    return render (request ,"academia_app/ admin_login-view.html" )

def login_a(request):
    return render(request, "academia_app/login_a.html")

def student_page(request):
    return render(request, "academia_app/student_page.html")

def course_recommendation_page(request):
    return render (request,"academia_app/course_recommendation_page.html")
def intervention(request):
    return render (request,"academia_app/intervention.html")

def intervention (request):
    return render (request, "academia_app/intervention.html")

def intervention_page (request):
    return render (request, "academia_app/intervention_page.html")

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
# class CustomLoginView(LoginView):
#     template_name = 'login.html'
#     success_url = reverse_lazy('success_url_name')
    

# def intervention_view(request):
#     if request.method == 'POST':
#         form = UserLoginForm(request.POST)
#         if form.is_valid():
#             registration_number = form.cleaned_data['registration_number']
#             password = form.cleaned_data['password']
#             user = authenticate(request, username=registration_number, password=password)
#             if user is not None:
#                 login(request, user)
#                 # Redirect to a success page or another view after successful login
#                 return redirect('success_page')
#             else:
#                 # Handle invalid credentials (display error message, etc.)
#                 pass
#     else:
#         form = UserLoginForm()
#     return render(request, 'intervention.html', {'form': form})    

# def intervention (request):
#       return HttpResponse(request,"academia_app/intervention.html")
  
def signup (request):
    
    if  request.method == "POST":
            username = request.POST['username']
            fname = request.POST["fname"]
            lname = request.POST["lname"]
            email = request.POST["email"]
            pass1= request.POST["pass1"]
            pass2 = request.POST["pass2"]

            myuser = User.objects.create_user (username, email, pass1)
            myuser.first_name =fname
            myuser.last_name =lname
            myuser.save ()
        
            messages.success (request, "Your account has been successfully created.")
        
            return redirect("signin")
    
    return render (request, "academia_app/signup.html")
  

def signin(request):
    if request.method == "POST":
        username = request.POST['username']
        pass1= request.POST["pass1"]
        user = authenticate( username=username,password=pass1 )
        
        if   user is not None:
            login(request,user)
            fname = user.first_name
            return render(request, "academia_app/intervention.html", {"fname":fname})
        else:
            
            messages.error(request, "Bad Credentials")
            return redirect('intervention')
    return render(request, "academia_app/signin.html")

def signout(request):
    logout(request)
    messages.success(request, "Logged out successfully!")
    return redirect("intervention")