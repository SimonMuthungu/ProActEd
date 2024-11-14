from django.core.management.base import BaseCommand
from django.contrib.auth.models import Group
from django.db import transaction
from academia_app.models import StudentUser, BaseUserGroup

class Command(BaseCommand):
    help = "Assign all student users to the 'Student Users' group and ensure their permissions."

    def handle(self, *args, **options):
        # Start a database transaction for safety
        @transaction.atomic
        def assign_students_to_student_group():
            # Get or create the "Student Users" group
            student_group, created = Group.objects.get_or_create(name="Student Users")
            if created:
                self.stdout.write(self.style.SUCCESS("Created 'Student Users' group."))

            # Query all StudentUser instances
            student_users = StudentUser.objects.all()
            for student in student_users:
                # Ensure is_staff and is_superuser are False for StudentUser
                student.is_staff = False
                student.is_superuser = False
                student.save()

                # Create an entry in BaseUserGroup if not exists
                BaseUserGroup.objects.get_or_create(
                    base_user=student,
                    group=student_group
                )
                self.stdout.write(self.style.SUCCESS(f"Assigned {student.username} to 'Student Users' group."))

            self.stdout.write(self.style.SUCCESS("All student users have been assigned to the 'Student Users' group."))

        # Execute the function
        assign_students_to_student_group()
