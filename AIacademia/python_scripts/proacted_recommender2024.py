# This is the final proacted recommender system

import time

starttime = time.time()
import logging
import os
import sys

import django
import joblib
from .dependeciesforrecomm2024 import clustered_weighted_vector
from .dependeciesforrecomm2024 import objectives_vectorizer, generalinfoandabout_vectorizer
import numpy as np
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity

from .dependeciesforrecomm2024 import (clustered_weighted_vector,
                                       generalinfoandabout_vectorizer,
                                       objectives_vectorizer)

# logging.basicConfig(filename=r'C:\Users\Hp\Desktop\ProActEd\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S') 

# C:\Users\Hp\Desktop\ProActEd\AIacademia\mainlogfile.log
logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S') 
# logging.basicConfig(filename=r'C:\Users\user\Desktop\ProActEd\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S') 


def proacted2024(users_interests, activities_users_have_enjoyed_in_the_past, top_n=5, showtime=True):

    logging.info('Pro-Act-Ed 2024 Recommender Engine Initialized')
    print("started proacted 2024")


    # setting up django environment to interact with django from this script
    sys.path.append(r'C:\Users\Hp\Desktop\ProActEd\AIacademia') 
    # sys.path.append(r'C:\Users\user\Desktop\ProActEd\AIacademia') 
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
    django.setup()


    # getting courses descriptions' vectors from django dbsqlite3
    from academia_app.models import Recommender_training_data_number_vectors
    print("Imported records from db")

    all_courses = Recommender_training_data_number_vectors.objects.all()

    
    print("Loading word2vec...")
    # Loading the model, download the word2Vec binary file and specify its location here
    model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')
    # model = joblib.load(r'C:\Users\HP\Desktop\word2vec_model.pkl')
    # model = joblib.load(r'C:\Users\user\Desktop\word2vec_model.pkl')
    print('Done loading word2vec')


    # vectorizing student input from the UI
    print("Vectorizing student input")
    vectorized_user_interests = clustered_weighted_vector(users_interests, model, objectives_vectorizer)
    vectorized_activities_enjoyed = clustered_weighted_vector(activities_users_have_enjoyed_in_the_past, model, generalinfoandabout_vectorizer)
    print("vectorized all student input")

    vectorized_user_interests_2d = vectorized_user_interests.reshape(1, -1)
    vectorized_activities_enjoyed_2d = vectorized_activities_enjoyed.reshape(1, -1)

    print('Successfully vectorized and reshaped student input...')
    print(f"vectorized_user_interests' shape: {vectorized_user_interests.shape}")


    # Create an empty list to store combined similarity scores and course identifiers
    combined_scores = []

    # Iterate through the courses in the database to calculate cosine similarity
    print("beginning to iterate the db for hexadecs")
    for course in all_courses:
        # Read and Deserialize the hex vectors to bytes first
        course_objectives_hex = course.course_objectives
        generalinfoandabout_hex = course.course_general_info_and_about

        # Convert hexadecimal string to bytes
        course_objectives_bytes = bytes.fromhex(course_objectives_hex)
        generalinfoandabout_bytes = bytes.fromhex(generalinfoandabout_hex)

        # Convert bytes to a NumPy array (assuming the data is stored as float64)
        course_objectives_array = np.frombuffer(course_objectives_bytes, dtype=np.float64)
        generalinfoandabout_array = np.frombuffer(generalinfoandabout_bytes, dtype=np.float64)

        # Reshape the array to the desired shape (e.g., 2100 dimensions)
        course_objectives_array = course_objectives_array.reshape((2100,))
        generalinfoandabout_array = generalinfoandabout_array.reshape((2100,))

        # Calculate cosine similarity for each vector (objectives vs student input)
        objective_similarity = cosine_similarity(vectorized_user_interests_2d, course_objectives_array.reshape(1, -1))[0][0]
        general_info_similarity = cosine_similarity(vectorized_activities_enjoyed_2d, generalinfoandabout_array.reshape(1, -1))[0][0] 

        # Combining the similarities - here were simply take the average
        combined_similarity = (objective_similarity + general_info_similarity) / 2

        # Appending the combined score and course identifier to the list
        combined_scores.append((course.course_name, combined_similarity)) 

    # Sort the combined scores in descending order based on similarity score
    combined_scores.sort(key=lambda x: x[1], reverse=True)

        
    # Recommended N courses
    top_courses = combined_scores[:top_n]

    top_course_names = [course_name for course_name, _ in top_courses]

    
    # print(f"Top {top_n} courses list: {combined_scores[:top_n]}")

    # reporting time used in mainlog file
    if showtime == True:
        endtime = time.time()
        timespent = f"time recommender model has used: {endtime - starttime}"
        print(timespent) 
        logging.info(timespent)


    return top_course_names


user_query = "I have a deep interest in health and fitness, focusing on nutrition, exercise, and mental well-being. My goal is to understand the science behind physical fitness and to apply this knowledge in developing holistic health programs. I am keen on exploring the psychological aspects of fitness and how they intersect with physical health, aiming to promote a balanced lifestyle."

Activitiesenjoyedbyuser = "I regularly engage in various physical activities like yoga, running, and weight training. I enjoy preparing nutritious meals and experimenting with healthy recipes. I often participate in local fitness challenges and marathons. Additionally, I attend workshops on nutrition and mental wellness, and enjoy reading books and articles related to health and fitness. I also volunteer as a fitness coach at my local community center, helping others achieve their health goals."

print(proacted2024(user_query, Activitiesenjoyedbyuser, top_n=5, showtime=True))
