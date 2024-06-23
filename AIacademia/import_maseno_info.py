import os
import csv
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import MasenoInfo

# Path to your CSV file
csv_file_path = 'C:/Users/user/Desktop/Scrapping_maseno_info/CSVS/msu_combined.csv'

# Function to import data from CSV
def import_data_from_csv(file_path):
    with open(file_path, mode='r', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for row in reader:
            MasenoInfo.objects.create(
                category=row['Category'],
                detail=row['Detail'],
                additional_info=row['Additional Info']
            )

if __name__ == "__main__":
    import_data_from_csv(csv_file_path)
    print("Data import completed successfully!")
