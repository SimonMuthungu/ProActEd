# writing from excel to the db for consistency

import sqlite3
import pandas as pd
import re

# Function to read data from CSV file
def read_csv_file(file_path):
    df = pd.read_csv(file_path)
    return df

# Function to preprocess data and extract unique schools and their abbreviations
def preprocess_data(data):
    unique_schools = {}
    for index, row in data.iterrows():
        school_name = row['SCHOOL']
        abbreviation = re.search(r'\((.*?)\)', school_name).group(1)
        school_name = re.sub(r'\s*\([^)]*\)', '', school_name)  # Remove abbreviations from school name
        if school_name not in unique_schools:
            unique_schools[school_name] = abbreviation
    return unique_schools

# Function to write data to SQLite database
def write_to_database(unique_schools, db_name):
    print("Database Path:", db_name)
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Insert data into table
    for school_name, abbreviation in unique_schools.items():
        cursor.execute('''INSERT INTO academia_app_school (name, abbreviation) 
                          VALUES (?, ?)''', (school_name, abbreviation)) 

    # Commit changes and close connection
    conn.commit()
    conn.close()

# Main function
def main():
    csv_file_path = r'C:\Users\Simon\proacted\AIacademia\test_data_files\Schools_and_Courses.csv'  # Replace with your CSV file path
    db_name = 'db (galavu).sqlite3'  # Replace with your SQLite database name 

    # Read data from CSV file
    data = read_csv_file(csv_file_path)

    # Preprocess data to extract unique schools and their abbreviations
    unique_schools = preprocess_data(data)

    # Write data to SQLite database
    write_to_database(unique_schools, db_name)

if __name__ == "__main__":
    main()


# write to school, course n student. calculate probs from there into the admin interface.