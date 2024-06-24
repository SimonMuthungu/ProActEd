import os
import csv
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from bot_data.models import MasenoInfo

csv_file_path = 'C:/Users/user/Desktop/Scrapping_maseno_info/CSVS/msu_combined.csv'

def import_data_from_csv(file_path):
    with open(file_path, mode='r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for row in reader:
            MasenoInfo.objects.using('bot_db').create(
                category=row['Category'],
                detail=row['Detail'],
                additional_info=row['Additional Info']
            )

# Call the function
import_data_from_csv(csv_file_path)
print("Data imported successfully.")
