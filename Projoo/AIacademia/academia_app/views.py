from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def login(request):
    return render(request, "academia_app/login.html")
def student_page(request):
    return render(request, "academia_app/student_page.html")
def admin_page(request):
    return render(request, "academia_app/admin_page.html")




