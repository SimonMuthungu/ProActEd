# this is to help with creating the datasets we will need to train the regression model
import pandas as pd
import random


# Automatically creating one
def create_dataset(total_lessons, no_of_students_to_create):
    lessons_attended = []
    total_lessons_that_semester = []
    aggregate_points = []
    passed = []
    counting = 0

    #if this person attended many lessons then they maybe should have passed
    while counting < no_of_students_to_create:

        individual_lessons_attended = random.randint(1, 234)
        percentage_attendance = (individual_lessons_attended/total_lessons)*100 

        if percentage_attendance > 80: #totoal attendance > 80%

            individual_aggregate_points = random.randint(65, 79) # they are likely to score higher, b2n 60 & 79


            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1


        elif percentage_attendance > 65:

            individual_aggregate_points = random.randint(60, 64)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1


        elif percentage_attendance > 55:

            individual_aggregate_points = random.randint(50, 59)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(1)
            counting += 1

        elif percentage_attendance > 50:

            individual_lessons_attended = random.randint(45, 49)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(0)
            counting += 1

        elif percentage_attendance > 40:

            individual_aggregate_points = random.randint(40, 44)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
            passed.append(0)
            counting += 1

        elif percentage_attendance < 40:

            individual_aggregate_points = random.randint(25, 39)

            lessons_attended.append(individual_lessons_attended)
            total_lessons_that_semester.append(total_lessons)
            aggregate_points.append(individual_aggregate_points)
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
    df.to_excel(r'C:\Users\Simon\proacted\ProActEd\Projoo\AIacademia\python_scripts\Dummy_dataset_5000.xlsx', index=False)


    return lessons_attended, total_lessons_that_semester, aggregate_points, passed



create_dataset(234, 5000)