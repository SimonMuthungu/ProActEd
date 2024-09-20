import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from sklearn.feature_extraction.text import TfidfVectorizer


# Function to convert user input into Word2Vec vectors weighted by TF-IDF scores
def clustered_weighted_vector(user_text, model, tfidf_vectorizer, num_clusters=7):
    words = user_text.split()
    tfidf_scores = tfidf_vectorizer.transform([user_text]).toarray()[0]
    feature_names = tfidf_vectorizer.get_feature_names_out()

    # Generate word vectors
    word_vectors = [model[word] * tfidf_scores[feature_names.tolist().index(word)] 
                    for word in words if word in model.key_to_index and word in feature_names]

    if not word_vectors:  # Handling case with no words found
        print("no words the user used are in the tfidf. consider using combined descriptions' tfidf for a more comprehensive plethora ") 
        return np.zeros(model.vector_size * num_clusters)

    # Clustering
    kmeans = KMeans(n_clusters=num_clusters, n_init=10)
    kmeans.fit(word_vectors)
    labels = kmeans.labels_ 

    # Concatenating cluster vectors
    concatenated_vector = np.array([])
    for cluster in range(num_clusters):
        cluster_vectors = [word_vectors[i] for i, label in enumerate(labels) if label == cluster]
        if cluster_vectors:
            cluster_center = np.mean(cluster_vectors, axis=0)
        else:
            cluster_center = np.zeros(model.vector_size)
        concatenated_vector = np.concatenate((concatenated_vector, cluster_center))

    # Padding the vector to ensure 2100 dimensions
    if concatenated_vector.shape[0] < 2100:
        padding_length = 2100 - concatenated_vector.shape[0]
        concatenated_vector = np.concatenate((concatenated_vector, np.zeros(padding_length)))

    return concatenated_vector


# creating 3 vectorizers for course description and prequisites and general info
objectives_vectorizer = TfidfVectorizer(stop_words='english')
generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
prerequisites_vectorizer = TfidfVectorizer(stop_words='english') 

import sys, os, django
 # setting up django environment to interact with django from this script
sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

 # getting courses descriptions' vectors from django dbsqlite3
from academia_app.models import Recommender_training_data_tokenized_sentences

courses = Recommender_training_data_tokenized_sentences.objects.all()


objectives_tfidf_matrix = objectives_vectorizer.fit_transform(course.course_objectives for course in courses)
generalinfoandabout__tfidf_matrix = generalinfoandabout_vectorizer.fit_transform(course.course_general_info_and_about for course in courses)