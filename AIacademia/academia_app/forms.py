from django import forms
from .models import UserProfile

class UserProfileForm(forms.Form):
    your_name = forms.CharField(label="Your name", max_length=100)
    subject = forms.CharField(max_length=100)
    message = forms.CharField(widget=forms.Textarea)
    sender = forms.EmailField()
    cc_myself = forms.BooleanField(required=False)