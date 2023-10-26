# implementation of the recommender system

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import joblib


path_to_data = r'C:\Users\Simon\proacted\AIacademia\data_files\gpt4_recommender_gen_training_data.xlsx'
df = pd.read_excel(path_to_data)


# tfidf_vectorizer = TfidfVectorizer()


# # # vectorizing the Course Objectives column
# tfidf_matrix = tfidf_vectorizer.fit_transform(df['Course Objectives'])


# # # saving the vectorized matrix into a file
# joblib.dump(tfidf_matrix, r"C:\Users\Simon\proacted\AIacademia\trained_models\matrix2.joblib") 
# joblib.dump(tfidf_vectorizer, r"C:\Users\Simon\proacted\AIacademia\trained_models\vectorizer2.joblib") 

matrix = joblib.load(r"C:\Users\Simon\proacted\AIacademia\trained_models\matrix.joblib")
vectorizer = joblib.load(r"C:\Users\Simon\proacted\AIacademia\trained_models\vectorizer.joblib")


student_interests = "i love farming"
student_profile = vectorizer.transform([student_interests])


# calculating cosine similarities b2n the dataset and student interests, and give an array
similarities = cosine_similarity(student_profile, matrix)


similar_courses_indices = similarities.argsort(axis=1)[:, ::-1]



top_5 = 5
recommended_courses = similar_courses_indices[0][:top_5]


recommended_course_names = df['Course Name'].iloc[recommended_courses].tolist()


print("\nRecommended Courses:\n")
for course in recommended_course_names:
    print(course)