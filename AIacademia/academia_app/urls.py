from django.urls import path

from . import views
<<<<<<< HEAD
from .views import admin_login_view

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
]



    
   
=======

urlpatterns = [

    path('', views.course_recommendation, name='course_recommendation'),
    path('login/', views.login_view, name='login'),
    # Dashboard view
    path('dashboard/', views.dashboard, name='dashboard'),
    # Other views
    path("student_page/", views.student_page, name="student_page"),
    path("admin_page/", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
]
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
