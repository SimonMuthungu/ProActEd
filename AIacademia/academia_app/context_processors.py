from .models import AdminUser, SuperAdminUser, StudentUser, School, Course

def admin_dashboard_context(request):
    if request.user.is_authenticated and (request.user.is_superuser or request.user.is_staff):
        return {
            'total_students': StudentUser.objects.count(),
            'total_staff': AdminUser.objects.count(),
            'total_admins': SuperAdminUser.objects.count(),
            'total_schools': School.objects.count(),
            'total_courses': Course.objects.count(),
        }
    return {}
