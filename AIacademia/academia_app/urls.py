from django.urls import path

from . import views

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
     path('api/get_courses/<int:department_id>/', views.get_courses, name='get_courses')
]


    
   
