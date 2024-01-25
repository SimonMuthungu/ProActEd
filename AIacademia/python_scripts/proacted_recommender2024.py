# This is the final proacted recommender system

import logging
import sys, os, django
import joblib
from recommender_clustering_pooling import clustered_weighted_vector, objectives_vectorizer, generalinfoandabout_vectorizer
import numpy as np
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity




logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\logfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')

def proacted2024(users_interests, activities_users_have_enjoyed_in_the_past):

    logging.info('Pro-Act-Ed 2024 Recommender Engine Initialized')


    # setting up django environment to interact with django from this script
    sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
    django.setup()


    # getting courses descriptions' vectors from django dbsqlite3
    from academia_app.models import Recommender_training_data_vectors

    all_courses = Recommender_training_data_vectors.objects.all()

    data = []

    for course in all_courses:
        course_name = course.course_name
        objective_vectors = np.frombuffer(course.course_objectives.encode('utf-8'), dtype=np.float32)
        general_info_vectors = np.frombuffer(course.course_general_info_and_about.encode('utf-8'), dtype=np.float32)

    # Extract the vectors into a list
    objective_vectors_from_db = [vector.objective_vectors for vector in course]




    
    # Loading the word2Vec model
    model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


    #loading the

    # vectorizing student input from the UI
    vectorized_user_interests = clustered_weighted_vector(users_interests, model, objectives_vectorizer)
    vectorized_activities_enjoyed = clustered_weighted_vector(activities_users_have_enjoyed_in_the_past, model, generalinfoandabout_vectorizer)


    # defining cosine similarity
    def calculate_similarity(user_vector, course_vectors):
        return [cosine_similarity(np.array([user_vector]), np.array(course_vectors))[0][0] for course_vector in course_vectors]


    Userambition_courseojective_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled Objective Vectors'].tolist()) 


                    