from django.contrib.auth.views import LogoutView
from django.urls import include, path

from . import admin, views

urlpatterns = [
    # path('admin/', admin.site.urls),
    path('', views.course_recommendation, name='course_recommendation'),
    path('login/', views.login_view, name='login'),
    path('dashboard/', views.dashboard, name='dashboard'),
    path("student_page/", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path("recommend_courses", views.recommend_courses, name="recommend_courses"),
]
