from django.urls import path

from . import views

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
