import os
import sys
import django
import numpy as np


# Add your Django project directory to sys.path
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')


# Set the DJANGO_SETTINGS_MODULE
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Recommender_training_data_number_vectors


np.set_printoptions(threshold=np.inf)

# Retrieve the first record from the original table with hexadecimal strings
record = Recommender_training_data_number_vectors.objects.first()

if record:
    course_objectives_hex = record.course_objectives
    
    # Convert hexadecimal string to bytes
    course_objectives_bytes = bytes.fromhex(course_objectives_hex)
    
    # Convert bytes to a NumPy array (assuming the data is stored as float64)
    course_objectives_array = np.frombuffer(course_objectives_bytes, dtype=np.float64)
    
    # Reshape the array to the desired shape (e.g., 2100 dimensions)
    course_objectives_array = course_objectives_array.reshape((2100,))
    
    # print("Hexadecimal:", course_objectives_hex)
    print("Array Shape:", course_objectives_array.shape)
    print("Array Data:", type(course_objectives_array))
else:
    print("No records found in the original table.")
