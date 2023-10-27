import pandas as pd

# Read the Excel file
df = pd.read_excel(r'C:\Users\Simon\proacted\AIacademia\python_scripts\preprocessed_data.xlsx')

# Check if 'Course Prequisites' column exists
if 'Course Prequisites' in df.columns:
    # Split the Course Prequisites into 'subject Course Prequisites' and 'general Course Prequisites'
    splits = df['Course Prequisites'].str.split('.', n=1, expand=True)
    df['general Course Prequisites'] = splits[0]
    df['subject Course Prequisites'] = splits[1]

    # Drop the original 'Course Prequisites' column
    df = df.drop('Course Prequisites', axis=1)

# Write the updated DataFrame to a new Excel file
df.to_excel(r'C:\Users\Simon\proacted\AIacademia\python_scripts\gpt4_recommender_gen_training_data.xlsx', index=False)

print("Process completed!")
