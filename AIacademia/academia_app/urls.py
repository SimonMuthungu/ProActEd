from django.urls import path

from . import views
from .views import admin_login_view

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
]



    
   
