from django.urls import path

from . import views

urlpatterns = [
    path("", views.login, name="login"),
    path("student_page", views.student_page, name="student_page"),
    path("admin_page", views.admin_page, name="admin_page"),
    path("predict", views.predict_view, name="manually_predict_view"),
    path("predict_data/", views.predict_data, name="predict_data")
]

