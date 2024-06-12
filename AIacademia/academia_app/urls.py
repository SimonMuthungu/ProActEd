from django.contrib.auth.views import LogoutView
from django.urls import include, path
from django.contrib.auth import views as auth_views

from . import admin, views

urlpatterns = [
    path('', views.course_recommendation, name='course_recommendation'),
    path('admin_dashboard/', views.admin_dashboard, name='admin_dashboard'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path('api/school_data/<int:school_id>/', views.school_data, name='school_data'),
    path('profile/', views.profile, name='profile'),
    path('student_page/', views.student_page, name='student_page'),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
    path('api/course_data/<int:course_id>/', views.course_data, name='course_data'),
    path('course_recommendation/', views.course_recommendation, name='course_recommendation'),
    path('student_page/inbox/', views.inbox, name='inbox'),
    path('check_new_messages/', views.check_new_messages, name='check_new_messages'),
    path('student_page/chat/<int:user_id>/', views.chat, name='chat'),
    path('student_page/send_message/<int:user_id>/', views.send_message, name='send_message'),
    path('get_new_messages/<int:user_id>/', views.get_new_messages, name='get_new_messages'),
    path('admin_page/', views.admin_page, name='admin_page'),
    path('recommend_courses/', views.recommend_courses, name='recommend_courses'),
    path('predict/', views.predict, name='predict'),
    path('predict_probability/', views.predict_probability, name='predict_probability'),
    path('predict_probability/<int:student_id>/', views.predict_probability, name='predict_probability'),
    path('realtimestudentprob/', views.realtimestudentprob, name='realtimestudentprob'),
]
