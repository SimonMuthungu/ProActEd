from sklearn.metrics.pairwise import cosine_similarity
import numpy as np

x = [[1.2, 1.0, 2.4]]
y = [[10.9, 10.04, 11.3]]
z = np.array(x)
u = np.array(y) 

# z.reshape(1, -1)
# u.reshape(1, -1) 


sim = cosine_similarity(z, u)
print(sim[0][0])
