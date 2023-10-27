import os
import django
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import joblib
import sys
from prepare_recommender_dataset import preprocess_text
from scipy.sparse import hstack


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
stacked_courses_matrix = hstack([combined_matrix, prerequisites_matrix])


top_5 = 3


student_interests = "technology"
student_subject_strengths = "computer studies"

# Cleaning student interests using nltk
clean_student_interests = preprocess_text(student_interests)
clean_student_subject_strengths = preprocess_text(student_subject_strengths)


combined_student_profile = combined_vectorizer.transform([student_interests])
prerequisites_student_profile = prerequisites_vectorizer.transform([student_subject_strengths])
stacked_student_matrix = hstack([combined_student_profile, prerequisites_student_profile])

combined_similarities = cosine_similarity(stacked_courses_matrix, stacked_student_matrix) 
combined_courses_indices = combined_similarities.flatten().argsort()[::-1]
combined_recommended_courses = combined_courses_indices[:top_5]
combined_recommended_course_names = df['Course Name'].iloc[combined_recommended_courses].tolist()


print("\nRecommended Courses based on Combined Info:\n")
for course in combined_recommended_course_names:
    print(course)

# print(combined_similarities)
# print('-------------------')
# print(combined_courses_indices)
# print('-------------------')
# print(combined_recommended_courses)
