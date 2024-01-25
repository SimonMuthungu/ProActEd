import os, sys
import django

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Recommender_training_data_byte_vectors, Recommender_training_data_number_vectors

byte_vectors = Recommender_training_data_byte_vectors.objects.all()

import numpy as np

for byte_vector in byte_vectors:
    course_name = byte_vector.course_name
    byte_objectives = byte_vector.course_objectives
    byte_general_info = byte_vector.course_general_info_and_about

    # Deserialize the byte vectors to NumPy arrays without encoding
    objectives_vector = np.frombuffer(byte_objectives, dtype=np.float32)
    general_info_vector = np.frombuffer(byte_general_info, dtype=np.float32)

    # Create a new entry in the number vectors table
    number_vector_entry = Recommender_training_data_number_vectors(
        course_name=course_name,
        course_objectives=objectives_vector,
        course_general_info_and_about=general_info_vector
    )
    number_vector_entry.save()

print('done...')
