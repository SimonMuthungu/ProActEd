import csv
import re

from academia_app.models import Course, School
from django.core.management.base import BaseCommand


class Command(BaseCommand):
    help = 'Imports schools and courses from a CSV file'

    def add_arguments(self, parser):
        parser.add_argument('csv_file', type=str, help='data_files/Schools_and_Courses.csv')

    def handle(self, *args, **options):
        with open(options['csv_file'], newline='') as csvfile:
            reader = csv.reader(csvfile)
            for row in reader:
                match = re.match(r"(.*)\((.*)\)", row[0])
                if match:
                    school_name = match.group(1).strip()
                    school_abbr = match.group(2).strip()

                    school, created = School.objects.get_or_create(
                        name=school_name,
                        defaults={'abbreviation': school_abbr}
                    )

                    Course.objects.create(
                        name=row[2].strip(),
                        prefix=row[1].strip(),
                        school=school,
                        students_count=100
                    )
