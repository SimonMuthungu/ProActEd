# Populating the StudentUser table

import sqlite3
import random

# Names and registration numbers of students
students = [
    ("Bentheya CCS/00015/022", "Bentheya Galavu"),
    ("Vyron Mino CCS/00023/022", "Vyron Mino"),
    ("Alex Njau CCS/00003/022", "Alex Njau"),
    ("Caeser Mwania CCS/00056/022", "Caeser Mwania"),
    ("Rholex Oruko CCS/00010/022", "Rholex Oruko"),
    ("Kelvin Muchai TMC/00009/022", "Kelvin Muchai"),
    ("Meshack Muema TMC/00081/022", "Meshack Muema"),
    ("Nicole Chepkorir TMC/00071/022", "Nicole Chepkorir")
]

# Function to get random course and school IDs
def get_random_ids(db_name, table_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Get all IDs from the specified table
    cursor.execute(f'SELECT id FROM {table_name}')
    ids = cursor.fetchall()

    # Close connection
    conn.close()

    # Return a random ID from the list
    return random.choice(ids)[0]

# Function to write data to SQLite database
def write_to_database(students, db_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Insert data into table
    for registration_number, name in students:
        # Get random course and school IDs
        course_id = get_random_ids(db_name, 'academia_app_course')
        school_id = get_random_ids(db_name, 'academia_app_school')

        # Get the id from the BaseUser table
        cursor.execute("SELECT id FROM academia_app_baseuser WHERE username=?", (name,))
        base_user_id = cursor.fetchone()[0]  # Fetch the id

        cursor.execute('''INSERT INTO academia_app_studentuser 
                          (baseuser_ptr_id, student_field, name, registration_number, graduation_probability, course_id, school_id) 
                          VALUES (?, ?, ?, ?, ?, ?, ?)''', 
                          (base_user_id, name, name, registration_number, 0.0, course_id, school_id))

    # Commit changes and close connection
    conn.commit()
    conn.close()


# Main function
def main():
    db_name = 'db (galavu).sqlite3'  # Replace with your SQLite database name 

    # Write data to SQLite database
    write_to_database(students, db_name)

if __name__ == "__main__":
    main()
