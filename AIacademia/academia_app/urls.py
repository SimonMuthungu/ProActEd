from django.urls import path

from . import views
from .views import admin_login_view

urlpatterns = [
    path("", views.login_a, name="login_a"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:department_id>/', views.get_courses, name='get_courses'),
    path('admin-login/', views.admin_login_view, name='admin_login'),
    path("course_recommendation_page", views.course_recommendation_page, name="course_recommendation_page"),
    path ("intervention/", views.intervention, name="intervention"),
    path ("signup", views.signup, name="signup"),
    path ("intervention_page/", views.intervention_view, name="intervention_page"),
    path ("signin", views.signin, name="signin"),
    path ("signout", views.signout, name="signout"),
    ]



    
   

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
