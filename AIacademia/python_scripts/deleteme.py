# # import os
# # import django
# # import pandas as pd
# # from sklearn.feature_extraction.text import TfidfVectorizer
# # from sklearn.metrics.pairwise import cosine_similarity
# # import joblib
# # import sys
# # import gensim
# # import numpy as np
# # from prepare_recommender_dataset import preprocess_text
# # # from run_recommender_system import weighted_vector # has to work with name == _main_
# # from scipy.sparse import hstack
# # from nltk.tokenize import sent_tokenize
# # from sklearn.cluster import KMeans


# # # # setting up django environment to interact with django from this script
# # # sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
# # # os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
# # # django.setup()

# # # # getting courses from django dbsqlite3 and making them into a df
# # # from academia_app.models import Recommender_training_data
# # # all_courses = Recommender_training_data.objects.all()
# # # courses_list = [{"Course Name": course.Course_name,
# # #                  "Course Objectives": preprocess_text(course.Course_objectives),
# # #                  "Course_general_info_and_about":  preprocess_text(course.Course_general_info_and_about),
# # #                  "Prerequisites": preprocess_text(course.General_prereuisites)} for course in all_courses]

# # # df = pd.DataFrame(courses_list)


# # # # creating 2 vectorizers for course description and prequisites
# # # objectives_vectorizer = TfidfVectorizer(stop_words='english')
# # # generalinfoandabout_vectorizer = TfidfVectorizer(stop_words='english')
# # # # prerequisites_vectorizer = TfidfVectorizer(stop_words='english') #use case halted for the moment
# # # objectives_tfidf_matrix = objectives_vectorizer.fit_transform(df['Course Objectives'])
# # # generalinfoandabout__tfidf_matrix = generalinfoandabout_vectorizer.fit_transform(df['Course_general_info_and_about'])
# # # # prerequisites_tfidf_matrix = prerequisites_vectorizer.fit_transform(df['Prerequisites'])


# # # objectives_feature_names = objectives_vectorizer.get_feature_names_out()
# # # feature_names_for_generalinfoandabout = generalinfoandabout_vectorizer.get_feature_names_out()
# # # # feature_names_for_prerequisites = prerequisites_vectorizer.get_feature_names_out()  #use case halted for the moment


# # # # Loading Word2Vec model
# # # model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


# # # # Tokenize sentences in course objectives and general info
# # # df['Tokenized Objectives'] = df['Course Objectives'].apply(sent_tokenize)
# # # print('\n\n\nSent tokenize... Done!\n')


# # # # Function to vectorize sentences using Word2Vec and calculate their weighted average
# # # def vectorize_sentences(sentences, model, tfidf_vectorizer):
# # #     feature_names = tfidf_vectorizer.get_feature_names_out()
# # #     tfidf_matrix = tfidf_vectorizer.transform(sentences)

# # #     sentence_vectors = []
# # #     for i, sentence in enumerate(sentences):
# # #         words = sentence.split()
# # #         word_vectors = [model[word] for word in words if word in model.key_to_index and word in feature_names]
# # #         word_tfidf = [tfidf_matrix[i, feature_names.tolist().index(word)] for word in words if word in model.key_to_index and word in feature_names]

# # #         if word_vectors:
# # #             weighted_avg_vector = np.average(word_vectors, weights=word_tfidf, axis=0)
# # #             sentence_vectors.append(weighted_avg_vector)
# # #         else:
# # #             # Handle cases where none of the words in the sentence are in the model or TF-IDF feature names
# # #             sentence_vectors.append(np.zeros(model.vector_size))

# # #     return sentence_vectors

# # # # Vectorize each sentence
# # # df['Vectorized Objectives'] = df['Tokenized Objectives'].apply(lambda x: vectorize_sentences(x, model, objectives_vectorizer))

# # # # Display the DataFrame sorted by combined similarity scores
# # # print("DataFrame head:\n", df.head())
# # # excel_file_path = r'C:\Users\Simon\proacted\AIacademia\data_files\oneormanysentencevectors.xlsx'
# # # df.to_excel(excel_file_path, index=False, engine='openpyxl')
# # # print('Vectorize words... Done!\n') 


# # import pandas as pd
# # import os
# # import django
# # from nltk.tokenize import sent_tokenize

# # # Setting up Django environment
# # sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
# # os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
# # django.setup()

# # # Importing the model
# # from academia_app.models import Recommender_training_data

# # # Fetching courses from the database
# # all_courses = Recommender_training_data.objects.all()

# # # Creating a list to store the courses and their sentence counts
# # courses_list = []
# # for course in all_courses:
# #     course_obj = {
# #         "Course Name": course.Course_name,
# #         "Course Objectives Sentence Count": [ len(sent_tokenize(course.Course_objectives)) if len(sent_tokenize(course.Course_objectives)) < 10 else "good"],
# #         "Course General Info Sentence Count": [ len(sent_tokenize(course.Course_general_info_and_about)) if len(sent_tokenize(course.Course_general_info_and_about)) < 10 else "good" ]
# #     }
# #     courses_list.append(course_obj)

# # # Creating a DataFrame from the list
# # df = pd.DataFrame(courses_list)

# # # Displaying the DataFrame
# # excel_file_path = r'C:\Users\Simon\proacted\AIacademia\data_files\countsentencespercoursename.xlsx'
# # df.to_excel(excel_file_path, index=False, engine='openpyxl')
# # print('Vectorize words... Done!\n') 

# x = [2,3,4,33,4,53,2]
# print(len(x))



def calculate_weights():
    # Assume some criteria for calculating weights
    weight1 = 0.2
    weight2 = 0.3
    weight3 = 0.4
    weight4 = 0.1

    # Return multiple values
    return weight1, weight2, weight3, weight4

# Call the function
weights_tuple = calculate_weights()
print(type(weights_tuple))
print(weights_tuple)
# Now, you can unpack the returned values into separate variables
weight1, weight2, weight3, weight4 = weights_tuple

# Use these values as needed
print(f"Weight 1: {weight1}")
print(f"Weight 2: {weight2}")
print(f"Weight 3: {weight3}")
print(f"Weight 4: {weight4}")
