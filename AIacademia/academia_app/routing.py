from django.urls import path
from .students import GraphStudent

ws_urlpatterns = [
    path('ws/academia_app/', GraphStudent.as_asgi())
]