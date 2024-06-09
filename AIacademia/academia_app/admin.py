from django import forms
from django.contrib import admin
from django.contrib.auth import get_user_model
from django.contrib.auth.admin import UserAdmin as BaseUserAdmin
from django.contrib.auth.models import Group
from django.contrib import admin
from .models import UserProfile
from .models import (AdminUserProxy, Attendance, Course, CourseOfInterest,
                     FeeInformation, FieldOfInterest, HighSchoolSubject,
                     Performance, School, Student, StudentUserProxy,
                     SuperAdminUserProxy)

# Custom form for creating new users
class UserCreationForm(forms.ModelForm):
    class Meta:
        model = get_user_model()
        fields = ('username', 'email')

    def save(self, commit=True):
        user = super().save(commit=False)
        user.set_password('changeme')
        if commit:
            user.save()
        return user

# Custom UserAdmin for Proxy Models
class CustomUserAdmin(BaseUserAdmin):
    add_form = UserCreationForm
    fieldsets = (
        (None, {'fields': ('username', 'email', 'password')}),
        ('Personal info', {'fields': ('first_name', 'last_name')}),
    )
    add_fieldsets = (
        (None, {'fields': ('first_name', 'last_name', 'username', 'email')}),
    )
    filter_horizontal = []

    def save_model(self, request, obj, form, change):
        super().save_model(request, obj, form, change)
        if not change:  # If creating a new user
            obj.set_password('changeme')  # Set default password
            self.assign_user_to_group(obj)  # Assign user to group based on type

    def assign_user_to_group(self, user):
        # Check the type of user and assign to group
        group_name = ''
        if isinstance(user, AdminUserProxy):
            group_name = 'Staff Users'
        elif isinstance(user, StudentUserProxy):
            group_name = 'Student Users'
        elif isinstance(user, SuperAdminUserProxy):
            group_name = 'Super Admins'
        
        if group_name:
            group, _ = Group.objects.get_or_create(name=group_name)
            user.groups.add(group)
            user.is_staff = 'Staff Users' in group_name or 'Super Admins' in group_name  # Grant admin access if staff or super admin
            user.save()
        
        
        
# Custom Admin for SuperAdminUser
class SuperAdminUserAdmin(CustomUserAdmin):
    model = SuperAdminUserProxy
    list_display = ('username', 'email')
    list_filter = ()

# Custom Admin for AdminUser (Staff)
class AdminUserAdmin(CustomUserAdmin):
    model = AdminUserProxy
    list_display = ('username', 'email')
    list_filter = ()

# Custom Admin for StudentUser
class StudentUserAdmin(CustomUserAdmin):
    model = StudentUserProxy
    list_display = ('first_name', 'last_name','username', 'email')
    list_filter = ()

# Custom Admin classes for other models
class SchoolAdmin(admin.ModelAdmin):
    list_display = ('name', 'abbreviation')
    search_fields = ('name',)

class CourseAdmin(admin.ModelAdmin):
    list_display = ('name', 'prefix', 'school', 'students_count')
    list_filter = ('school',)
    search_fields = ('name', 'prefix')

class StudentAdmin(admin.ModelAdmin):
    list_display = ('name', 'registration_number', 'course', 'school')
    list_filter = ('course', 'school')
    search_fields = ('name', 'registration_number')

class FeeInformationAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'required_fees', 'fees_paid')
    list_filter = ('semester',)
    search_fields = ('student__name',)

class AttendanceAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'total_classes', 'attended_classes')
    list_filter = ('semester',)
    search_fields = ('student__name',)

class PerformanceAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'aggregate_points', 'agp')
    list_filter = ('semester',)
    search_fields = ('student__name',)

# Custom GroupAdmin
class CustomGroupAdmin(admin.ModelAdmin):
    def get_queryset(self, request):
        return super().get_queryset(request) if request.user.is_superuser else Group.objects.none()

# Register your custom user and group admins
User = get_user_model()
if User in admin.site._registry:
    admin.site.unregister(User)
admin.site.register(User, CustomUserAdmin)

if Group in admin.site._registry:
    admin.site.unregister(Group)
admin.site.register(Group, CustomGroupAdmin)


# Registering the custom admin classes
admin.site.register(SuperAdminUserProxy, SuperAdminUserAdmin)
admin.site.register(AdminUserProxy, AdminUserAdmin)
admin.site.register(StudentUserProxy, StudentUserAdmin)

# Register other models
admin.site.register(School, SchoolAdmin)
admin.site.register(Course, CourseAdmin)
admin.site.register(Student, StudentAdmin)
admin.site.register(FeeInformation, FeeInformationAdmin)
admin.site.register(Attendance, AttendanceAdmin)
admin.site.register(Performance, PerformanceAdmin)
admin.site.register(FieldOfInterest)
admin.site.register(HighSchoolSubject)
admin.site.register(CourseOfInterest)
admin.site.register(UserProfile)