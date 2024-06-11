#app\urls.py
from django.contrib.auth.views import LogoutView
from django.urls import include, path

from . import admin, views
from .views import inbox, send_message, admin_dashboard

urlpatterns = [
    path('', views.course_recommendation, name='course_recommendation'),
    path('admin/', admin_dashboard, name='admin_dashboard'),
    path('login/', views.login_view, name='login'),
    path('logout/', LogoutView.as_view(next_page='course_recommendation'), name='logout'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path("profile/", views.profile, name='profile'),
    path("student_page/", views.student_page, name="student_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
    path('course_recommendation/', views.course_recommendation, name='course_recommendation'),
    
    path('student_page/inbox/', views.inbox, name='inbox'),
    path('check_new_messages/', views.check_new_messages, name='check_new_messages'),
    path('student_page/chat/<int:user_id>/', views.chat, name='chat'),
    path('student_page/send_message/<int:user_id>/', views.send_message, name='send_message'),
    

    path("admin_page", views.admin_page, name="admin_page"),
    path("recommend_courses/", views.recommend_courses, name="recommend_courses"),
    path('logout/', LogoutView.as_view(next_page='course_recommendation'), name='logout'),
    path('course_recommendation/', views.course_recommendation, name='course_recommendation'), 
    path('predict/', views.predict_probability, name='predict_probability'),
    path('predict/', views.predict, name='predict'),
    path('predict_probability/', views.predict_probability, name='predict_probability'), #the default
    path('predict_probability/<int:student_id>/', views.predict_probability, name='predict_probability'), # passes a value to the model
    path('realtimestudentprob/', views.realtimestudentprob, name='realtimestudentprob'), 
    path('realtimestudentprob/', views.realtimestudentprob, name='realtimestudentprob'), 

    ]

