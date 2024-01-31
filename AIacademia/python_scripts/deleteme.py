import os
import sys
import django
import re
import numpy as np

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Recommender_training_data

# Query the database to find the row with the longest course description
longest_description_row = Recommender_training_data.objects.order_by('-course_general_info_and_about').first()

# Print the course name and the length of the course description
print("Course Name:", longest_description_row.course_name)
print("Length of Course Description:", len(longest_description_row.course_general_info_and_about))
