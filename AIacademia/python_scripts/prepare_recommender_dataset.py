# this is to help with the etl and pre processing of the recommender training dataset

import pandas as pd

recommender_training_dataset = r"C:\Users\Simon\proacted\AIacademia\python_scripts\recommender_dataset.xlsx"

df = pd.read_excel(recommender_training_dataset) 

first_column = df['Course Name'] 
print(first_column)