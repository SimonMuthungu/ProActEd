if __name__ == 'main': 
    # This is the final proacted recommender system

    import logging
    import sys, os, django
    import joblib
    from dependeciesforrecomm2024 import clustered_weighted_vector
    from dependeciesforrecomm2024 import objectives_vectorizer, generalinfoandabout_vectorizer
    import numpy as np
    import pandas as pd
    from sklearn.metrics.pairwise import cosine_similarity




    logging.basicConfig(filename=r'C:\Users\Simon\proacted\AIacademia\mainlogfile.log',level=logging.DEBUG, format='%(levelname)s || %(asctime)s || %(message)s', datefmt='%d-%b-%y %H:%M:%S') 

    def proacted2024(users_interests, activities_users_have_enjoyed_in_the_past):

        logging.info('Pro-Act-Ed 2024 Recommender Engine Initialized')


        # setting up django environment to interact with django from this script
        sys.path.append(r'C:\Users\Simon\proacted\AIacademia') 
        os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
        django.setup()


        # getting courses descriptions' vectors from django dbsqlite3
        from academia_app.models import Recommender_training_data_number_vectors

        all_courses = Recommender_training_data_number_vectors.objects.all()

        
        # Loading the word2Vec model
        model = joblib.load(r'C:\Users\Simon\proacted_googleds\word2vec_model.pkl')


        # vectorizing student input from the UI
        vectorized_user_interests = clustered_weighted_vector(users_interests, model, objectives_vectorizer)
        # vectorized_activities_enjoyed = clustered_weighted_vector(activities_users_have_enjoyed_in_the_past, model, generalinfoandabout_vectorizer)
        print('Successfully vectorized student input...')
        logging.info('Successfully vectorized student input...')
        print(f"vectorized_user_interests' shape: {vectorized_user_interests.shape}")


        # Iterate through the courses in the database to calculate cosine similarity
        for course in all_courses:
            # Read and Deserialize the hex vectors to bytes first
            course_objectives_hex = course.course_objectives

            # Convert hexadecimal string to bytes
            course_objectives_bytes = bytes.fromhex(course_objectives_hex)

            # Convert bytes to a NumPy array (assuming the data is stored as float64)
            course_objectives_array = np.frombuffer(course_objectives_bytes, dtype=np.float64)

            # Reshape the array to the desired shape (e.g., 2100 dimensions)
            course_objectives_array = course_objectives_array.reshape((2100,))


            # now with the vector representing this course, we want to calculate cosine similarity
            # between the users inputs and this course's vector
            vectorized_user_interests_matrix = np.array([vectorized_user_interests])
            objective_vector_matrix = np.array([objective_vector])

            # Calculate cosine similarity for each vector
            objective_similarity = cosine_similarity(vectorized_user_interests_matrix, objective_vector_matrix)[0][0]
            # general_info_similarity = cosine_similarity(vectorized_activities_enjoyed, general_info_vector)[0][0]

            print(objective_similarity)


    user_int = "I am dedicated to making a meaningful contribution to the realm of education and learning. My goal is to revolutionize traditional teaching methods and enhance access to quality education for all. I am enthusiastic about exploring innovative technologies and digital tools to create engaging and interactive learning experiences. I aspire to empower educators and learners alike by promoting inclusive and accessible educational platforms that cater to diverse needs and foster a lifelong love for learning."

    activities_enjyd = "I engage in various activities that align with my passion for education and technology. I enjoy creating and sharing educational content on online platforms, such as developing instructional videos and interactive lessons. Additionally, I actively participate in educational technology workshops and conferences to stay updated on the latest advancements in the field. Furthermore, I volunteer my time to tutor and mentor students, helping them grasp challenging concepts and cultivate a love for learning. These activities not only allow me to pursue my interests but also contribute to my professional growth in the field of education and technology."


    proacted2024(user_int, activities_enjyd)