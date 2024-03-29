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

print('\n\n\n|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|')
print('|                       WELCOME TO PROACTED                                                   |')
print('|                       @ PROACTED 1.1 2023                                                   |')
print('|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|\n\n\n')

# working on building a comprehensive user profile
user_interests = input('\n\Tell us your ambition in life, what would you like to accomplish or become?:\n\n') #to be matched against objectives
user_subjects = input('\nWhich subjects did you excel at in high school?\n\n') #against course pre-requisites
activities_enjoyed = input('\ntell us of activities you have enjoyed in the past, eg debating, repairing broken radios,  \nthat might help us know youre interests better:\n\n') #general info & about


# getting a bigger user profile from they themselves
user_interests = preprocess_text(user_interests)
user_subjects = preprocess_text(user_subjects)
activities_enjoyed = preprocess_text(activities_enjoyed)

print(user_interests, '\n', user_subjects, '\n', activities_enjoyed)



print(f'\n\nGive us a moment, as we give you our best...\n\n')


# setting up django environment to interact with django from this script
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# getting courses from django dbsqlite3 and making them into a df
from academia_app.models import Recommender_training_data
all_courses = Recommender_training_data.objects.all()
courses_list = [{"Course Name": course.Course_name,
                 "Combined Info": preprocess_text(course.Course_objectives) + " " + preprocess_text(course.Course_general_info_and_about),
                 "Prerequisites": preprocess_text(course.General_prereuisites)} for course in all_courses]

df = pd.DataFrame(courses_list)
# print(df) 

# creating 2 vectorizers for course description and prequisites
vectorizer = TfidfVectorizer(stop_words='english')
prerequisites_vectorizer = TfidfVectorizer(stop_words='english')
tfidf_matrix = vectorizer.fit_transform(df['Combined Info'])
tfidf_matrix_prerequisites = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


feature_names = vectorizer.get_feature_names_out()
feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()

# Loading Word2Vec model
model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')

# Function to convert text into Word2Vec vectors weighted by TF-IDF scores
def weighted_vector(text, tfidf_scores, model, feature_names):
    words = [word for word in text.split() if word in model.key_to_index and word in feature_names]
    if not words:
        print(f'\nfor some reason, we dont know what some words you provided mean...\n')
        return np.zeros(model.vector_size)
    feature_names = feature_names.tolist()
    vectors = np.array([model[word] * tfidf_scores[feature_names.index(word)] for word in words])
    return sum(vectors) / len(vectors)

# loading them from dumped joblib file, everytime the program runs
tfidf_matrix = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix.pkl')
vectorizer = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_vectorizer.pkl')
prerequisites_vectorizer = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_prerequisites_vectorizer.pkl')
tfidf_matrix_prerequisites = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix_prerequisites.pkl')
course_vectors = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\course_vectors.pkl')
prerequisites_vectors = joblib.load(r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\prerequisites_vectors.pkl')

# embedding student input for interests and subjects, this will come from ui input
student_vector_for_interests = weighted_vector(user_interests, vectorizer.transform([user_interests]).toarray()[0], model, feature_names)
student_vector_for_subjects = weighted_vector(user_subjects, prerequisites_vectorizer.transform([user_subjects]).toarray()[0], model, feature_names_for_prerequisites)


# Calculate cosine similarities
interestvscoursedescription_similarities = cosine_similarity([student_vector_for_interests], course_vectors) 
interestvsprerequisite_similarities = cosine_similarity([student_vector_for_subjects], prerequisites_vectors) 
combined_total_similarity = (0.65 * interestvscoursedescription_similarities) + (0.35* interestvsprerequisite_similarities)


# Get top 5 recommended courses
top_5_indices = combined_total_similarity[0].argsort()[-5:][::-1] 
top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 


# printing them, or returning to a view
print('\n\n\n|-------------------Courses we think would be best for you based on your interests:-----------------|\n\n')
for course in top_5_courses:
    print(f'|                  {course}.')
print('\n\n|----------------------THANKS, THIS IS PRO-ACT-ED 1.1-------------------------------------------------|\n\n\n')
