from django.urls import path
from django.contrib.auth.views import LogoutView
from . import views
#For auth realated paths
urlpatterns = [
    path('login/', views.login_view, name='login'),
    path('logout/', LogoutView.as_view(next_page='course_recommendation'), name='logout'),
]
