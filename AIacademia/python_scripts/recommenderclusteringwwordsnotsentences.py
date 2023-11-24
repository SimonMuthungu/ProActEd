# lets try to remove sent tokenize and see how that takes the model in terms of accuracy

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
# from run_recommender_system import weighted_vector # has to work with name == _main_
from scipy.sparse import hstack
from nltk.tokenize import word_tokenize
from sklearn.cluster import KMeans


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

health_amb = "I am deeply passionate about health and fitness. My ultimate goal is to innovate in the field of sports medicine, contributing to the well-being and peak performance of athletes. I dream of creating new therapies and nutrition plans that revolutionize how we approach physical training and recovery."
act_enj = "I've always been active in sports, particularly enjoying soccer and swimming. On weekends, I volunteer as a coach for a local youth sports team, teaching them the basics of teamwork and physical fitness. I also spend a lot of time reading about nutrition and experimenting with healthy recipes."

amb_tech = "I aspire to be at the forefront of technological innovation, particularly in the realm of user experience design. My ambition is to design digital products that are not only technically efficient but also user-friendly and accessible to all. Integrating aesthetics with functionality is my ultimate design philosophy."
tech_acte = "I love coding, especially working on website design. I often participate in online hackathons and enjoy the challenge of creating functional web apps under time constraints. In my free time, I dabble in graphic design, creating digital art and experimenting with various design software."



# getting a bigger user profile from they themselves
user_interests = preprocess_text(amb_tech)
# user_subjects = preprocess_text(user_subjects)
activities_enjoyed = preprocess_text(tech_acte)



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
                 "combinedprereqandabout": preprocess_text(course.Course_general_info_and_about),
                 "Prerequisites": preprocess_text(course.General_prereuisites)} for course in all_courses]

df = pd.DataFrame(courses_list)


# creating 2 vectorizers for course description and prequisites
objectives_vectorizer = TfidfVectorizer(stop_words='english')
generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
combinedvectorizer = TfidfVectorizer(stop_words='english')
# prerequisites_vectorizer = TfidfVectorizer(stop_words='english') #use case halted for the moment
objectives_tfidf_matrix = objectives_vectorizer.fit_transform(df['Course Objectives'])
generalinfoandabout__tfidf_matrix = generalinfoandabout_vectorizer.fit_transform(df['Course_general_info_and_about'])
combinedvectorizer_tfidfmatrix = combinedvectorizer.fit_transform(df['combinedprereqandabout'])
# prerequisites_tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


objectives_feature_names = objectives_vectorizer.get_feature_names_out()
feature_names_for_generalinfoandabout = generalinfoandabout_vectorizer.get_feature_names_out()
# feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()  #use case halted for the moment


# Loading Word2Vec model
model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


# Tokenize sentences in course objectives and general info
df['Tokenized Objectives'] = df['Course Objectives'].apply(word_tokenize)
df['Tokenized General Info'] = df['Course_general_info_and_about'].apply(word_tokenize)
print('\n\n\nSent tokenize... Done!\n')


# Function to vectorize sentences using Word2Vec and calculate their weighted average
def vectorize_sentences(sentences, model, tfidf_vectorizer): # needs to now use words, not sentences
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

# Vectorize each sentence -> word
df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))
df['Vectorized General Info'] = df['Tokenized General Info'].apply(lambda x: vectorize_sentences(x, model, generalinfoandabout_vectorizer))
# Display the DataFrame sorted by combined similarity scores
print("DataFrame head:\n", df.head())
excel_file_path = r'C:\Users\Simon\proacted\AIacademia\data_files\coursevectorstobeginat.xlsx'
df.to_excel(excel_file_path, index=False, engine='openpyxl')
print('Vectorize sentences... Done!\n') 


# function for clustering the sentences
def cluster_sentences(vectors, num_clusters=8):
    # Create an array to store the cluster labels
    cluster_labels = np.zeros(len(vectors), dtype=int)

    # If there are no vectors, return an empty array
    if len(vectors) == 0:
        return cluster_labels

    # If there are fewer sentences than the desired number of clusters
    if len(vectors) < num_clusters:
        # Assign each sentence to a separate cluster
        for i in range(len(vectors)):
            cluster_labels[i] = i
    else:
        # Fit KMeans clustering
        kmeans = KMeans(n_clusters=num_clusters, n_init=10)
        kmeans.fit(vectors)
        cluster_labels = kmeans.labels_

    return cluster_labels


# Apply clustering to vectorized sentences
df['Objective Clusters'] = df['Vectorized Objectives'].apply(lambda x: cluster_sentences(x))
df['General Info Clusters'] = df['Vectorized General Info'].apply(lambda x: cluster_sentences(x))
print('Sentences clusterised... Done!\n')


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

    # padding with zero for cosine calculation
    if concatenated_vector.shape[0] < 2400:
        padding_length = 2400 - concatenated_vector.shape[0]
        concatenated_vector = np.concatenate((concatenated_vector, np.zeros(padding_length)))

    return concatenated_vector


# Applying the function to the DataFrame
df['Concatenated Max Pooled Vectors'] = df.apply(lambda row: concatenate_max_pooled_vectors(row['Vectorized Objectives'], row['Objective Clusters']), axis=1)
df['Concatenated Max Pooled General Info'] = df.apply(lambda x: concatenate_max_pooled_vectors(x['Vectorized General Info'], x['General Info Clusters']), axis=1)
print('Poling and concatenation... Done!\n')
# have left out so as to focus first on the first 2 columns
# df['Pooled Prerequisites'] = df.apply(lambda x: avg_pooling(x['Vectorized General Info'], x['General Info Clusters']), axis=1)


# Function to convert user input into Word2Vec vectors weighted by TF-IDF scores
def clustered_weighted_vector(user_text, model, tfidf_vectorizer, num_clusters=8):
    words = user_text.split()
    tfidf_scores = tfidf_vectorizer.transform([user_text]).toarray()[0]
    feature_names = tfidf_vectorizer.get_feature_names_out()

    # Generate word vectors
    word_vectors = [model[word] * tfidf_scores[feature_names.tolist().index(word)] 
                    for word in words if word in model.key_to_index and word in feature_names]

    if not word_vectors:  # Handling case with no words found
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

    # Padding the vector to ensure 900 dimensions
    if concatenated_vector.shape[0] < 2400:
        padding_length = 2400 - concatenated_vector.shape[0]
        concatenated_vector = np.concatenate((concatenated_vector, np.zeros(padding_length)))

    return concatenated_vector




# vectorizing student input from UI
# embedding student input for interests and subjects, this will come from ui input
vectorized_user_interests = clustered_weighted_vector(user_interests, model, combinedvectorizer)
vectorized_activities_enjoyed = clustered_weighted_vector(activities_enjoyed, model, combinedvectorizer)
print('User input vectorization... Done!\n')


# Example cosine similarity calculation
def calculate_similarity(user_vector, course_vectors):
    return [cosine_similarity([user_vector], [course_vector])[0][0] for course_vector in course_vectors]


Objective_Similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Max Pooled Vectors'].tolist())
General_Info_Similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Max Pooled General Info'].tolist())
combined_total_similarity = np.array(Objective_Similarity) * 0.60 + np.array(General_Info_Similarity) * 0.40
# df['Prerequisites similarity'] = calculate_similarity(user_tfidf_prerequisites, df['Pooled General Info'])

print(combined_total_similarity.shape)

# Create a DataFrame to display course names with their corresponding similarity scores
similarity_df = pd.DataFrame({
    'Course Name': df['Course Name'],
    'Combined Similarity': combined_total_similarity
})

# Display the DataFrame sorted by combined similarity scores
# excel_file_path = r'C:\Users\Simon\proacted\AIacademia\data_files\similarity_scores_courses.xlsx'
# similarity_df.to_excel(excel_file_path, index=False, engine='openpyxl')
# print(similarity_df.sort_values(by='Combined Similarity', ascending=False))


top_5_indices = combined_total_similarity.argsort()[-5:][::-1]
top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 
for index in top_5_indices:
    print(f"Course: {df.iloc[index]['Course Name']}, Score: {combined_total_similarity[index]}")



# printing them, or returning to a view
print('\n\n\n|-------------------Courses we think would be best for you based on your interests:-----------------|\n\n')
for course in top_5_courses:
    print(f'|                  {course}.')
print('\n\n|----------------------THANKS, THIS IS PRO-ACT-ED 1.2-------------------------------------------------|\n\n\n')

