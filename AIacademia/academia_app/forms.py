from django import forms
from .models import StudentUser, UserProfile

class UpdateStudentProfileForm(forms.ModelForm):
    email = forms.EmailField()
    phone_number = forms.CharField(max_length=15)

    class Meta:
        model = StudentUser
        fields = ['registration_number', 'course', 'school', 'profile_picture']

    def __init__(self, *args, **kwargs):
        super(UpdateStudentProfileForm, self).__init__(*args, **kwargs)
        self.fields['email'].initial = self.instance.email
        try:
            self.fields['phone_number'].initial = self.instance.userprofile.phone_number
        except UserProfile.DoesNotExist:
            pass

    def save(self, commit=True):
        student = super(UpdateStudentProfileForm, self).save(commit=False)
        student.email = self.cleaned_data['email']
        student.save()

        try:
            user_profile = student.userprofile
        except UserProfile.DoesNotExist:
            user_profile = UserProfile(user=student)
        
        user_profile.phone_number = self.cleaned_data['phone_number']
        user_profile.save()

        if commit:
            student.save()

        return student
