# this file can only run on the main directory of this project

import os
import sys

import django
import pandas as pd

# sys.path.append('/AIacademia/')


# Initialize Django environment
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# Django model import here
from academia_app.models import Course_data_for_recommender


def import_data_from_excel(excel_file_path):
    # Read the Excel file
    df = pd.read_excel(excel_file_path, engine='openpyxl')

    # Assuming your Excel sheet has columns: 'course_name', 'subject_prerequisite', 'general_prerequisite'
    # Adjust if your column names are different
    for index, row in df.iterrows():
        course = Course_data_for_recommender(
            Course_name=row['Course Name'],
            Course_Objectives=row['Course Objectives'],
            Course_General_Info_and_About=row['Course General Info and About'],
            Prerequisites=row['Prequisites']
        )
        course.save()

    print("Data imported successfully!")

if __name__ == "__main__":
    file_path = r"C:\Users\Simon\proacted\AIacademia\data_files\gpt4_recommender_gen_training_data.xlsx"
    import_data_from_excel(file_path)
