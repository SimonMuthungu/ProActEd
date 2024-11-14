from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from academia_app.models import BaseUser, BaseUserGroup

class Command(BaseCommand):
    help = "Assigns users without any groups to the 'Student Users' group."

    def handle(self, *args, **options):
        # Get or create the Student Users group
        student_group, created = Group.objects.get_or_create(name="Student Users")
        
        # Query for all BaseUsers who have no group assignments
        users_without_groups = BaseUser.objects.filter(groups=None)

        # Assign each of these users to the Student Users group
        for user in users_without_groups:
            # Add the user to the Student Users group
            BaseUserGroup.objects.get_or_create(base_user=user, group=student_group)
            self.stdout.write(self.style.SUCCESS(f"Assigned {user.username} to 'Student Users' group."))
        
        if users_without_groups:
            self.stdout.write(self.style.SUCCESS("Successfully assigned users without groups to 'Student Users' group."))
        else:
            self.stdout.write("No users found without groups.")
