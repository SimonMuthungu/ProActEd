# lazy_load_model_with_cache.py

import os
from sentence_transformers import SentenceTransformer
from django.core.cache import cache

def lazy_load_model_with_cache():
    model_key = 'sbert_model'
    model = cache.get(model_key)
    if model is None:
        # If model is not in cache, load it
        local_model_path = os.path.abspath('../../proacted_googleds/sbert_files')
        os.environ["TRANSFORMERS_OFFLINE"] = "1"
        os.environ["TRANSFORMERS_CACHE"] = local_model_path
        model = SentenceTransformer('all-MiniLM-L6-v2')
        cache.set(model_key, model, timeout=None)
        print("Loaded and cached SentenceTransformer model.")
    else:
        print("Using cached SentenceTransformer model.")

    return model

