# the recommender model currently has a 40% accuracy for most courses
# this will apply pooling and clustering to help the model identify a students course even with
# a not so strong profile, ie, to be keen and accurate

<<<<<<< HEAD
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
# from run_recommender_system import weighted_vector # has to work with name == _main_
from scipy.sparse import hstack
from nltk.tokenize import sent_tokenize
from sklearn.cluster import KMeans
import logging 


logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\logfile.log',level=logging.DEBUG, format='%(levelname)s - %(asctime)s - %(message)s', datefmt='%d-%b-%y %H:%M:%S')
=======
import logging
import os
import sys

import django
import gensim
import joblib
import numpy as np
import pandas as pd
from nltk.tokenize import sent_tokenize
from prepare_recommender_dataset import preprocess_text
# from run_recommender_system import weighted_vector # has to work with name == _main_
from scipy.sparse import hstack
from sklearn.cluster import KMeans
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

logging.basicConfig(filename=r'C:\Users\user\Desktop\ProActEd\AIacademia\logfile.log',level=logging.DEBUG, format='%(levelname)s - %(asctime)s - %(message)s', datefmt='%d-%b-%y %H:%M:%S')
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51



# welcome

print('\n\n\n|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|')
print('|                       WELCOME TO PROACTED                                                   |')
print('|                       @ PROACTED 1.2 2023                                                   |')
print('|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|')
print('|---------------------------------------------------------------------------------------------|\n\n\n')

# working on building a comprehensive user profile
# user_interests = input('\nTell us your ambition in life, what would you like to accomplish or become?:\n\n') #to be matched against objectives
# # user_subjects = input('\nWhich subjects did you excel at in high school?\n\n') #against course pre-requisites
# activities_enjoyed = input('\ntell us of activities you have enjoyed in the past, eg debating, repairing broken radios,  \nthat might help us know youre interests better:\n\n') #general info & about
print("\nTemporarily halted user input, using predefined strings!!\n")
amb = "I aspire to make a significant impact in the field of environmental conservation. My dream is to develop innovative solutions to reduce pollution and promote sustainable living practices. I am passionate about researching renewable energy sources and implementing eco-friendly technologies in urban areas to combat climate change and protect natural habitats"
act_e = "Throughout high school, I found myself deeply engrossed in activities like debating and public speaking. I enjoyed participating in debate clubs, where I honed my skills in persuasive communication and critical thinking. Additionally, I have a keen interest in technology, particularly in building and programming small electronic devices. This hobby of mine has sparked a curiosity in how technology can be leveraged to solve everyday problems."

health_amb =  "I am interested in pursuing a career in healthcare, specifically as a nurse. I want to provide care and support to patients in hospitals."
act_enj = "I volunteer at local health clinics and enjoy learning about medical sciences. In my leisure time, I read about healthcare advancements and participate in health awareness campaigns."


amb_tech = "My ambition is to delve into the world of artificial intelligence and machine learning. I aim to develop cutting-edge AI solutions that can transform industries."
tech_acte = "My ambition is to delve into the world of artificial intelligence and machine learning. I aim to develop cutting-edge AI solutions that can transform industries."



# getting a bigger user profile from they themselves
<<<<<<< HEAD
user_interests = preprocess_text(amb)
# user_subjects = preprocess_text(user_subjects)
activities_enjoyed = preprocess_text(act_e) 
=======
user_interests = preprocess_text(input("Enter User Intrests"))
# user_subjects = preprocess_text(user_subjects)
activities_enjoyed = preprocess_text(input("Activities")) 
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51



print(f'\n\nGive us a moment, as we give you our best...\n\n')


# setting up django environment to interact with django from this script
<<<<<<< HEAD
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
=======
sys.path.append(r'C:\Users\user\Desktop\ProActEd\AIacademia')
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# getting courses from django dbsqlite3 and making them into a df
from academia_app.models import Recommender_training_data
<<<<<<< HEAD
=======

>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
all_courses = Recommender_training_data.objects.all()
courses_list = [{"Course Name": course.Course_name,
                 "Course Objectives": preprocess_text(course.Course_objectives),
                 "Course_general_info_and_about":  preprocess_text(course.Course_general_info_and_about),
                 "Prerequisites": preprocess_text(course.General_prereuisites)} for course in all_courses]

df = pd.DataFrame(courses_list)
<<<<<<< HEAD

=======
print(df.head())
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

# creating 2 vectorizers for course description and prequisites
objectives_vectorizer = TfidfVectorizer(stop_words='english')
generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
# prerequisites_vectorizer = TfidfVectorizer(stop_words='english') #use case halted for the moment
objectives_tfidf_matrix = objectives_vectorizer.fit_transform(df['Course Objectives'])
generalinfoandabout__tfidf_matrix = generalinfoandabout_vectorizer.fit_transform(df['Course_general_info_and_about'])
# prerequisites_tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


objectives_feature_names = objectives_vectorizer.get_feature_names_out()
feature_names_for_generalinfoandabout = generalinfoandabout_vectorizer.get_feature_names_out()
# feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()  #use case halted for the moment


# Loading Word2Vec model
<<<<<<< HEAD
model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')
=======
#model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51


# Tokenize sentences in course objectives and general info
df['Tokenized Objectives'] = df['Course Objectives'].apply(sent_tokenize)
df['Tokenized General Info'] = df['Course_general_info_and_about'].apply(sent_tokenize)
print('\n\n\nTokenized sentences!\n')


# Function to vectorize sentences using Word2Vec and calculate their weighted average
def vectorize_sentences(sentences, model, tfidf_vectorizer):
    feature_names = tfidf_vectorizer.get_feature_names_out()
    tfidf_matrix = tfidf_vectorizer.transform(sentences)

    sentence_vectors = []
    for i, sentence in enumerate(sentences):
        words = sentence.split()
        word_vectors = [model[word] for word in words if word in model.key_to_index and word in feature_names]
<<<<<<< HEAD
        word_tfidf = [tfidf_matrix[i, feature_names.tolist().index(word)] for word in words if word in model.key_to_index and word in feature_names] 
=======
        word_tfidf = [tfidf_matrix[i, feature_names.tolist().index(word)] for word in words if word in model.key_to_index and word in feature_names]
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

        if word_vectors:
            weighted_avg_vector = np.average(word_vectors, weights=word_tfidf, axis=0)
            sentence_vectors.append(weighted_avg_vector)

        else:
            # Handle cases where none of the words in the sentence are in the model or TF-IDF feature names
            sentence_vectors.append(np.zeros(model.vector_size))

<<<<<<< HEAD
        # print(len(sentence_vectors)) 
=======
        # print(len(sentence_vectors))
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

    return sentence_vectors

# Vectorize each sentence
<<<<<<< HEAD
df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))
df['Vectorized General Info'] = df['Tokenized General Info'].apply(lambda x: vectorize_sentences(x, model, generalinfoandabout_vectorizer))
print('Vectorized sentences!\n')


# function for clustering the sentence vectors into 10 clusters to produce dim 2100 vectors 
=======
# df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))
# df['Vectorized General Info'] = df['Tokenized General Info'].apply(lambda x: vectorize_sentences(x, model, generalinfoandabout_vectorizer))
# print('Vectorized sentences!\n')


# function for clustering the sentence vectors into 10 clusters to produce dim 2100 vectors
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
def cluster_sentences(vectors, num_clusters=7):
    # Create an array to store the cluster labels
    cluster_labels = np.zeros(len(vectors), dtype=int)

    # If there are no vectors, return an empty array
    if len(vectors) == 0:
        logging.info(f'line 136: len(vectors) == 0 meaning some sentence somewhere doesnt exist when it should')
        return cluster_labels


    # If there are fewer sentences than the desired number of clusters
    # if len(vectors) < num_clusters:
    #     # Assign each sentence to a separate cluster
    #     for i in range(len(vectors)):
    #         cluster_labels[i] = i


    else:
        # Fit KMeans clustering
        kmeans = KMeans(n_clusters=num_clusters, n_init=5)
        kmeans.fit(vectors)
        cluster_labels = kmeans.labels_

    return cluster_labels


# Apply clustering to vectorized sentences
df['Objective Clusters'] = df['Vectorized Objectives'].apply(lambda x: cluster_sentences(x))
df['General Info Clusters'] = df['Vectorized General Info'].apply(lambda x: cluster_sentences(x))
print('Sentences clusterised!\n')


# # now pooling (Avg and avg)
# def Avg_pool_vectors_per_cluster(vectors, clusters):
#     Avg_pooled_vectors = {}
#     for cluster in set(clusters):
#         cluster_vectors = [vectors[i] for i, c in enumerate(clusters) if c == cluster]
#         Avg_pooled_vectors[cluster] = np.Avg(cluster_vectors, axis=0)
#     return Avg_pooled_vectors


# getting the average of what sentences in each label is saying; 10 clusters will now have 10 sentences that represent what the courses are saying


def avg_pooling(vectors, clusters):
<<<<<<< HEAD
    pooled_vectors = []    
=======
    pooled_vectors = []
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

    for cluster in set(clusters):
        cluster_vectors = [vectors[i] for i, c in enumerate(clusters) if c == cluster]
        pooled_vectors.append(np.mean(cluster_vectors, axis=0))
    # return np.mean(pooled_vectors, axis=0)
    return pooled_vectors



# concatenating the Avg pooled vectors to form one high dimensional vector with all disctinctions captures well
def concatenate_avg_pooled_vectors(vectors, clusters):
    avg_pooled_vectors = avg_pooling(vectors, clusters)
    concatenated_vector = np.concatenate(avg_pooled_vectors) 

    # padding with zero for cosine calculation
    if concatenated_vector.shape[0] < 2100:
        print("Were padding due to dim < 2100")
        padding_length = 2100 - concatenated_vector.shape[0]
        concatenated_vector = np.concatenate((concatenated_vector, np.zeros(padding_length)))

    return concatenated_vector


# Applying the function to the DataFrame
df['Concatenated Avg Pooled Objective Vectors'] = df.apply(lambda row: concatenate_avg_pooled_vectors(row['Vectorized Objectives'], row['Objective Clusters']), axis=1)
df['Concatenated Avg Pooled General Info Vectors'] = df.apply(lambda x: concatenate_avg_pooled_vectors(x['Vectorized General Info'], x['General Info Clusters']), axis=1)
print('Poling and concatenation... Done!\n')


# have left out so as to focus first on the first 2 columns
# df['Pooled Prerequisites'] = df.apply(lambda x: avg_pooling(x['Vectorized General Info'], x['General Info Clusters']), axis=1)


# Function to convert user input into Word2Vec vectors weighted by TF-IDF scores
def clustered_weighted_vector(user_text, model, tfidf_vectorizer, num_clusters=7):
    words = user_text.split()
    tfidf_scores = tfidf_vectorizer.transform([user_text]).toarray()[0]
    feature_names = tfidf_vectorizer.get_feature_names_out()

    # Generate word vectors
<<<<<<< HEAD
    word_vectors = [model[word] * tfidf_scores[feature_names.tolist().index(word)] 
                    for word in words if word in model.key_to_index and word in feature_names]

    if not word_vectors:  # Handling case with no words found
        print("no words the user used are in the tfidf. consider using combined descriptions' tfidf for a more comprehensive plethora ") 
=======
    word_vectors = [model[word] * tfidf_scores[feature_names.tolist().index(word)]
                    for word in words if word in model.key_to_index and word in feature_names]

    if not word_vectors:  # Handling case with no words found
        print("no words the user used are in the tfidf. consider using combined descriptions' tfidf for a more comprehensive plethora ")
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
        return np.zeros(model.vector_size * num_clusters)

    # Clustering
    kmeans = KMeans(n_clusters=num_clusters, n_init=10)
    kmeans.fit(word_vectors)
<<<<<<< HEAD
    labels = kmeans.labels_ 
=======
    labels = kmeans.labels_
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

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




# vectorizing student input from UI : embedding student input for interests and subjects, this will come from ui input
<<<<<<< HEAD
vectorized_user_interests = clustered_weighted_vector(user_interests, model, objectives_vectorizer)
vectorized_activities_enjoyed = clustered_weighted_vector(activities_enjoyed, model, generalinfoandabout_vectorizer)
print('User input vectorization... Done!\n')
=======
# vectorized_user_interests = clustered_weighted_vector(user_interests, model, objectives_vectorizer)
# vectorized_activities_enjoyed = clustered_weighted_vector(activities_enjoyed, model, generalinfoandabout_vectorizer)
# print('User input vectorization... Done!\n')
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51


# Example cosine similarity calculation
def calculate_similarity(user_vector, course_vectors):
    return [cosine_similarity([user_vector], [course_vector])[0][0] for course_vector in course_vectors]


<<<<<<< HEAD
Userambition_courseojective_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled Objective Vectors'].tolist()) 

Activitiesenjoyedbyuser_coursegeneralinfo_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled General Info Vectors'].tolist())

Userambition_coursegeneralinfo_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled General Info Vectors'].tolist())

Activitiesenjoyedbyuser_courseojective_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled Objective Vectors'].tolist())

combined_total_similarity = np.array(Userambition_courseojective_similarity) * 0.30 + np.array(Activitiesenjoyedbyuser_coursegeneralinfo_similarity) * 0.50 + np.array(Userambition_coursegeneralinfo_similarity) * 0.10 + np.array(Activitiesenjoyedbyuser_courseojective_similarity) * 0.10
# df['Prerequisites similarity'] = calculate_similarity(user_tfidf_prerequisites, df['Pooled General Info'])

print(combined_total_similarity.shape)
=======
# Userambition_courseojective_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled Objective Vectors'].tolist()) 

# Activitiesenjoyedbyuser_coursegeneralinfo_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled General Info Vectors'].tolist())

# Userambition_coursegeneralinfo_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled General Info Vectors'].tolist())

# Activitiesenjoyedbyuser_courseojective_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled Objective Vectors'].tolist())

# combined_total_similarity = np.array(Userambition_courseojective_similarity) * 0.30 + np.array(Activitiesenjoyedbyuser_coursegeneralinfo_similarity) * 0.50 + np.array(Userambition_coursegeneralinfo_similarity) * 0.10 + np.array(Activitiesenjoyedbyuser_courseojective_similarity) * 0.10
# df['Prerequisites similarity'] = calculate_similarity(user_tfidf_prerequisites, df['Pooled General Info'])

# print(combined_total_similarity.shape)
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51

# Create a DataFrame to display course names with their corresponding similarity scores
similarity_df = pd.DataFrame({
    'Course Name': df['Course Name'],
<<<<<<< HEAD
    'Combined Similarity': combined_total_similarity
=======
    # 'Combined Similarity': combined_total_similarity
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
})

# Display the DataFrame sorted by combined similarity scores
excel_file_path = r'C:\Users\Simon\proacted\AIacademia\data_files\similarity_scores_courses.xlsx'
similarity_df.to_excel(excel_file_path, index=False, engine='openpyxl')
# print(similarity_df.sort_values(by='Combined Similarity', ascending=False))


<<<<<<< HEAD
top_5_indices = combined_total_similarity.argsort()[-5:][::-1]
top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 
for index in top_5_indices:
    print(f"Course: {df.iloc[index]['Course Name']}, Score: {combined_total_similarity[index]}")
=======
# top_5_indices = combined_total_similarity.argsort()[-5:][::-1]
# top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 
# for index in top_5_indices:
#     print(f"Course: {df.iloc[index]['Course Name']}, Score: {combined_total_similarity[index]}")
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51



# printing them, or returning to a view
print('\n\n\n|-------------------Courses we think would be best for you based on your interests:-----------------|\n\n')
<<<<<<< HEAD
for course in top_5_courses:
    print(f'|                  {course}.')
=======
# for course in top_5_courses:
    # print(f'|                  {course}.')
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
print('\n\n|----------------------THANKS, THIS IS PRO-ACT-ED 1.2-------------------------------------------------|\n\n\n')

