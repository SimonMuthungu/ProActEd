import json
from django.core.management.base import BaseCommand
from django.core.serializers.json import DjangoJSONEncoder
from academia_app.models import Recommender_training_data_byte_vectors

class Command(BaseCommand):
    help = 'Dumpdata excluding binary fields'

    def handle(self, *args, **options):
        data = []
        for obj in Recommender_training_data_byte_vectors.objects.all():
            obj_dict = {
                "course_name": obj.course_name,
                # Exclude binary fields
                "course_objectives": None,
                "course_general_info_and_about": None,
                "general_prerequisites": None,
                "subject_prerequisites": None,
            }
            data.append(obj_dict)
        
        with open('recommender_training_data_byte_vectors_backup.json', 'w') as f:
            json.dump(data, f, cls=DjangoJSONEncoder)
        
        self.stdout.write(self.style.SUCCESS('Successfully dumped data excluding binary fields'))
