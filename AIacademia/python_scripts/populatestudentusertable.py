import sqlite3
import random

from torch import rand

def read_names_from_file(file_path):
    with open(file_path, 'r') as file:
        names = file.readlines()
    # Remove newline characters and return the list of names
    return [name.strip() for name in names]

# List of random first names from the file
file_path = r'C:\Users\Simon\Downloads\first-names.txt'
first_names = read_names_from_file(file_path)

# Function to generate the numerical part of the registration number
def generate_registration_number(sch_id, cursor):
    while True:
        # Generate a potential registration number
        first_digit = str(random.randint(0, 2))
        second_digit = str(random.choice([2, 1]))
        remaining_digits = ''.join(str(random.randint(0, 9)) for _ in range(2))

        #find school id for abbreviation
        abbreviation = cursor.execute("SELECT abbreviation FROM academia_app_school WHERE id=?", (sch_id,))
        abbreviation = cursor.fetchone()[0]

        reg_number = f"{abbreviation}/00{first_digit}{remaining_digits}/02{second_digit}"

        # Check if the generated registration number already exists in the database
        cursor.execute("SELECT COUNT(*) FROM academia_app_studentuser WHERE registration_number=?", (reg_number,))
        count = cursor.fetchone()[0]

        # If the registration number is unique, return it
        if count == 0:
            return reg_number


# Function to get random names
def get_random_names():
    return random.sample(first_names, 2)  # Get any two random first names

import sqlite3

def get_school_id_for_course(db_name, course_id):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Fetch school ID for the given course ID
    cursor.execute("SELECT school_id FROM academia_app_course WHERE id=?", (course_id,))
    school_id = cursor.fetchone()[0]

    # Close connection
    conn.close()

    return school_id

def write_to_database(db_name):
    conn = sqlite3.connect(db_name)
    cursor = conn.cursor()

    # Keep track of selected base users
    selected_base_users = set()

    # Iterate through each course
    for course_id in range(1, 75):
        # Get school ID for the current course
        school_id = get_school_id_for_course(db_name, course_id)

        # Select a random base user for the current course (ensure uniqueness)
        base_user_id = random.randint(87, 2008)
        while base_user_id in selected_base_users:
            base_user_id = random.randint(87, 2008)

        # Add selected base user to the set
        selected_base_users.add(base_user_id)

        # Fetch base user details from academia_app_baseuser table
        cursor.execute("SELECT username, first_name, last_name FROM academia_app_baseuser WHERE id=?", (base_user_id,))
        base_user_data = cursor.fetchone()

        # Extract username, first name, and last name
        username, first_name, last_name = base_user_data

        lessons = random.randint(30, 220)

        user_reg_no = generate_registration_number(school_id, cursor)
        print(f'current base_user_id: {base_user_id}')

        while True:
            try:
                # Insert data into academia_app_studentuser table
                cursor.execute('''INSERT INTO academia_app_studentuser 
                    (baseuser_ptr_id, student_field, name, registration_number, graduation_probability, profile_picture, course_id, school_id, Aggregate_points, CAT_1_marks, CAT_2_marks, Lessons_Attended, Total_lessons_in_that_period, activity_on_elearning_platforms, activity_on_learning_platforms, homework_submission_rates, pcnt_of_lessons_attended, teachers_comments_so_far, Deadline_Adherence) 
                    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', 
                    (base_user_id, f"{first_name} {last_name}", f"{first_name} {last_name}", user_reg_no, 0.0, None, course_id, school_id, random.randint(30, 65), random.randint(5, 28), random.randint(10, 25), lessons, 234, random.randint(30, 95), random.randint(20, 85), random.randint(20, 85), int(lessons/234*100), "There is room for improvement", "mostly on time")) 
            except:
                # Select a random base user for the current course (ensure uniqueness)
                base_user_id = random.randint(87, 2008)
                while base_user_id in selected_base_users:
                    base_user_id = random.randint(87, 2008)

                # Add selected base user to the set
                selected_base_users.add(base_user_id)

                # Fetch base user details from academia_app_baseuser table
                cursor.execute("SELECT username, first_name, last_name FROM academia_app_baseuser WHERE id=?", (base_user_id,))
                base_user_data = cursor.fetchone()

                # Extract username, first name, and last name
                username, first_name, last_name = base_user_data

                lessons = random.randint(30, 220)

                user_reg_no = generate_registration_number(school_id, cursor)
                print(f'current base_user_id: {base_user_id}')

                # Insert data into academia_app_studentuser table
                cursor.execute('''INSERT INTO academia_app_studentuser 
                    (baseuser_ptr_id, student_field, name, registration_number, graduation_probability, profile_picture, course_id, school_id, Aggregate_points, CAT_1_marks, CAT_2_marks, Lessons_Attended, Total_lessons_in_that_period, activity_on_elearning_platforms, activity_on_learning_platforms, homework_submission_rates, pcnt_of_lessons_attended, teachers_comments_so_far, Deadline_Adherence) 
                    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', 
                    (base_user_id, f"{first_name} {last_name}", f"{first_name} {last_name}", user_reg_no, 0.0, None, course_id, school_id, random.randint(30, 65), random.randint(5, 28), random.randint(10, 25), lessons, 234, random.randint(30, 95), random.randint(20, 85), random.randint(20, 85), int(lessons/234*100), "There is room for improvement", "mostly on time")) 


    # Commit changes and close connection
    conn.commit()
    conn.close()


# Main function
def main():
    db_name = r'C:\Users\Simon\proacted\AIacademia\db (galavu).sqlite3'  # Replace with your SQLite database name 

    # Write data to SQLite database
    write_to_database(db_name)

if __name__ == "__main__":
    main()

