import random
import string
from datetime import datetime, timedelta

def read_names_from_file(file_path):
    with open(file_path, 'r') as file:
        names = file.readlines()
    # Remove newline characters and return the list of names
    return [name.strip() for name in names]

# List of random first names from the file
file_path = r'C:\Users\Simon\Downloads\first-names.txt'
first_names = read_names_from_file(file_path)

# Function to get random names
def get_random_names():
    return random.sample(first_names, 2)  # Get any two random first names

# Example usage
name1, name2 = get_random_names()
print(f"Generated names: {name1} {name2}\n")



# Function to generate a random float value for the password
def generate_random_float():
    return random.uniform(0.0, 100.0)  # Adjust the range as needed

# Function to generate a random date between now and a week ago
def generate_random_date():
    now = datetime.now()
    week_ago = now - timedelta(days=7)
    random_date = random.uniform(week_ago.timestamp(), now.timestamp())
    return datetime.fromtimestamp(random_date).strftime('%Y-%m-%d %H:%M:%S')

# Function to generate a random base user
def generate_random_base_user(cursor):
    name1, name2 = get_random_names()
    username = ''.join(random.choices([name1, name2]))  # Generate a random username
    email = f"{username}{random.randint(0,9)}@example.com"
    role = ""  # Placeholder for role
    date_joined = generate_random_date()
    # Generate other placeholder values as needed

    # Check if the username already exists
    cursor.execute("SELECT COUNT(*) FROM academia_app_baseuser WHERE username=?", (username,))
    count = cursor.fetchone()[0]

    # If the username already exists, generate a new one
    while count > 0:
        name1, name2 = get_random_names()
        username = ''.join(random.choices([name1, name2]))
        email = f"{username}{random.randint(0,9)}@example.com"
        cursor.execute("SELECT COUNT(*) FROM academia_app_baseuser WHERE username=?", (username,))
        count = cursor.fetchone()[0]

    # Create a dictionary representing the base user
    base_user = {
        'password': generate_random_float(),
        'is_superuser': 0,
        'username': username,
        'first_name': name1,
        'last_name': name2,
        'email': email,
        'is_staff': 0,
        'is_active': 1,
        'date_joined': date_joined,
        'role': role
    }

    return base_user



import sqlite3, os

# Connect to the SQLite database
conn = sqlite3.connect(r'C:\Users\Simon\proacted\AIacademia\db (galavu).sqlite3')  
print("Connection to database established successfully")
cursor = conn.cursor()

current_directory = os.getcwd()

absolute_path = os.path.abspath(os.path.join(current_directory))

# Print the absolute path
print(f"Absolute path to the database file: {absolute_path}")



# Loop to generate and insert random base users
for baseuser in range(1, 498):
    random_base_user = generate_random_base_user(cursor) 

    # Insert the generated base user into the baseuser table
    cursor.execute('''INSERT INTO academia_app_baseuser 
                      (password, is_superuser, username, first_name, last_name, email, is_staff, is_active, date_joined, role) 
                      VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', 
                      (random_base_user['password'], 
                       random_base_user['is_superuser'], 
                       random_base_user['username'], 
                       random_base_user['first_name'], 
                       random_base_user['last_name'], 
                       random_base_user['email'], 
                       random_base_user['is_staff'], 
                       random_base_user['is_active'], 
                       random_base_user['date_joined'], 
                       random_base_user['role']))
    print(f"\nGenerated and inserted random base user: {random_base_user}")

# Commit changes and close connection
conn.commit()
conn.close()

