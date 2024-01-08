from django.contrib import admin

from .models import (AdminUser, Attendance, BaseUser, Course, CourseOfInterest,
                     FeeInformation, FieldOfInterest, HighSchoolSubject,
                     Performance, School, Student, SuperAdminUser)


class StudentAdmin(admin.ModelAdmin):
    list_display = ('name', 'registration_number', 'course','school', 'graduation_probability')
    list_filter = ('course', 'school')
    search_fields = ('name', 'registration_number')
    fieldsets = (
        ('Student Information', {
            'fields': ('name', 'registration_number', 'graduation_probability')
        }),
        ('Academic Details', {
            'fields': ('course', 'school')
        }),
    )

class BaseUserAdmin(admin.ModelAdmin):
    list_display = ('username', 'email', 'first_name', 'last_name', 'is_active', 'is_staff')
    # other custom options
    pass

class AdminUserAdmin(admin.ModelAdmin):
    list_display = ('username', 'admin_field', 'is_active', 'is_staff')
    # other custom options
    pass

class SuperAdminUserAdmin(admin.ModelAdmin):
    list_display = ('username', 'superadmin_field', 'is_active', 'is_superuser')
    # other custom options
    pass
    
# Custom Admin for School
class SchoolAdmin(admin.ModelAdmin):
    list_display = ('name', 'abbreviation')
    search_fields = ('name',)

# Custom Admin for Course
class CourseAdmin(admin.ModelAdmin):
    list_display = ('name', 'prefix', 'school', 'students_count')
    list_filter = ('school',)
    search_fields = ('name', 'prefix')

# Custom Admin for FeeInformation
class FeeInformationAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'required_fees', 'fees_paid')
    list_filter = ('semester',)
    search_fields = ('student__name',)

# Custom Admin for Attendance
class AttendanceAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'total_classes', 'attended_classes')
    list_filter = ('semester',)
    search_fields = ('student__name',)

# Custom Admin for Performance
class PerformanceAdmin(admin.ModelAdmin):
    list_display = ('student', 'semester', 'aggregate_points', 'agp')
    list_filter = ('semester',)
    search_fields = ('student__name',)

# Register your models here
admin.site.register(BaseUser, BaseUserAdmin)
admin.site.register(AdminUser, AdminUserAdmin)
admin.site.register(SuperAdminUser, SuperAdminUserAdmin)
admin.site.register(School, SchoolAdmin)
admin.site.register(Course, CourseAdmin)
admin.site.register(Student, StudentAdmin)
admin.site.register(FeeInformation, FeeInformationAdmin)
admin.site.register(Attendance, AttendanceAdmin)
admin.site.register(Performance, PerformanceAdmin)
admin.site.register(FieldOfInterest)  # Add custom admin if needed
admin.site.register(HighSchoolSubject)  # Add custom admin if needed
admin.site.register(CourseOfInterest)  # Add custom admin if needed
