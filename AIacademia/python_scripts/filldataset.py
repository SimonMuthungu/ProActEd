# this script will help fill up the additional fields in the new dataset sheet

import pandas as pd
import random

# Assuming you have a DataFrame named df with the initial columns populated
# Lessons_Attended, Total_lessons_in_that_period, Aggregate points, passed

df = pd.read_excel(r'C:\Users\Simon\proacted\AIacademia\test_data_files\trainwith_100000.xlsx')

# Calculate % of lessons attended
df['% of lessons attended'] = (df['Lessons_Attended'] / df['Total_lessons_in_that_period']) * 100

# Populate homework submission rates with random percentages between 50 and 100
df['homework submission rates'] = [random.randint(30, 100) for _ in range(len(df))] 

# Populate activity on e-learning platforms with random percentages between 0 and 100
df['activity on e-learning platforms'] = [random.randint(10, 99) for _ in range(len(df))]

# Populate CAT 1 and CAT 2 marks with random marks between 0 and 100
df['CAT 1 marks'] = [random.randint(0, 30) for _ in range(len(df))]
df['CAT 2 marks'] = [random.randint(0,30) for _ in range(len(df))]

# Populate Deadline Adherence with either 'poor' or 'on-time'
deadline_adherence_options = ['poor', 'on-time']
df['Deadline Adherence'] = [random.choice(deadline_adherence_options) for _ in range(len(df))]

# Teachers' comments
teachers_comments_1 = [
    "Good progress", "Excellent work",
    "Outstanding commitment", "Showing great potential", "Highly motivated"
]

teachers_comments_2 = [
    "Needs improvement", "Can do better", "Struggling with concepts",
 "Falling behind", "Lacking participation"
 ]

df['teachers comments so far'] = [random.choice(teachers_comments_1) for _ in range(len(df))]

ndf = pd.DataFrame(df)
df.to_excel(r'C:\Users\Simon\proacted\AIacademia\test_data_files\trainwith_100000.xlsx', index=False) 


# Display the first few rows to check
print(df.head())