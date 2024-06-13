import os
import django
import random
import string

# Initialize Django
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from django.contrib.auth.models import Group
from academia_app.models import BaseUser, StudentUser, Course, School

# Expanded list of first and last names
first_names = [
    "John", "Jane", "Alice", "Bob", "Charlie", "David", "Emma", "Fiona", "George", "Hannah",
    "Michael", "Jennifer", "Christopher", "Jessica", "Matthew", "Ashley", "Andrew", "Emily", 
    "Daniel", "Jessica", "Joshua", "Amanda", "William", "Sarah", "Joseph", "Samantha", 
    "Robert", "Elizabeth", "Ryan", "Olivia", "Nicholas", "Sophia", "Anthony", "Isabella", 
    "Jason", "Mia", "Brian", "Madison", "Kevin", "Alexis", "Eric", "Abigail", 
    "Steven", "Grace", "Thomas", "Ella", "Timothy", "Hailey", "Charles", "Alyssa", 
    "Mark", "Taylor", "Paul", "Kayla", "Donald", "Anna", "James", "Victoria"
]

last_names = [
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
    "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin",
    "Lee", "Perez", "Thompson", "White", "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson",
    "Walker", "Young", "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores",
    "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", "Carter", "Roberts"
]

def random_name():
    return f"{random.choice(first_names)} {random.choice(last_names)}"

# Generate random relevant text
def random_text(max_length=50):
    words = [
        "excellent", "good", "average", "needs improvement", "outstanding", "satisfactory", "unsatisfactory",
        "engaging", "motivated", "determined", "cooperative", "creative", "disciplined", "persistent",
        "collaborative", "focused", "curious", "responsive", "articulate", "enthusiastic", "independent",
        "organized", "confident", "resilient", "empathetic", "respectful", "proactive", "efficient",
        "attentive", "innovative", "problem-solving", "adaptable", "adventurous", "analytical", "tenacious",
        "patient", "perceptive", "resourceful", "reliable", "tech-savvy", "team player", "leadership"
    ]
    return ' '.join(random.choices(words, k=random.randint(5, max_length//6)))

def random_string(length=8):
    return ''.join(random.choices(string.ascii_lowercase + string.digits, k=length))

def generate_unique_username(first_name, last_name):
    # Generate a unique username
    while True:
        random_suffix = ''.join(random.choices(string.ascii_lowercase + string.digits, k=6))
        username = f'{first_name.lower()}.{last_name.lower()}.{random_suffix}'
        try:
            existing_user = BaseUser.objects.get(username=username)
            print(f"Username {username} already exists, generating a new one...")
        except BaseUser.DoesNotExist:
            return username

def create_student_user(i):
    try:
        # Generate random data for the student
        name = random_name()
        first_name, last_name = name.split()
        username = generate_unique_username(first_name, last_name)
        registration_number = f'REG{i:05d}'
        
        # Provide a default value for student_field
        student_field = random_text()  # You can use any value here
        
        graduation_probability = random.uniform(0, 100)
        lessons_attended = random.uniform(0, 100)
        total_lessons = random.uniform(0, 234)
        aggregate_points = random.uniform(0, 100)
        pcnt_of_lessons_attended = random.uniform(0, 100)
        homework_submission_rates = random.uniform(0, 100)
        activity_on_learning_platforms = random.uniform(0, 100)
        cat_1_marks = random.uniform(0, 100)
        cat_2_marks = random.uniform(0, 100)
        deadline_adherence = random_text(50)
        teachers_comments = random_text(100)
        activity_on_elearning_platforms = random.uniform(0, 100)
        
        # Determine course_id and school_id
        course_id = random.randint(1, 75)
        school_mapping = [
            (1, 3, 91), (4, 6, 92), (7, 10, 93), (11, 16, 94), 
            (17, 21, 95), (22, 30, 96), (31, 34, 93), (35, 45, 97), 
            (46, 52, 98), (53, 69, 99), (70, 70, 100), 
            (71, 73, 101), (74, 74, 102), (75, 75, 103)
        ]
        for start, end, school_id in school_mapping:
            if start <= course_id <= end:
                break
        
        # Create BaseUser
        user = BaseUser.objects.create_user(
            username=username, 
            password='changeme', 
            first_name=first_name,
            last_name=last_name,
            email=f'{username}@gmail.com'
        )
        
        # Assign user to Student User group
        student_user_group, _ = Group.objects.get_or_create(name='Student User')
        user.groups.add(student_user_group)
        
        # Create StudentUser with the default value for student_field
        student_user = StudentUser.objects.create(
            baseuser_ptr=user,
            name=name,
            registration_number=registration_number,
            course_id=course_id,
            school_id=school_id,
            graduation_probability=graduation_probability,
            Lessons_Attended=lessons_attended,
            Total_lessons_in_that_period=total_lessons,
            Aggregate_points=aggregate_points,
            pcnt_of_lessons_attended=pcnt_of_lessons_attended,
            homework_submission_rates=homework_submission_rates,
            activity_on_learning_platforms=activity_on_learning_platforms,
            CAT_1_marks=cat_1_marks,
            CAT_2_marks=cat_2_marks,
            Deadline_Adherence=deadline_adherence,
            teachers_comments_so_far=teachers_comments,
            activity_on_elearning_platforms=activity_on_elearning_platforms,
            student_field=student_field  # Provide a default value
        )
        
        return student_user
    except Exception as e:
        print(f"Error creating student {i}: {e}")
        print(f"Failed username: {username}")
        return None

def populate_students(n=1000):
    try:
        for i in range(1, n + 1):
            create_student_user(i)
            if i % 100 == 0:
                print(f"Processed batch {i-99} to {i}")
    except KeyboardInterrupt:
        print("\n\nProcess interrupted. Exiting...")
    except Exception as e:
        print(f"\n\nError: {e}")

if __name__ == '__main__':
    populate_students()
