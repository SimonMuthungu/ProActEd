import numpy as np
from sklearn.metrics.pairwise import cosine_similarity

# Define a set of vectors (for example, document embeddings)
vectors = np.array([
    [0.1, 0.2, 0.3],  # Vector 1
    [0.4, 0.5, 0.6],  # Vector 2
    [0.7, 0.8, 0.9],  # Vector 3
    [0.0, 0.1, 0.0],  # Vector 4
    [0.9, 0.8, 0.7]   # Vector 5
])

# Define a query vector
query_vector = np.array([[0.05, 0.01, 0.05]])

# Calculate cosine similarity between the query vector and each of the other vectors
similarities = cosine_similarity(query_vector, vectors)
print(similarities[0])

# # Use argsort to get the indices of vectors in descending order of similarity
# # Note: [0] is used to get the first row of similarities since query_vector has only one row
sorted_indices = np.argsort(similarities[0])[::-1]

# # Print the sorted indices and their corresponding similarity scores
print("Sorted indices:", sorted_indices)
print("Corresponding similarity scores:", similarities[0][sorted_indices])
