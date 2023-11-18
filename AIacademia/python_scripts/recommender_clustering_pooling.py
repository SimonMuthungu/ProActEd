# the recommender model currently has a 40% accuracy for most courses
# this will apply pooling and clustering to help the model identify a students course even with
# a not so strong profile, ie, to be keen and accurate

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
from nltk.tokenize import sent_tokenize
from sklearn.cluster import KMeans


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
                 "Course Objectives": preprocess_text(course.Course_objectives),
                 "Course_general_info_and_about":  preprocess_text(course.Course_general_info_and_about),
                 "Prerequisites": preprocess_text(course.General_prereuisites)} for course in all_courses]

df = pd.DataFrame(courses_list)


# creating 2 vectorizers for course description and prequisites
objectives_vectorizer = TfidfVectorizer(stop_words='english')
generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
prerequisites_vectorizer = TfidfVectorizer(stop_words='english') #use case halted for the moment
objectives_tfidf_matrix = objectives_vectorizer.fit_transform(df['Course Objectives'])
generalinfoandabout__tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Course_general_info_and_about'])
prerequisites_tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


objectives_feature_names = objectives_vectorizer.get_feature_names_out()
feature_names_for_generalinfoandabout = generalinfoandabout_vectorizer.get_feature_names_out()
feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()  #use case halted for the moment


# Loading Word2Vec model
model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


# Tokenize sentences in course objectives and general info
df['Tokenized Objectives'] = df['Course Objectives'].apply(sent_tokenize)
df['Tokenized General Info'] = df['Course_general_info_and_about'].apply(sent_tokenize)


# Function to vectorize sentences using Word2Vec and calculate their weighted average
def vectorize_sentences(sentences, model, tfidf_vectorizer):
    feature_names = tfidf_vectorizer.get_feature_names_out()
    tfidf_matrix = tfidf_vectorizer.transform(sentences)

    sentence_vectors = []
    for i, sentence in enumerate(sentences):
        words = sentence.split()
        word_vectors = [model[word] for word in words if word in model.key_to_index and word in feature_names]
        word_tfidf = [tfidf_matrix[i, feature_names.tolist().index(word)] for word in words if word in model.key_to_index and word in feature_names]

        if word_vectors:
            weighted_avg_vector = np.average(word_vectors, weights=word_tfidf, axis=0)
            sentence_vectors.append(weighted_avg_vector)
        else:
            # Handle cases where none of the words in the sentence are in the model or TF-IDF feature names
            sentence_vectors.append(np.zeros(model.vector_size))

    return sentence_vectors

# Vectorize each sentence
df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))
df['Vectorized General Info'] = df['Tokenized General Info'].apply(lambda x: vectorize_sentences(x, model, generalinfoandabout_vectorizer))


# function for clustering the sentences
def cluster_sentences(vectors, num_clusters=5):
    if len(vectors) < num_clusters:
        num_clusters = len(vectors)
    kmeans = KMeans(n_clusters=num_clusters)
    kmeans.fit(vectors)
    return kmeans.labels_

# Apply clustering to vectorized sentences
df['Objective Clusters'] = df['Vectorized Objectives'].apply(lambda x: cluster_sentences(x))
df['General Info Clusters'] = df['Vectorized General Info'].apply(lambda x: cluster_sentences(x))


# now pooling (max and avg)
def max_pool_vectors_per_cluster(vectors, clusters):
    max_pooled_vectors = {}
    for cluster in set(clusters):
        cluster_vectors = [vectors[i] for i, c in enumerate(clusters) if c == cluster]
        max_pooled_vectors[cluster] = np.max(cluster_vectors, axis=0)
    return max_pooled_vectors


def avg_pooling(vectors, clusters):
    pooled_vectors = []
    for cluster in set(clusters):
        cluster_vectors = [vectors[i] for i, c in enumerate(clusters) if c == cluster]
        pooled_vectors.append(np.mean(cluster_vectors, axis=0))
    return np.mean(pooled_vectors, axis=0)

# concatenating the max pooled vectors to form one high dimensional vector with all disctinctions captures well
def concatenate_max_pooled_vectors(vectors, clusters):
    max_pooled_vectors = max_pool_vectors_per_cluster(vectors, clusters)
    concatenated_vector = np.concatenate([max_pooled_vectors[cluster] for cluster in sorted(max_pooled_vectors.keys())])
    return concatenated_vector

# Applying the function to the DataFrame
df['Concatenated Max Pooled Vectors'] = df.apply(lambda row: concatenate_max_pooled_vectors(row['Vectorized Objectives'], row['Objective Clusters']), axis=1)
df['Concatenated Max Pooled General Info'] = df.apply(lambda x: concatenate_max_pooled_vectors(x['Vectorized General Info'], x['General Info Clusters']), axis=1)

# have left out so as to focus first on the first 2 columns
# df['Pooled Prerequisites'] = df.apply(lambda x: avg_pooling(x['Vectorized General Info'], x['General Info Clusters']), axis=1)


# Example user vectorization (assuming you have vectorized the user inputs)
user_vector_objectives = objectives_vectorizer.transform([user_interests]).toarray()[0]
user_vector_general_info = generalinfoandabout_vectorizer.transform([activities_enjoyed]).toarray()[0]

# user_tfidf_prerequisites = prerequisites_vectorizer.transform(user_subjects).toarray()[0] 

# vectorizing student input from UI
vectorized_user_interests = vectorize_sentences(user_interests, model, user_vector_objectives)
vectorized_activities_enjoyed = vectorize_sentences(activities_enjoyed, model, user_vector_general_info) 


# Example cosine similarity calculation
def calculate_similarity(user_vector, course_vectors):
    return [cosine_similarity([user_vector], [course_vector])[0][0] for course_vector in course_vectors]


df['Objective Similarity'] = calculate_similarity(vectorized_user_interests, df['Concatenated Max Pooled Vectors'])
df['General Info Similarity'] = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Max Pooled General Info'])

# df['Prerequisites similarity'] = calculate_similarity(user_tfidf_prerequisites, df['Pooled General Info'])
