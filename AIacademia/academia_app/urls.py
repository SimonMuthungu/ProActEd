from django.contrib.auth.views import LogoutView
from django.urls import include, path
from django.urls import path

from . import views
from . import admin

urlpatterns = [

    path('', views.course_recommendation, name='course_recommendation'),
    path('login/', views.login_view, name='login'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path("student_page/", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path("recommend_courses", views.recommend_courses, name="recommend_courses"),
    path('logout/', LogoutView.as_view(next_page='course_recommendation'), name='logout'),
    path('course_recommendation/', views.course_recommendation, name='course_recommendation'),
    # path('predict/', views.predict, name='predict'),
    # path('predict/probability/', views.predict_probability, name='predict_probability'),
    ]