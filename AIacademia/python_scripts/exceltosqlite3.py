# writing from excel to the db for consistency

import sqlite3
import pandas as pd
import random

# Function to read data from Excel file
def read_excel_file(file_path):
    df = pd.read_excel(file_path)
    return df

# Function to create SQLite database and write data to it
def write_to_database(data, db_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Insert data into table
    for index, row in data.iterrows():
        cursor.execute('''INSERT INTO academia_app_school (name, abbreviation) 
                          VALUES (?, ?)''', (row['SCHOOL'], row['PREFIX'])) 

    # Commit changes and close connection
    conn.commit()
    conn.close()

# Main function
def main():
    excel_file_path = r'C:\Users\Simon\proacted\AIacademia\test_data_files\Schools_and_Courses.csv'  # Replace with your Excel file path
    db_name = 'db.sqlite3'  # Replace with your SQLite database name

    # Read data from Excel file
    data = read_excel_file(excel_file_path)

    # Write data to SQLite database
    write_to_database(data, db_name)

if __name__ == "__main__":
    main()
