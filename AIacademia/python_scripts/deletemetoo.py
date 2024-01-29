import os
import sys
import django

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()


from academia_app.models import Recommender_training_data_byte_vectors

# Retrieve the binary data from the database
vector_record = Recommender_training_data_byte_vectors.objects.get(course_name='Bachelor of Science (Agribusiness Management, With IT)') 

print(vector_record)
course_objectives_vector = vector_record.course_objectives
course_general_info_and_about_vector = vector_record.course_general_info_and_about


# If the data is stored as a hexadecimal string, convert it to bytes
course_objectives_vector_bytes = bytes.fromhex(course_objectives_vector)
course_general_info_and_about_vector_bytes = bytes.fromhex(course_general_info_and_about_vector)


# Now, you have the binary data as bytes objects
# You can use the data as needed, e.g., convert it back to numpy arrays
import numpy as np
objective_vector = np.frombuffer(course_objectives_vector_bytes, dtype=np.float32)
general_info_vector = np.frombuffer(course_general_info_and_about_vector_bytes, dtype=np.float32)

print(objective_vector)
print(general_info_vector) 
