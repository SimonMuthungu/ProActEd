# python script to check skewedness of dummy_data
# this will help know how predictable random generation can be

import pandas as pd

data_source = r'C:\Users\Simon\proacted\ProActEd\AIacademia\python_scripts\trainwith_100000.xlsx'

# reading from excel and making it a df
df = pd.read_excel(data_source)

genius = 0
xtreme_genius = 0
gen_row = []
x_treme_gen_row = []



for index, row in df.iterrows():
    Lessons_Attended = int(row['Lessons_Attended'])
    passed = int(row['passed'])

    # print(aggregate_points, type(aggregate_points))
    # print(passed, type(passed))
    
    if Lessons_Attended < 97 and passed == 1:
        genius += 1
        gen_row.append(index)
    elif Lessons_Attended < 127 and passed == 1:
        xtreme_genius += 1
        x_treme_gen_row.append(index)

# df.to_excel(r'C:\Users\Simon\proacted\ProActEd\AIacademia\python_scripts\Dummy_dataset_50002.xlsx', index=False)


print(f'\ngenii in the house: {genius}\n and xtreme geniis: {xtreme_genius}\n')

# print(gen_row)