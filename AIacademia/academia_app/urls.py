# from django.urls import include, path

# from . import views
# from .admin import admin

# urlpatterns = [

#     path('', views.course_recommendation, name='course_recommendation'),
#     path('login/', views.login_view, name='login'),
#     path('dashboard/', views.dashboard, name='dashboard'),
#    path("student_page/", views.student_page, name="student_page"),
#     path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
# ]
from django.urls import path
from .views import admin_login_view

from . import views

urlpatterns = [
    path("", views.course_recommendation, name="course_recommendation"),
    path("login/", views.login_view, name="login")
    path("student_page/", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path('api/get_courses/<int:department_id>/', views.get_courses, name='get_courses'),
    # path('admin-login/', views.admin_login_view, name='admin_login'),
    path("course_recommendation_page", views.course_recommendation_page, name="course_recommendation_page"),
    path ("intervention/", views.intervention, name="intervention"),
    path ("signup", views.signup, name="signup"),
    path ("intervention_page/", views.intervention_page, name="intervention_page"),
    # path ("signin", views.signin, name="signin"),
    # path ("signout", views.signout, name="signout"),
]


    
   
