from django.urls import path

from . import views

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page")
]

