from sklearn.feature_extraction.text import TfidfVectorizer

corpus = ["your", "list", "of", "text", "documents"]
vectorizer = TfidfVectorizer()
vectorizer.fit(corpus)

# Now you can access feature names
feature_names = vectorizer.get_feature_names_out()
print(feature_names)
