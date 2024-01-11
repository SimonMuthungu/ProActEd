from django.contrib.auth.models import Group, Permission
from django.contrib.contenttypes.models import ContentType
from django.core.management.base import BaseCommand


class Command(BaseCommand):
    help = 'Setup default groups and permissions'

    def handle(self, *args, **kwargs):
        # Create Admin Group
        admin_group, created = Group.objects.get_or_create(name='Admin')
        admin_permissions = Permission.objects.all()  # Assuming Admin has all permissions
        admin_group.permissions.set(admin_permissions)

        # Create Staff Group with limited permissions
        staff_group, created = Group.objects.get_or_create(name='Staff')
        # Replace 'model1', 'model2' with the actual model names for which you want to grant permissions
        content_types = ContentType.objects.filter(model__in=['model1', 'model2'])
        staff_permissions = Permission.objects.filter(content_type__in=content_types)
        staff_group.permissions.set(staff_permissions)

        # Create Student Group with read-only permissions
        student_group, created = Group.objects.get_or_create(name='Student')
        # 'view_' permissions are typically read-only, adjust as needed for your models
        student_permissions = Permission.objects.filter(codename__startswith='view_')
        student_group.permissions.set(student_permissions)

        self.stdout.write(self.style.SUCCESS('Successfully set up default groups and permissions'))
