from django import forms
from .models import Student, UserProfile

class UpdateStudentProfileForm(forms.ModelForm):
    email = forms.EmailField()
    phone_number = forms.CharField(max_length=15)

    class Meta:
        model = Student
        fields = ['registration_number', 'course', 'school', 'profile_picture']

    # def __init__(self, *args, **kwargs):
    #     super(UpdateStudentProfileForm, self).__init__(*args, **kwargs)
    #     self.fields['email'].initial = self.instance.user.email
    #     self.fields['phone_number'].initial = self.instance.user.userprofile.phone_number

    def save(self, commit=True):
        student = super(UpdateStudentProfileForm, self).save(commit=False)
        user = student.user
        user.email = self.cleaned_data['email']
        user.save()
        # user.userprofile.phone_number = self.cleaned_data['phone_number']
        user.userprofile.save()
        if commit:
            student.save()
        return student
