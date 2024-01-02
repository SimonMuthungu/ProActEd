import csv
import os

from academia_app.models import StudentUser  # Import your StudentUser model
from django.core.management.base import BaseCommand, CommandError


class Command(BaseCommand):
    help = 'Imports student users from a CSV file'

    def handle(self, *args, **kwargs):
        # Assuming the CSV file is in the academia_app directory
        csv_file_path = os.path.join(os.path.dirname(__file__), '../../student_users.csv')

        try:
            with open(csv_file_path, newline='', encoding='utf-8') as csvfile:
                reader = csv.reader(csvfile)
                next(reader)  # Skip the header row
                for row in reader:
                    registration_number = row[0].replace('/', '')  # Convert ccs/00046/022 to ccs00046022
                    password = 'changeme'
                    if not StudentUser.objects.filter(username=registration_number).exists():
                        StudentUser.objects.create_user(username=registration_number, password=password)
                        self.stdout.write(self.style.SUCCESS(f'Successfully added student user {registration_number}'))
                    else:
                        self.stdout.write(self.style.WARNING(f'User {registration_number} already exists'))
        except Exception as e:
            raise CommandError(f'Error reading file or adding users: {e}')
