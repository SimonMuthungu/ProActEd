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

# welcome

print('\n\n--------------------------------------------------------------------------------------')
print('--------------------------------------------------------------------------------------')
print('-----------------WELCOME TO PROACTED   -----------------------------------------------')
print('--------------------------------------------------------------------------------------')
print('-----------------@PROACTED 1.1 C 2023  -----------------------------------------------')
print('--------------------------------------------------------------------------------------')
print('--------------------------------------------------------------------------------------')
print('--------------------------------------------------------------------------------------\n\n\n')
print('\n\nEnter your interests. Feel free to talk... :)\n\n')
user_interests = input()
user_subjects = input('\nAnd subjects you did in high school?\n\n')


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
# model = gensim.models.KeyedVectors.load_word2vec_format(r"C:\Users\Simon\proacted\GoogleNews-vectors-negative300.bin", binary=True)
model = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\word2vec_model.pkl')


# creating 2 vectorizers for course description and prequisites
# vectorizer = TfidfVectorizer(stop_words='english')
# prerequisites_vectorizer = TfidfVectorizer(stop_words='english')
# tfidf_matrix = vectorizer.fit_transform(df['Combined Info'])
# tfidf_matrix_prerequisites = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


# Function to convert text into Word2Vec vectors weighted by TF-IDF scores
def weighted_vector(text, tfidf_scores, model, feature_names):
    words = [word for word in text.split() if word in model.key_to_index and word in feature_names]
    if not words:
        print(f'\nfor some reason, we dont know what some words you provided mean...\n')
        return np.zeros(model.vector_size)
    feature_names = feature_names.tolist()
    vectors = np.array([model[word] * tfidf_scores[feature_names.index(word)] for word in words])
    return sum(vectors) / len(vectors)


tfidf_matrix = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix.pkl')

# Convert course descriptions and prerequisites to weighted vectors
# course_vectors = np.array([weighted_vector(desc, tfidf_matrix[i].toarray()[0], model, feature_names) for i, desc in enumerate(df['Combined Info'])])
# prerequisites_vectors = np.array([weighted_vector(prereq, tfidf_matrix_prerequisites[i].toarray()[0], model, feature_names_for_prerequisites) for i, prereq in enumerate(df['Prerequisites'])])

# saving the files in joblib
# joblib.dump(vectorizer, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_vectorizer.pkl')
# joblib.dump(prerequisites_vectorizer, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_prerequisites_vectorizer.pkl')
# joblib.dump(tfidf_matrix, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix.pkl')
# joblib.dump(tfidf_matrix_prerequisites, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix_prerequisites.pkl')
# joblib.dump(course_vectors, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\course_vectors.pkl')
# joblib.dump(prerequisites_vectors, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\prerequisites_vectors.pkl')
# joblib.dump(model, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\word2vec_model.pkl')

# loading them from dumped joblib file
vectorizer = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_vectorizer.pkl')
prerequisites_vectorizer = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_prerequisites_vectorizer.pkl')
tfidf_matrix_prerequisites = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix_prerequisites.pkl')
course_vectors = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\course_vectors.pkl')
prerequisites_vectors = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\prerequisites_vectors.pkl')
feature_names = vectorizer.get_feature_names_out()
feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out() 


# embedding student input for interests and subjects, this will come from ui input
student_vector_for_interests = weighted_vector(user_interests, vectorizer.transform([user_interests]).toarray()[0], model, feature_names)
student_vector_for_subjects = weighted_vector(user_subjects, prerequisites_vectorizer.transform([user_subjects]).toarray()[0], model, feature_names_for_prerequisites)


# Calculate cosine similarities
interestvscoursedescription_similarities = cosine_similarity([student_vector_for_interests], course_vectors) 
interestvsprerequisite_similarities = cosine_similarity([student_vector_for_subjects], prerequisites_vectors) 
combined_total_similarity = (0.6 * interestvscoursedescription_similarities) + (0.4* interestvsprerequisite_similarities)


# Get top 3 recommended courses
top_5_indices = combined_total_similarity[0].argsort()[-5:][::-1] 
top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 


# printing them, or returning to a view
print('\n|-------------------Courses we think would be best for you based on your interests:-----------------|\n')
for course in top_5_courses:
    print(f'|                  {course}')
print('\n|----------------------THANKS, THIS IS PRO-ACT-ED-----------------------------------------------------|\n\n\n')
