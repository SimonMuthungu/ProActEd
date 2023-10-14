from django.urls import path
from .views import admin_login_view

from . import views

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:department_id>/', views.get_courses, name='get_courses'),
    path('admin-login/', views.admin_login_view, name='admin_login'),

]


    
   
