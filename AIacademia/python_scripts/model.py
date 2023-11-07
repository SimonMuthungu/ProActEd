<<<<<<< HEAD
import json
import os
import django
import sys

sys.path.append(r'C:\Users\Simon\proacted\AIacademia')

# Initialize Django to use its models outside a regular environment
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "AIacademia.settings")
django.setup()

from academia_app.models import Recommender_training_data

# Load the JSON data
with open('AIacademia\schools_and_courses_data.json', 'r') as file:
    data = json.load(file)

courses_data = data['courses']

# Write data to the database
for course_data in courses_data:
    course = Recommender_training_data(
        Course_name=course_data['Course Name'],
        Course_objectives=" ",
        Course_general_info_and_about=" ",
        General_prereuisites = " ",
        Subject_prerequisites = " "
    )
    course.save()
print("Courses data successfully migrated!")
=======
import gensim

# Load the model
print('started reading')
model = gensim.models.KeyedVectors.load_word2vec_format(r"C:\Users\Simon\proacted\GoogleNews-vectors-negative300.bin", binary=True)
print('finished reading')
# Get the vector for the word 'computer'
m = model['computer']

# Print the vector
print(m)
>>>>>>> c05bfde20735bbfed350f994a5a4c930eba30e28
