import time
import os
import sys
import django
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from sentence_transformers import SentenceTransformer



starttime = time.time()

print("Loading s-model")
# local_model_path = os.path.abspath('../../proacted_googleds/sbert_files') 
local_model_path = r'C:\Users\Simon\proacted_googleds\sbert_files'

print(f"local mod path: {local_model_path}")
print("Contents of the model directory:", os.listdir(local_model_path))
os.environ["TRANSFORMERS_OFFLINE"] = "1"
os.environ["TRANSFORMERS_CACHE"] = local_model_path


import sentence_transformers
print(f"sbert version: {sentence_transformers.__version__}")
try: 
    model = SentenceTransformer(local_model_path)
    print("Done loading s-model")

except Exception as e:
    print(f'error e: {e}') 