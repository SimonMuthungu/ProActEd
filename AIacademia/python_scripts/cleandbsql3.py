import os
import django
import nltk
import sys
sys.path.append(r'C:\Users\Simon\proacted\AIacademia')

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

from academia_app.models import Course_data_for_recommender
# nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

courses = Course_data_for_recommender.objects.all()

for course in courses:
    text = course.Course_Objectives
    tokens = word_tokenize(text)
    tokens = [word for word in tokens if word.lower() not in stopwords.words('english')]
    cleaned_text = ' '.join(tokens)
    
    course.Course_Objectives = cleaned_text
    course.save()
    print('done')
