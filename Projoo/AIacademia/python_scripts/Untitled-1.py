# python script to check skewedness of dummy_data(5000)
# this will help know how predictable random generation can be

import pandas as pd
data_source = r'C:\Users\Simon\proacted\ProActEd\Projoo\AIacademia\python_scripts\Dummy_dataset_5000.xlsx'

# reading from excel and making it a df
df = pd.read_excel(data_source)
count_skewedness = 0
skewed_row = []
new_skewed_row = []



for index, row in df.iterrows():
    aggregate_points = int(row['Aggregate points'])
    passed = int(row['passed'])
    # print(aggregate_points, type(aggregate_points))
    # print(passed, type(passed))
    
    if aggregate_points == 76 and passed == 0:
        count_skewedness += 1
        skewed_row.append(index)
        df = df.drop(index)


print('skewed data:', count_skewedness)

print(skewed_row)