from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from academia_app.models import BaseUser, BaseUserGroup

class Command(BaseCommand):
    help = "Assigns users to specific groups based on is_staff and is_superuser fields."

    def handle(self, *args, **options):
        # Get or create the required groups
        super_admin_group, _ = Group.objects.get_or_create(name="SuperAdminUser")
        staff_user_group, _ = Group.objects.get_or_create(name="Staff Users")

        # Process users who are only staff (is_staff=True, is_superuser=False)
        staff_only_users = BaseUser.objects.filter(is_staff=True, is_superuser=False)
        for user in staff_only_users:
            # Remove the user from any admin-related groups except 'Staff User'
            BaseUserGroup.objects.filter(base_user=user).exclude(group=staff_user_group).delete()
            
            # Ensure the user is assigned to the 'Staff User' group
            BaseUserGroup.objects.get_or_create(base_user=user, group=staff_user_group)
            self.stdout.write(self.style.SUCCESS(f"Assigned {user.username} to 'Staff User' group."))

        # Process users who are super admin (is_staff=True, is_superuser=True)
        super_admin_users = BaseUser.objects.filter(is_staff=True, is_superuser=True)
        for user in super_admin_users:
            # Ensure the user is in the 'SuperAdminUser' group without clearing other group memberships
            BaseUserGroup.objects.get_or_create(base_user=user, group=super_admin_group)
            self.stdout.write(self.style.SUCCESS(f"Ensured {user.username} is in 'SuperAdminUser' group."))

        self.stdout.write(self.style.SUCCESS("Completed assigning groups based on user roles."))
