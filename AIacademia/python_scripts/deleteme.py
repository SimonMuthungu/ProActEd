import os
import sys
import django
import re
import numpy as np

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Recommender_training_data_byte_vectors


# Retrieve the binary data from the database
vector_record = Recommender_training_data_byte_vectors.objects.get(course_name='Bachelor of Science (Agribusiness Management, With IT)')

# # Convert the hexadecimal string to a multiline string
# course_objectives_vector = """
# {}
# """.format(vector_record.course_objectives.strip())  # Remove leading/trailing whitespace

# print(course_objectives_vector) 
# x = bytes.fromhex(course_objectives_vector)

# Retrieve the binary data from the database
vector_record = Recommender_training_data_byte_vectors.objects.get(course_name='Bachelor of Science (Agribusiness Management, With IT)') 

# Convert the byte data to a hexadecimal string
course_objectives_vector_hex = vector_record.course_objectives

print(type(course_objectives_vector_hex))

vector_list = []


try:
    # Assuming course_objectives_vector_hex contains the hexadecimal string
    print(f"Original Hexadecimal String: {course_objectives_vector_hex}")

    # Remove 'b' character and non-hexadecimal characters
    valid_hexadecimal_string = course_objectives_vector_hex.lstrip('b')
    valid_hexadecimal_string = re.sub(r'[^0-9a-fA-F ]', '', valid_hexadecimal_string)
    print(f"Valid Hexadecimal String: {valid_hexadecimal_string}")


    # Convert hexadecimal value to float and store them in a list 
    vector_array = np.array([float.fromhex(valid_hexadecimal_string)])
    print(f"Vector Array: {vector_array}") 

    # Convert the list of float values to a NumPy array
    vector_array = np.array(vector_array)
    print(f"Vector Array Shape: {vector_array.shape}")
    
    # Assuming you know the original shape (e.g., (2100,))
    # vector_array = vector_array.reshape((2100,))
    
    print(f"Vector Array (Reshaped): {vector_array}")

    vector_list.append(vector_array)


except Exception as e:
    print(f"An error occurred: {e}")
