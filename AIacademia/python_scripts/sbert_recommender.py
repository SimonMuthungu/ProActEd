import time
import os
import sys
import django
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from sentence_transformers import SentenceTransformer



starttime = time.time()

print("Loading s-model")
local_model_path = os.path.abspath('../../proacted_googleds/sbert_files') 
print(f"local model path: {local_model_path}")
print("Contents of the model directory:", os.listdir(local_model_path))
os.environ["TRANSFORMERS_OFFLINE"] = "1"
os.environ["TRANSFORMERS_CACHE"] = local_model_path


import sentence_transformers
print(f"sbert version: {sentence_transformers.__version__}")

model = SentenceTransformer('all-MiniLM-L6-v2')
print("Done loading s-model")

# Setting up Django environment
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

try:
    from academia_app.models import RecommenderSBERTVectors

    all_sbert_vectors = RecommenderSBERTVectors.objects.all()

    combined_scores = []

    for sbert_vector in all_sbert_vectors:
        course_name = sbert_vector.course_name
        description_embedding_bytes = bytes.fromhex(sbert_vector.description_embedding)
        objectives_embedding_bytes = bytes.fromhex(sbert_vector.objectives_embedding)

        # Convert bytes back to NumPy arrays
        description_embedding_array = np.frombuffer(description_embedding_bytes, dtype=np.float64).reshape(1, -1)
        objectives_embedding_array = np.frombuffer(objectives_embedding_bytes, dtype=np.float64).reshape(1, -1)

        # user input embedding
        user_query = "I have a deep interest in health and fitness, focusing on nutrition, exercise, and mental well-being. My goal is to understand the science behind physical fitness and to apply this knowledge in developing holistic health programs. I am keen on exploring the psychological aspects of fitness and how they intersect with physical health, aiming to promote a balanced lifestyle."

        Activitiesenjoyedbyuser = "I regularly engage in various physical activities like yoga, running, and weight training. I enjoy preparing nutritious meals and experimenting with healthy recipes. I often participate in local fitness challenges and marathons. Additionally, I attend workshops on nutrition and mental wellness, and enjoy reading books and articles related to health and fitness. I also volunteer as a fitness coach at my local community center, helping others achieve their health goals."

        userinterest_embedding = model.encode([user_query])[0].reshape(1, -1)
        usersenjoyedactivity_embedding = model.encode([user_query])[0].reshape(1, -1) 

        # Calculate cosine similarity
        objective_similarity = cosine_similarity(userinterest_embedding, objectives_embedding_array)[0][0]
        description_similarity = cosine_similarity(usersenjoyedactivity_embedding, description_embedding_array)[0][0]

        # Combine the similarities
        combined_similarity = (objective_similarity + description_similarity) / 2

        # Append combined score with course name
        combined_scores.append((course_name, combined_similarity))

    # Sort the combined scores based on similarity
    combined_scores.sort(key=lambda x: x[1], reverse=True)

    # Retrieve the top N most similar courses
    N = 5  # Number of top courses you want
    top_course_names = [score[0] for score in combined_scores[:N]]

    print(top_course_names)

except Exception as e:
    print(f"An error occurred: {e}")

endtime = time.time()
print(f"Time taken: {endtime - starttime}")
