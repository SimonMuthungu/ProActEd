from django.contrib.auth.views import LogoutView
from django.urls import include, path

from . import views
from .admin import admin

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.course_recommendation, name='course_recommendation'),
    path('login/', views.login_view, name='login'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path("student_page/", views.student_page, name="student_page"),
    path('api/get_courses/<int:school_id>/', views.get_courses, name='get_courses'),
    path('logout/', LogoutView.as_view(next_page='course_recommendation'), name='logout'),
    path('course_recommendation/', views.course_recommendation, name='course_recommendation'),
]