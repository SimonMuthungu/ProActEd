import gensim

# Load the model
print('started reading')
model = gensim.models.KeyedVectors.load_word2vec_format(r"C:\Users\Simon\proacted\GoogleNews-vectors-negative300.bin", binary=True)
print('finished reading')
# Get the vector for the word 'computer'
m = model['computer']

# Print the vector
print(m)
