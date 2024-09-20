# writing from excel to the db for consistency

import sqlite3
import pandas as pd
import re

# Function to read data from CSV file
def read_csv_file(file_path):
    df = pd.read_csv(file_path)
    return df

# Function to preprocess data and extract unique courses, their abbreviations, and corresponding school names
def preprocess_data(data):
    unique_courses = {}
    for index, row in data.iterrows():
        school_name = row['SCHOOL']
        course_name = row['PROGRAM']  # Assuming 'DIR' column contains course names
        abbreviation = row['PREFIX']  # Assuming 'PREFIX' column contains course abbreviations
        school_name = re.sub(r'\s*\([^)]*\)', '', school_name)  # Remove abbreviations from school name
        unique_courses[(school_name, course_name)] = abbreviation
    return unique_courses

# Function to get school IDs from the database
def get_school_ids(unique_courses, db_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    school_ids = {}
    for school_course, _ in unique_courses.items():
        school_name, _ = school_course
        cursor.execute('''SELECT id FROM academia_app_school WHERE name = ?''', (school_name,))
        result = cursor.fetchone()
        if result:
            school_ids[school_course] = result[0]

    conn.close()
    return school_ids

# Function to write data to SQLite database
def write_to_database(unique_courses, school_ids, db_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Insert data into table
    for (school_name, course_name), abbreviation in unique_courses.items():
        school_id = school_ids.get((school_name, course_name))
        if school_id:
            cursor.execute('''INSERT INTO academia_app_course (name, prefix, school_id) 
                              VALUES (?, ?, ?)''', (course_name, abbreviation, school_id))

    # Commit changes and close connection
    conn.commit()
    conn.close()

# Main function
def main():
    csv_file_path = r'C:\Users\Simon\proacted\AIacademia\test_data_files\Schools_and_Courses.csv'  # Replace with your CSV file path
    db_name = 'db (galavu).sqlite3'  # Replace with your SQLite database name 

    # Read data from CSV file
    data = read_csv_file(csv_file_path)

    # Preprocess data to extract unique courses, their abbreviations, and corresponding school names
    unique_courses = preprocess_data(data)

    # Get school IDs from the database
    school_ids = get_school_ids(unique_courses, db_name)

    # Write data to SQLite database
    write_to_database(unique_courses, school_ids, db_name)

if __name__ == "__main__":
    main()
