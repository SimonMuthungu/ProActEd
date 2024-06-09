import sys
import os

sys.path.append(r'C:\Users\Hp\Desktop\ProActEd\AIacademia') 



import logging
import os
import sys

import django
import gensim
import joblib
import numpy as np
import pandas as pd
from nltk.tokenize import sent_tokenize
# from run_recommender_system import weighted_vector # has to work with name == _main_
from sklearn.cluster import KMeans
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

logging.basicConfig(filename=r'C:\Users\Hp\Desktop\ProActEd\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')
# logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S')



def load_model(users_interests, activities_users_have_enjoyed_in_the_past):
    logging.info('Recommender model loaded and running')

    # preprocessing function from the prepare recommender
    # this is to help with the etl and pre processing of the recommender training dataset

#   import nltk
    from nltk.corpus import stopwords 
    from nltk.tokenize import word_tokenize

    # df = pd.read_excel(r"AIacademia/data_files/gpt4_recommender_gen_training_data.xlsx")

    # Download the NLTK stopwords data if not already downloaded
    # nltk.download("stopwords")
    # nltk.download("punkt")

    # Define a function to preprocess text
    def preprocess_text(text):
        # Handle empty cells
        if pd.isna(text):
            text = ""

        # Lowercasing
        text = text.lower()

        # Tokenization
        tokens = word_tokenize(text)

        # Remove stopwords
        stop_words = set(stopwords.words("english"))
        filtered_tokens = [word for word in tokens if word not in stop_words]

        # Rejoin the filtered tokens to form cleaned text
        cleaned_text = " ".join(filtered_tokens)

        return cleaned_text



    # getting a bigger user profile from they themselves
    user_interests = preprocess_text(users_interests)
    # user_subjects = preprocess_text(user_subjects)
    activities_enjoyed = preprocess_text(activities_users_have_enjoyed_in_the_past) 



    print(f'\n\nGive us a moment, as we give you our best...\n\n')
    logging.info('Processing request...')


    # setting up django environment to interact with django from this script
    sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
    django.setup()

    # getting courses from django dbsqlite3 and making them into a df
    from academia_app.models import Recommender_training_data

    all_courses = Recommender_training_data.objects.all()
    courses_list = [{"Course Name": course.course_name,
                    "Course Objectives": preprocess_text(course.course_objectives),
                    "Course_general_info_and_about":  preprocess_text(course.course_general_info_and_about),
                    "Prerequisites": preprocess_text(course.general_prerequisites)} for course in all_courses]

    df = pd.DataFrame(courses_list)

    # creating 3 vectorizers for course description and prequisites and general info
    objectives_vectorizer = TfidfVectorizer(stop_words='english')
    generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
    prerequisites_vectorizer = TfidfVectorizer(stop_words='english') 


    objectives_tfidf_matrix = objectives_vectorizer.fit_transform(df['Course Objectives'])
    generalinfoandabout__tfidf_matrix = generalinfoandabout_vectorizer.fit_transform(df['Course_general_info_and_about'])
    prerequisites_tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


    objectives_feature_names = objectives_vectorizer.get_feature_names_out()
    feature_names_for_generalinfoandabout = generalinfoandabout_vectorizer.get_feature_names_out()
    feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()  


    # Loading Word2Vec model
    model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


    # Tokenize sentences in course objectives and general info
    df['Tokenized Objectives'] = df['Course Objectives'].apply(sent_tokenize)
    df['Tokenized General Info'] = df['Course_general_info_and_about'].apply(sent_tokenize)
    # df['Tokenized General Prerequisites'] = df['Prerequisites'].apply(sent_tokenize)
    print('\n\n\nTokenized sentences!\n')




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

            # print(len(sentence_vectors)) 

        return sentence_vectors


    # Vectorize each sentence
    df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))
    df['Vectorized General Info'] = df['Tokenized General Info'].apply(lambda x: vectorize_sentences(x, model, generalinfoandabout_vectorizer))
    print('Vectorized sentences!\n')


    # function for clustering the sentence vectors into 7 clusters to produce dim 2100 vectors 
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

        return cluster_labels,


    # Apply clustering to vectorized sentences
    df['Objective Clusters'] = df['Vectorized Objectives'].apply(lambda x: pd.Series(cluster_sentences(x)))
    df['General Info Clusters'] = df['Vectorized General Info'].apply(lambda x: pd.Series(cluster_sentences(x)))
    print('Sentences clusterised!\n')


    # getting the average of what sentences in each label is saying; 10 clusters will now have 10 sentences that represent what the courses are saying

    def avg_pooling(vectors, clusters):
        pooled_vectors = []    

        for cluster in set(clusters):
            cluster_vectors = [vectors[i] for i, c in enumerate(clusters) if c == cluster]
            pooled_vectors.append(np.mean(cluster_vectors, axis=0))
        # return np.mean(pooled_vectors, axis=0)
        return pooled_vectors



    # concatenating the Avg pooled vectors to form one high dimensional vector with all disctinctions captured well
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
    print('Pooling and concatenation... Done!\n')
    print(np.array(df['Concatenated Avg Pooled General Info Vectors'][0]).shape)

    # excel_file_path = 'data_files/checkingvectors.xlsx'

    # with pd.ExcelWriter(excel_file_path, engine='openpyxl', mode='w') as writer:
    #     df['Concatenated Avg Pooled Objective Vectors'].to_excel(writer, sheet_name='Sheet1', index=False)

    print('done writing, cancel now')

    # df['Pooled Prerequisites'] = df.apply(lambda x: avg_pooling(x['Vectorized General Info'], x['General Info Clusters']), axis=1)

    from academia_app.models import Recommender_training_data_number_vectors

    for index, row in df.iterrows():

        objective_hex = row['Concatenated Avg Pooled Objective Vectors'].tobytes().hex()
        general_info_hex = row['Concatenated Avg Pooled General Info Vectors'].tobytes().hex()

        vector_record = Recommender_training_data_number_vectors(
            course_name=row['Course Name'],
            course_objectives=objective_hex,
            course_general_info_and_about=general_info_hex
        )
        vector_record.save()

    print('Number vectors saved, cancel now...')


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




    # vectorizing student input from UI : embedding student input for interests and subjects, this will come from ui input
    vectorized_user_interests = clustered_weighted_vector(user_interests, model, objectives_vectorizer)
    vectorized_activities_enjoyed = clustered_weighted_vector(activities_enjoyed, model, generalinfoandabout_vectorizer) 
    print(vectorized_user_interests)
    print(vectorized_activities_enjoyed)
    print('User input vectorization... Done!\n')


    # Example cosine similarity calculation
    def calculate_similarity(user_vector, course_vectors):
        return [cosine_similarity(np.array([user_vector]), np.array([course_vector]).reshape(1, -1))[0][0] for course_vector in course_vectors]
        # return [cosine_similarity(np.array([user_vector]), np.array([course_vector]))[0][0] for # course_vector in course_vectors]



    Userambition_courseojective_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled Objective Vectors'].tolist()) 

    Activitiesenjoyedbyuser_coursegeneralinfo_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled General Info Vectors'].tolist())

    Userambition_coursegeneralinfo_similarity = calculate_similarity(vectorized_user_interests, df['Concatenated Avg Pooled General Info Vectors'].tolist())

    Activitiesenjoyedbyuser_courseojective_similarity = calculate_similarity(vectorized_activities_enjoyed, df['Concatenated Avg Pooled Objective Vectors'].tolist())

    combined_total_similarity = np.array(Userambition_courseojective_similarity) * 0.40 + np.array(Activitiesenjoyedbyuser_coursegeneralinfo_similarity) * 0.40 + np.array(Userambition_coursegeneralinfo_similarity) * 0.10 + np.array(Activitiesenjoyedbyuser_courseojective_similarity) * 0.10
    # df['Prerequisites similarity'] = calculate_similarity(user_tfidf_prerequisites, df['Pooled General Info'])




    top_5_indices = combined_total_similarity.argsort()[-10:][::-1]
    top_5_courses = df['Course Name'].iloc[top_5_indices].tolist() 


    # Instead of printing, it returns a list 
    # print('\n\n\n|-------------------Courses we think would be best for you based on your interests:-----------------|\n\n')
    # for course in top_5_courses:
    #     print(f'|                  {course}.')
    # print('\n\n|----------------------THANKS, THIS IS PRO-ACT-ED 1.2-------------------------------------------------|\n\n\n')
        
    return top_5_courses





# this is for testing the script above, during production, it should hashed out


user_int = "I have a deep interest in health and fitness, focusing on nutrition, exercise, and mental well-being. My goal is to understand the science behind physical fitness and to apply this knowledge in developing holistic health programs. I am keen on exploring the psychological aspects of fitness and how they intersect with physical health, aiming to promote a balanced lifestyle."

activities_enjyd = "I regularly engage in various physical activities like yoga, running, and weight training. I enjoy preparing nutritious meals and experimenting with healthy recipes. I often participate in local fitness challenges and marathons. Additionally, I attend workshops on nutrition and mental wellness, and enjoy reading books and articles related to health and fitness. I also volunteer as a fitness coach at my local community center, helping others achieve their health goals."




# print(load_model(user_int, activities_enjyd))




# for the hexadecimal data, i wrote a dataframe to a database as follows: objective_hex = row['Concatenated Avg Pooled Objective Vectors'].tobytes().hex()
#         general_info_hex = row['Concatenated Avg Pooled General Info Vectors'].tobytes().hex(). Now, the data is stored in dbsqlite3 browser
