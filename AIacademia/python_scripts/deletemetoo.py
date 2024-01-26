import numpy as np
import os
import sys
import django

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Recommender_training_data_number_vectors

# Choose the column you want to examine (e.g., 'course_objectives')
selected_column = 'course_objectives'

# Retrieve the data from the database
number_vectors = Recommender_training_data_number_vectors.objects.all()

# Access the first vector in the selected column (assuming there's at least one row)
vector = getattr(number_vectors[0], selected_column)

# Convert the serialized string back to a NumPy array
vector = np.fromstring(vector, dtype=np.float32)

# Print the shape (dimensions) of the vector
print(f"Vector shape: {vector.shape}")

# Print the vector itself (if you want to see its values)
print("Vector values:")
print(vector)
