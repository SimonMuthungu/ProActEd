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
        ran = 80.0
        cursor.execute('''INSERT INTO academia_app_probabilitydatatable (Lessons_Attended, Total_lessons_in_that_period, Aggregate_points, pcnt_of_lessons_attended, homework_submission_rates, activity_on_learning_platforms, CAT_1_marks, CAT_2_marks, Deadline_Adherence, teachers_comments_so_far, activity_on_elearning_platforms, passed_or_not) 
                          VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', (row['Lessons_Attended'], row['Total_lessons_in_that_period'], row['Aggregate points'], row['% of lessons attended'], row['homework submission rates'], ran, row['CAT 1 marks'], row['CAT 2 marks'], row['Deadline Adherence'], row['teachers comments so far'], row['activity on e-learning platforms'], row['passed_or_not'])) 

    # Commit changes and close connection
    conn.commit()
    conn.close()

# Main function
def main():
    excel_file_path = r'C:\Users\Simon\proacted\AIacademia\test_data_files\trainwith_100000.xlsx'  # Replace with your Excel file path
    db_name = 'db.sqlite3'  # Replace with your SQLite database name

    # Read data from Excel file
    data = read_excel_file(excel_file_path)

    # Write data to SQLite database
    write_to_database(data, db_name)

if __name__ == "__main__":
    main()
