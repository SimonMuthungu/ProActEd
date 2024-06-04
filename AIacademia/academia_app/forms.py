from django import forms
from .models import UserProfile
from django.forms import ModelForm

class UserProfileForm(forms.ModelForm):
    class Meta:
        model= UserProfile
        fields = ['user', 'bio', 'full_name', 'phone_number', 'parents_phone_number']
    #   your_name = forms.CharField(label="Your name", max_length=100)
    # subject = forms.CharField(max_length=100)
    # message = forms.CharField(widget=forms.Textarea)
    # sender = forms.EmailField()
    # cc_myself = forms.BooleanField(required=False)