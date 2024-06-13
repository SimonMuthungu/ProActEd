# data_migration/management/commands/populate_data.py

from django.core.management.base import BaseCommand
from academia_app.models import FieldOfInterest, HighSchoolSubject

class Command(BaseCommand):
    help = 'Populate initial data for FieldOfInterest and HighSchoolSubject'

    def handle(self, *args, **kwargs):
        # List of interests and subjects
        interests_data = [
            'POLITICS', 'SCIENCE', 'DESIGN', 'ARTS', 'TEACHING', 'PUBLIC SPEAKING',
            'READING', 'OUTDOOR ACTIVITIES', 'MUSIC', 'ART AND CREATIVITY', 'GARDENING',
            'GAMING', 'WRITING', 'TRAVELLING', 'TECHNOLOGY', 'CODING', 'VOLUNTEERING',
            'COLLECTING', 'DANCE', 'FILM AND CINEMA', 'ANIMAL PETS', 'DIY AND CRAFTING',
            'HISTORY AND GENEOLGY', 'ASTRONOMY', 'READING AND LEARNING', 'FISHING',
            'BIRD WATCHING', 'CYCLING', 'ARCHERY', 'MARTIAL ARTS', 'POTTERY AND CERAMICS',
            'BOARD GAME DESIGN', 'HOME BREWING', 'PHOTOGRAPHY', 'GOLF', 'ROBOTICS',
            'CALLIGRAPHY', 'HOME IMPROVEMENT', 'METAL DETECTING'
        ]

        subjects_data = [
            'MATHEMATICS', 'ENGLISH', 'KISWAHILI', 'CHEMISTRY', 'BIOLOGY', 'PHYSICS',
            'CRE', 'IRE', 'HISTORY', 'GEOGRAPHY', 'AGRICULTURE', 'BUSINESS STUDIES',
            'COMPUTER STUDIES', 'HOME SCIENCE','MUSIC','ART AND DESIGN', 'DRAWING AND DESIGN',
            'GERMAN', 'FRENCH'
        ]

        # Create interests
        for interest in interests_data:
            obj, created = FieldOfInterest.objects.get_or_create(name=interest)
            if created:
                self.stdout.write(self.style.SUCCESS(f'Created interest: {obj.name}'))

        # Create subjects
        for subject in subjects_data:
            obj, created = HighSchoolSubject.objects.get_or_create(name=subject)
            if created:
                self.stdout.write(self.style.SUCCESS(f'Created subject: {obj.name}'))

        self.stdout.write(self.style.SUCCESS('Successfully populated data'))
