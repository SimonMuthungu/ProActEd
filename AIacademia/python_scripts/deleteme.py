import pandas as pd
import os
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'academia_app.settings')
django.setup()

from academia_app.models import probabilitydatatable  # Import your model

# Path to your Excel file
excel_path = r'C:\Users\Simon\proacted\AIacademia\data_files\trainwith_100000.xlsx'

# Read the Excel file
df = pd.read_excel(excel_path, engine='openpyxl')

# Iterate over DataFrame rows
for index, row in df.iterrows():
    # Create and save an instance of the model for each row in the DataFrame
    instance = probabilitydatatable(
        Lessons_Attended=row['Lessons_Attended'],  # Match Excel column names with model fields
        Total_lessons_in_that_period=row['Total_lessons_in_that_period'],
        Aggregate_points = row['Aggregate_points']
        passed = row['passed']
        pcnt_of_lessons_attended = row['%_of_lessons_attended']
        homework_submission_rates = row['homework_submission_rates']
        activity_on_learning_platforms = row['activity_on_learning_platforms']
        CAT_1_marks = row['CAT_1_marks']
        Activity_in_group_discussions = row['Activity_in_group_discussions']
        CAT_2_marks = row['CAT_2_marks']
        Deadline_Adherence = row['Deadline_Adherence']
    )
    instance.save()

print("Data imported successfully.")
