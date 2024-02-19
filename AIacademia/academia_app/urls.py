from django.urls import include, path
from django.urls import path

from . import views
from .admin import admin

urlpatterns = [
     
    path('', views.course_recommendation, name='course_recommendation'),
    path('login/', views.login_view, name='login'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path("Profile/", views.Profile, name='addprofile'),
    path("student_page/", views.student_page, name="student_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
   
    
]
