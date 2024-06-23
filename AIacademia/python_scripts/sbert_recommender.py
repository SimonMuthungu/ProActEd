def sbert_proactedrecomm2024(model, users_interests, activities_users_have_enjoyed_in_the_past, top_n=5, showtime=True):

    import logging
    import time
    import os
    import sys
    import django
    import numpy as np
    from sklearn.metrics.pairwise import cosine_similarity
    import time

    logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S') 

    starttime = time.time()


    logging.info('S-Bert 2024 Recommender Engine Initialized')
    print("started proacted 2024") 


    print("Loading s-model")
    local_model_path = os.path.abspath('../../proacted_googleds/sbert_files') 

    os.environ["TRANSFORMERS_OFFLINE"] = "1"
    # os.environ["TRANSFORMERS_CACHE"] = local_model_path

    # Setting up Django environment
    sys.path.append(r'C:\Users\Simon\proacted\AIacademia')
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
    django.setup()

    try:
        from academia_app.models import RecommenderSBERTVectors

        all_sbert_vectors = RecommenderSBERTVectors.objects.all()

        combined_scores = []
        coursescalculatedsimilarityfor = 0

        timetoencode = time.time()
        userinterest_embedding = model.encode([users_interests])[0].reshape(1, -1)
        usersenjoyedactivity_embedding = model.encode([activities_users_have_enjoyed_in_the_past])[0].reshape(1, -1) 
        encodeendtime = time.time()
        print(f"Time taken for the model to encode the user inputs: {encodeendtime - timetoencode}") 

        for sbert_vector in all_sbert_vectors:
            course_name = sbert_vector.course_name
            description_embedding_bytes = bytes.fromhex(sbert_vector.description_embedding)
            objectives_embedding_bytes = bytes.fromhex(sbert_vector.objectives_embedding)

            # Convert bytes back to NumPy arrays
            description_embedding_array = np.frombuffer(description_embedding_bytes, dtype=np.float32).reshape(1, -1)
            objectives_embedding_array = np.frombuffer(objectives_embedding_bytes, dtype=np.float32).reshape(1, -1)

            # Calculate cosine similarity
            objective_similarity = cosine_similarity(userinterest_embedding, objectives_embedding_array)[0][0]
            description_similarity = cosine_similarity(usersenjoyedactivity_embedding, description_embedding_array)[0][0]
            coursescalculatedsimilarityfor += 1

            # Combine the similarities
            combined_similarity = (objective_similarity + description_similarity) / 2

            # Append combined score with course name
            combined_scores.append((course_name, combined_similarity))

        # Sort the combined scores based on similarity
        combined_scores.sort(key=lambda x: x[1], reverse=True)

        # Retrieve the top N most similar courses
        top_course_names = [score[0] for score in combined_scores[:top_n]]

    except Exception as e:
        print(f"An error occurred: {e}")

    endtime = time.time()
    if showtime == True:
        print(f"Time taken: {endtime - starttime}")
        logging.info(f"Time taken by sbert model: {endtime - starttime}")

    return top_course_names



# This part is for testing purposes only
# user input embedding
# user_query = "I have a deep interest in health and fitness, focusing on nutrition, exercise, and mental well-being. My goal is to understand the science behind physical fitness and to apply this knowledge in developing holistic health programs. I am keen on exploring the psychological aspects of fitness and how they intersect with physical health, aiming to promote a balanced lifestyle."

# Activitiesenjoyedbyuser = "I regularly engage in various physical activities like yoga, running, and weight training. I enjoy preparing nutritious meals and experimenting with healthy recipes. I often participate in local fitness challenges and marathons. Additionally, I attend workshops on nutrition and mental wellness, and enjoy reading books and articles related to health and fitness. I also volunteer as a fitness coach at my local community center, helping others achieve their health goals."


# print(sbert_proactedrecomm2024(user_query, Activitiesenjoyedbyuser, top_n=7, showtime=False))