"""The view function to update the course tbale with total grad probs manually"""



def realtimestudentprob(request, course_id=61, school_id=None):
    """This function will run every student's probability metrics and update the student table and other relevant tables, then the admin page will be caused to read the db again, ultimately reflecting on the admin interface as fresh and new manna."""

    if course_id and not school_id:
        course_ids = [1, 58, 61, 51, 35, 68, 63, 21, 15]
        for course_i in course_ids:
            try:
                # Getting all students associated with the given course ID
                students = StudentUser.objects.filter(course_id=course_i)

                # Loading the machine learning model
                model_path = r'C:\Users\Simon\proacted\AIacademia\trained_models\proacted_model_2.2_with5morefeatures.joblib'
                model = joblib.load(model_path)

                total_probability = 0.0

                for student in students:
                    # Prepare input data for prediction
                    input_data = [[
                        student.Lessons_Attended,
                        student.Aggregate_points,
                        student.pcnt_of_lessons_attended,
                        student.homework_submission_rates,
                        student.CAT_1_marks,
                        student.CAT_2_marks,
                        student.activity_on_elearning_platforms
                    ]] 

                    # Predict student real-time probabilities
                    prediction = model.predict(input_data)

                    print(f"probability for {student.name} is {prediction[0][0]}")

                    # Write the probability to the table
                    student.graduation_probability = prediction[0][0]
                    student.save()

                    # Update total probability
                    total_probability += prediction[0][0]

                    course = Course.objects.get(id=course_i)
                    course.graduation_probability = total_probability
                    course.save()
                    print(f'saved even course: {course}: {total_probability}')  

            # after calculating probabilities in real time, the admin panel goes ahead to display then new values, student.graduation_probability
            # return HttpResponse("Success") # here, return the admin page with these new values.
            except Exception as e:
                print(f"Error: {e}")

    elif school_id and not course_id:
        # logic for school id
        schools = Course.objects.filter(school_id=school_id) 
        for courses in schools:
            coursenames =  courses.name
            course_probabilities = courses.graduation_probability
            course_studentcount = courses.students_count
            average_prob_to_display = course_probabilities/course_studentcount

            print(f"To be displayed asa bar: {coursenames} against {average_prob_to_display}")
        return HttpResponse("Some error occurred, plese try again") # here also, render the admin page with these two fields for the bar graph to be drawn
    return HttpResponse("nothing")