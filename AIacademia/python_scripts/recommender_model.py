# implementation of the recommender system

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity


path_to_data = r'C:\Users\Simon\proacted\AIacademia\python_scripts\preprocessed_data_two_columns.xlsx'

df = pd.read_excel(path_to_data)

# instantiating a vectorizer
tfidf_vectorizer = TfidfVectorizer()

# vectorizing the Course Objectives column
tfidf_matrix = tfidf_vectorizer.fit_transform(df['Course Objectives'])

# print(tfidf_matrix)

# testing with dummy interests
student_interests = "build tech systems"

# transform these using the same tf-idf
student_profile = tfidf_vectorizer.transform([student_interests])

# calculating cosine similarities b2n the dataset and student interests, and give an array
similarities = cosine_similarity(student_profile, tfidf_matrix)


similar_courses_indices = similarities.argsort(axis=1)[:, ::-1]

# print(similar_courses_indices)

top_5 = 5
recommended_courses = similar_courses_indices[0][:top_5]

recommended_course_names = df['Course Name'].iloc[recommended_courses].tolist()

print("Recommended Courses:\n")
for course in recommended_course_names:
    print(course)
