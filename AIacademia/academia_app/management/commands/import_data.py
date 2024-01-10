import json

from django.core.management.base import BaseCommand

from academia_app.models import Course, School


class Command(BaseCommand):
    help = 'Imports data from a JSON file into the database'

    def handle(self, *args, **kwargs):
        data_file = 'schools_and_courses_data.json'

        try:
            with open(data_file, 'r', encoding='utf-8') as file:
                data = json.load(file)
                for item in data.get('courses', []):
                    id = item.get('id')
                    course_name = item.get('Course Name')
                    program_code = item.get('program_code')

                    # Fetch the school or skip the course if school_id is not found
                    try:
                        school = School.objects.get(id=id)
                    except School.DoesNotExist:
                        self.stdout.write(self.style.WARNING(f'School with id {id} does not exist. Skipping course.'))
                        continue

                    # Create a course associated with the school
                    Course.objects.create(name=course_name, program_code=program_code, school=school)

            self.stdout.write(self.style.SUCCESS('Data import completed successfully.'))
        except Exception as e:
            self.stdout.write(self.style.ERROR(f'Error importing data: {str(e)}'))
