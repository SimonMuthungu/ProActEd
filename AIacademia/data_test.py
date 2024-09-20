import os
import django

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from bot_data.models import MasenoInfo

def check_data_in_database():
    data = MasenoInfo.objects.using('bot_db').all()
    for entry in data:
        print(f"Category: {entry.category}, Detail: {entry.detail}, Additional Info: {entry.additional_info}")

# Call the function
check_data_in_database()
