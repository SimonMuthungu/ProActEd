import os
import django
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import joblib
import sys
from prepare_recommender_dataset import preprocess_text

sys.path.append(r'C:\Users\Simon\proacted\AIacademia')

# Initialize Django environment
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# Import the model after Django environment is set up
from academia_app.models import Course_data_for_recommender

# Fetch all data from the Course_data_for_recommender model
all_courses = Course_data_for_recommender.objects.all()

courses_list = [{
    "Course Name": course.Course_name,
    "Combined Info": course.Course_Objectives + " " + course.Course_General_Info_and_About,
    "Prerequisites": course.Prerequisites
} for course in all_courses]

df = pd.DataFrame(courses_list)

# Create separate vectorizers for the combined column and the Prerequisites column
combined_vectorizer = TfidfVectorizer()
prerequisites_vectorizer = TfidfVectorizer()

combined_matrix = combined_vectorizer.fit_transform(df['Combined Info'])
prerequisites_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])

student_interests = "farming and general agriculture"
student_subject_strengths = "biology and agriculture"
# Cleaning student interests using nltk
clean_student_interests = preprocess_text(student_interests)
clean_student_subject_strengths = preprocess_text(student_subject_strengths)


top_5 = 5 

# Getting cosine similarities based on the combined information
combined_student_profile = combined_vectorizer.transform([student_interests])
combined_similarities = cosine_similarity(combined_student_profile, combined_matrix)
combined_courses_indices = combined_similarities.argsort(axis=1)[:, ::-1]
combined_recommended_courses = combined_courses_indices[0][:top_5]
combined_recommended_course_names = df['Course Name'].iloc[combined_recommended_courses].tolist()

# Getting cosine similarities based on the prerequisites
prerequisites_student_profile = prerequisites_vectorizer.transform([student_subject_strengths])
prerequisites_similarities = cosine_similarity(prerequisites_student_profile, prerequisites_matrix)
prerequisites_courses_indices = prerequisites_similarities.argsort(axis=1)[:, ::-1]
prerequisites_recommended_courses = prerequisites_courses_indices[0][:top_5]
prerequisites_recommended_course_names = df['Course Name'].iloc[prerequisites_recommended_courses].tolist()


print("\nRecommended Courses based on Combined Info:\n")
for course in combined_recommended_course_names:
    print(course)

print("\nRecommended Courses based on Prerequisites:\n")
for course in prerequisites_recommended_course_names:
    print(course)
