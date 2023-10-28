import os
import django
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import joblib
import sys
import gensim
import numpy as np
from prepare_recommender_dataset import preprocess_text
from scipy.sparse import hstack


# setting up django environment to interact with django from this script
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# getting courses from django dbsqlite3 and making them into a df
from academia_app.models import Course_data_for_recommender
all_courses = Course_data_for_recommender.objects.all()
courses_list = [{"Course Name": course.Course_name,
                 "Combined Info": course.Course_Objectives + " " + course.Course_General_Info_and_About,
                 "Prerequisites": course.Prerequisites} for course in all_courses]

df = pd.DataFrame(courses_list)


# Loading Word2Vec model
model = gensim.models.KeyedVectors.load_word2vec_format('path_to_Word2Vec_model.bin', binary=True)


# creating 2 vectorizers for course description and prequisites
vectorizer = TfidfVectorizer(stop_words='english')
prerequisites_vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = vectorizer.fit_transform(df['Combined Info'])
tfidf_matrix_prerequisites = prerequisites_vectorizer.fit_transform(df['Prerequisites'])
feature_names = vectorizer.get_feature_names_out()
feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out() 


# Function to convert text into Word2Vec vectors weighted by TF-IDF scores
def weighted_vector(text, tfidf_scores, model):
    words = [word for word in text.split() if word in model.vocab and word in feature_names]
    if not words:
        return np.zeros(model.vector_size)
    vectors = np.array([model[word] * tfidf_scores[feature_names.index(word)] for word in words])
    return sum(vectors) / len(vectors)


# Convert course descriptions and prerequisites to weighted vectors
course_vectors = np.array([weighted_vector(desc, tfidf_matrix[i].toarray()[0], model) for i, desc in enumerate(df['Combined Info'])])
prerequisites_vectors = np.array([weighted_vector(prereq, tfidf_matrix[i].toarray()[0], model) for i, prereq in enumerate(df['Prerequisites'])])


# embedding student input for interests and subjects, this will come from ui input
student_vector_for_interests = weighted_vector("technology", tfidf_matrix.transform(["technology"]).toarray()[0], model)
student_vector_for_subjects = weighted_vector("mathematics", tfidf_matrix.transform(["mathematics"]).toarray()[0], model)


# Calculate cosine similarities
interestvscoursedescription_similarities = cosine_similarity([student_vector_for_interests], course_vectors) 
interestvsprerequisite_similarities = cosine_similarity([student_vector_for_subjects], prerequisites_vectors) 
combined_total_similarity = (0.67 * interestvscoursedescription_similarities) + (0.33 * interestvsprerequisite_similarities)


# Get top 3 recommended courses
top_3_indices = combined_total_similarity[0].argsort()[-3:][::-1] 
top_3_courses = df['Course Name'].iloc[top_3_indices].tolist() 


# printing them, or returning to a view
print("\nRecommended Courses based on Combined Info:\n")
for course in top_3_courses:
    print(course)
