# this is to help with creating the datasets we will need to train the regression model
import random

import pandas as pd


# Automatically creating one
def create_dataset(total_lessons, no_of_students_to_create):
    lessons_attended = []
    total_lessons_that_semester = []
    aggregate_points = []
    passed = []
    counting = 0

    #if this person attended many lessons then they maybe should have passed
    while counting < no_of_students_to_create:

        individual_lessons_attended = random.randint(50, 234) # in a whole year, its very likely that any student will attend >50 lessons
        percentage_attendance = (individual_lessons_attended/total_lessons)*100 

        if percentage_attendance > 80: #total yearly attendance > 80%

            # for a more practical model, theres students who might attend and not  get the high scores of 65-79
            individual_aggregate_points = random.randint(60, 79) # range is likely b2n 60 & 79

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1


        elif percentage_attendance > 65:

            individual_aggregate_points = random.randint(55, 68)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1


        elif percentage_attendance > 55:

            individual_aggregate_points = random.randint(55, 65)
            genius_aggregates = random.randint(60, 68)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1

        elif percentage_attendance > 50:

            individual_aggregate_points = random.randint(45, 54)

            genius_aggregates = random.randint(55, 65)


            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)

            g_or_not = random.randint(1, 2) # this student with low attendance could either score highly (for the genius) or lowly

            if g_or_not == 1:
                aggregate_points.append(genius_aggregates)
                passed.append(1)
            else:
                aggregate_points.append(individual_aggregate_points)
                passed.append(0)

            counting += 1

        elif percentage_attendance > 40:

            individual_aggregate_points = random.randint(40, 50)

            genius_aggregates = random.randint(50, 65)


            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)

            g_or_not = random.randint(1, 2) # this student with low attendance could either score highly (for the genius) or lowly

            if g_or_not == 1:
                aggregate_points.append(individual_aggregate_points)
                passed.append(0)

            else:
                aggregate_points.append(genius_aggregates)
                if genius_aggregates > 55:
                    passed.append(1)
                else:
                    passed.append(0)
            counting += 1

        elif percentage_attendance < 40:

            individual_aggregate_points = random.randint(25, 39)
            genius_aggregates = random.randint(45, 60)


            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)

            g_or_not = random.randint(1, 2) # this student with low attendance could either score highly (for the genius) or lowly

            if g_or_not == 1:
                aggregate_points.append(individual_aggregate_points)
                passed.append(0)

            else:
                aggregate_points.append(genius_aggregates)
                if genius_aggregates > 55:
                    passed.append(1)
                else:
                    passed.append(0)
            counting += 1


        dummy_data = {
        # 'Name': ['Galavu', 'Mercy', 'Simon', 'Moncrief', 'Mervitz', 'John', 'Julian'],
        'Lessons_Attended': lessons_attended,
        'Total_lessons_in_that_period': total_lessons_that_semester,
        'Aggregate points': aggregate_points,
        'passed': passed
        }

    df = pd.DataFrame(dummy_data)
    df.to_excel(r'C:\Users\Simon\proacted\ProActEd\AIacademia\python_scripts\trainwith_100000.xlsx', index=False)


    return lessons_attended, total_lessons_that_semester, aggregate_points, passed



create_dataset(234, 100000)
print("done...\n")

# so, the dataset with 5000 records has 1033 geniuses (low lesson attendance and fail correlation removed)
# the dataset with 100000 records has 10288 geniuses