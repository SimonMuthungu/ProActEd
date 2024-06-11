from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from academia_app.models import BaseUser, SuperAdminUser, StudentUser, AdminUser  # Adjust the import paths according to your project structure

class Command(BaseCommand):
    help = 'Ensures only the specified user groups exist and assigns users to the correct groups'

    def handle(self, *args, **kwargs):
        required_groups = ['SuperAdminUser', 'StaffUser', 'StudentUser']

        # Delete groups that are not in the required_groups list
        Group.objects.exclude(name__in=required_groups).delete()

        # Create required groups if they do not exist
        groups = {}
        for group in required_groups:
            groups[group], created = Group.objects.get_or_create(name=group)

        # Function to clear and reassign groups for a user
        def clear_and_reassign_groups(user, group_name):
            user.groups.clear()
            user.groups.add(groups[group_name])

        # Clear all groups for all users and reassign to the correct groups
        for user in SuperAdminUser.objects.all():
            clear_and_reassign_groups(user, 'SuperAdminUser')

        for user in StudentUser.objects.all():
            clear_and_reassign_groups(user, 'StudentUser')

        for user in AdminUser.objects.all():
            clear_and_reassign_groups(user, 'StaffUser')

        # Check BaseUser for any users not included in the specific groups
        for user in BaseUser.objects.all():
            if not user.groups.filter(name__in=required_groups).exists():
                clear_and_reassign_groups(user, 'StudentUser')  # Default to StudentUser if not in a specific group

        self.stdout.write(self.style.SUCCESS('Groups ensured and users assigned successfully'))
