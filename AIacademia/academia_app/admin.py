from django.contrib import admin

from .models import (Attendance, Course, CourseOfInterest, FeeInformation,
                     FieldOfInterest, HighSchoolSubject, Performance, School,
                     Student)


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

admin.site.register(School)
admin.site.register(Course)
admin.site.register(Student, StudentAdmin)
admin.site.register(FeeInformation)
admin.site.register(Attendance)
admin.site.register(Performance)
admin.site.register(FieldOfInterest)
admin.site.register(HighSchoolSubject)
admin.site.register(CourseOfInterest)
