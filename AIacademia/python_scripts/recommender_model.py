# this is the file responsible for all training of the model.

import os
import django
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import joblib
import sys
import gensim
import numpy as np
from AIacademia.python_scripts.run_recommender_system import weighted_vector, vectorizer, tfidf_matrix, tfidf_matrix_prerequisites, prerequisites_vectorizer, feature_names, feature_names_for_prerequisites, df
from prepare_recommender_dataset import preprocess_text
from scipy.sparse import hstack


# Loading Word2Vec model
model = gensim.models.KeyedVectors.load_word2vec_format(r"C:\Users\Simon\proacted\GoogleNews-vectors-negative300.bin", binary=True)


# these are hashed because they are already stored in the joblib file, no need to initialise them over


# Convert course descriptions and prerequisites to weighted vectors
course_vectors = np.array([weighted_vector(desc, tfidf_matrix[i].toarray()[0], model, feature_names) for i, desc in enumerate(df['Combined Info'])])
prerequisites_vectors = np.array([weighted_vector(prereq, tfidf_matrix_prerequisites[i].toarray()[0], model, feature_names_for_prerequisites) for i, prereq in enumerate(df['Prerequisites'])])

# saving the files in joblib, once
joblib.dump(vectorizer, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_vectorizer.pkl')
joblib.dump(prerequisites_vectorizer, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_prerequisites_vectorizer.pkl')
joblib.dump(tfidf_matrix, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix.pkl')
joblib.dump(tfidf_matrix_prerequisites, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\tfidf_matrix_prerequisites.pkl')
joblib.dump(course_vectors, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\course_vectors.pkl')
joblib.dump(prerequisites_vectors, r'C:\Users\Simon\proacted\AIacademia\trained_models_recommender\prerequisites_vectors.pkl')
print("\n\ndone with storing the pkl files\n")


