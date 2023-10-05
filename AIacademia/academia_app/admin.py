from django.contrib import admin

from .models import Course, Department, School, Student


class StudentAdmin(admin.ModelAdmin):
    list_display = ('name', 'registration_number', 'course', 'department', 'school', 'graduation_probability')
    list_filter = ('course', 'department', 'school')
    search_fields = ('name', 'registration_number')
    fieldsets = (
        ('Student Information', {
            'fields': ('name', 'registration_number', 'graduation_probability')
        }),
        ('Academic Details', {
            'fields': ('course', 'department', 'school')
        }),
    )

admin.site.register(School)
admin.site.register(Department)
admin.site.register(Course)
admin.site.register(Student, StudentAdmin)
