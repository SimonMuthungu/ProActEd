# management/commands/populate_roles.py
from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from academia_app.models import BaseUser

class Command(BaseCommand):
    help = 'Populates the role field for existing users based on their group'

    def handle(self, *args, **kwargs):
        role_map = {
            'SuperAdminUser': 'Super Administrator',
            'StaffUser': 'Administrator',
            'StudentUser': 'Student User',
        }

        for user in BaseUser.objects.all():
            for group_name, role in role_map.items():
                if user.groups.filter(name=group_name).exists():
                    user.role = role
                    user.save()
                    break

        self.stdout.write(self.style.SUCCESS('Roles populated successfully'))
