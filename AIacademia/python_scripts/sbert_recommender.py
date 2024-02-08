import os, sys, django
from sklearn.metrics.pairwise import cosine_similarity


from sentence_transformers import SentenceTransformer


print("Loading s-model")
local_model_path = os.path.abspath('C:/Users/Simon/proacted_googleds/sbert_files')
os.environ["TRANSFORMERS_CACHE"] = local_model_path


try:
    model = SentenceTransformer('all-MiniLM-L6-v2')
    print("Done loading s-model")
except Exception as e:
    print(f"An error occured: {e}")

# getting courses from django dbsqlite3

sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

try:
    from academia_app.models import Recommender_training_data

    all_courses = Recommender_training_data.objects.all()

    course_descriptions = [course_desc.course_general_info_and_about for course_desc in all_courses]  
    course_objectives = [course_obj.course_objectives for course_obj in all_courses]

    # Convert course descriptions to embeddings
    print("Generating embeddings for course descriptions...")
    course_generalinfo_embeddings = model.encode(course_descriptions)
    course_objectives_embeddings = model.encode(course_objectives) 
    print("Done Generating embeddings for course descriptions...")

    # user input embedding
    user_query = "I'm interested in machine learning and data science"
    Activitiesenjoyedbyuser = 'I\'m interested in machine learning and data science'
    userinterest_embedding = model.encode([user_query])[0]  
    useractivity_embedding = model.encode([Activitiesenjoyedbyuser])[0]  

    userinterest_courseobjectives_similarities = cosine_similarity(userinterest_embedding.reshape(1, -1), course_objectives_embeddings)
    Activitiesenjoyedbyuser_coursegeneralinfo_similarity = cosine_similarity(useractivity_embedding.reshape(1, -1), course_generalinfo_embeddings)

    # combinedsimilarity = 

    # Find indices of top N most similar courses
    top_indices = userinterest_courseobjectives_similarities.argsort()[0][-5:][::-1]  

    # Retrieve the top N most similar course descriptions
    top_course_descriptions = [course_descriptions[i] for i in top_indices]

    print(top_course_descriptions) 

except Exception as e:
    print(f"An error occured: {e}")
