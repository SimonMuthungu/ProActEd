# this is to help with the etl and pre processing of the recommender training dataset

#import nltk
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
