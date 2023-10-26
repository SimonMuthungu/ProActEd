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
    "Course Objectives": course.Course_Objectives,
    "Course General Info and About": course.Course_General_Info_and_About,
    "Prerequisites": course.Prerequisites
} for course in all_courses]

df = pd.DataFrame(courses_list)


tfidf_vectorizer = TfidfVectorizer()
tfidf_matrix = tfidf_vectorizer.fit_transform(df['Prerequisites'])

matrix = tfidf_vectorizer.transform(df['Prerequisites'])

student_interests = "I love technology and coding"
# cleaning student interests using nltk
clean_student_interests = preprocess_text(student_interests)
print(clean_student_interests)

student_profile = tfidf_vectorizer.transform([student_interests])

similarities = cosine_similarity(student_profile, matrix)
similar_courses_indices = similarities.argsort(axis=1)[:, ::-1]

top_5 = 5
recommended_courses = similar_courses_indices[0][:top_5]
recommended_course_names = df['Course Name'].iloc[recommended_courses].tolist()

print("\nRecommended Courses based on Prerequisites:\n")
for course in recommended_course_names:
    print(course)
