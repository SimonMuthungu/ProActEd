from django.urls import include, path
from django.urls import path

from . import views
from . import admin

urlpatterns = [
    path("", views.course_recommendation, name="course_recommendation"),
    path("login/", views.login_view, name="login"),
    path("student_page/", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path("recommend_courses", views.recommend_courses, name="recommend_courses"),
]


    
   
