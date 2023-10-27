# academia_app/management/commands/add_schools.py
from academia_app.models import School
from django.core.management.base import BaseCommand


class Command(BaseCommand):
    help = 'Add schools to the database'

    def handle(self, *args, **options):
        schools = [
            {"id": 14,"name": "School of Agriculture & Food Security", "abbreviation": "SAFS"},
            {"id": 13,"name": "School of Arts and Social Sciences", "abbreviation": "SASS"},
            {"id": 12,"name": "School of Business and Economics", "abbreviation": "SBE"},
            {"id": 11,"name": "School of Computing & Informatics", "abbreviation": "SCI"},
            {"id": 10,"name": "School of Development and Strategic Studies", "abbreviation": "SDSS"},
            {"id": 9,"name": "School of Education", "abbreviation": "SE"},
            {"id": 8,"name": "School of Mathematics, Statistics & Actuarial Science", "abbreviation": "SMSAS"},
            {"id": 7,"name": "School of Medicine", "abbreviation": "SM"},
            {"id": 6,"name": "School of Nursing", "abbreviation": "SN"},
            {"id": 5,"name": "School of Pharmacy", "abbreviation": "SP"},
            {"id": 4,"name": "School of Physical & Biological Sciences", "abbreviation": "SPBS"},
            {"id": 3,"name": "School of Planning and Architecture", "abbreviation": "SPA"},
            {"id": 2,"name": "School of Public Health & Community Development", "abbreviation": "SPHCD"},
            {"id": 1,"name": "School of Law", "abbreviation": "SL"}
        ]

        for school_data in schools:
            School.objects.create(**school_data)

        self.stdout.write(self.style.SUCCESS('Schools added successfully.'))
