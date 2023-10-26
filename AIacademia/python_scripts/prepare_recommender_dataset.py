# this is to help with the etl and pre processing of the recommender training dataset

import pandas as pd
import nltk
from nltk.corpus import stopwords 
from nltk.tokenize import word_tokenize

df = pd.read_excel(r"AIacademia/data_files/gpt4_recommender_gen_training_data.xlsx")

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

columns_to_preprocess = ["Course Objectives", "Course General Info and About", "General Prequisites", "Subject Prequisites"]

# Apply text pre-processing to specified columns
for column in columns_to_preprocess:
    df[column] = df[column].apply(preprocess_text) 

# Save the preprocessed data
df.to_excel(r"AIacademia/data_files/gpt4_recommender_gen_training_data_preprocessed.xlsx", index=False)