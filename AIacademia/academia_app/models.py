from django.db import models


class School(models.Model):
    id = models.AutoField(primary_key=True)  # Explicitly define an 'id' field
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)

class Course(models.Model):
    # program_code = models.CharField(max_length=15, null=True, unique=True, default='Course')
    name = models.CharField(max_length=100)
    prefix = models.CharField(max_length=15)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

class Student(models.Model):
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    graduation_probability = models.FloatField(default=0.0)

class FeeInformation(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    required_fees = models.DecimalField(max_digits=10, decimal_places=2)
    fees_paid = models.DecimalField(max_digits=10, decimal_places=2)

class Attendance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    total_classes = models.PositiveIntegerField()
    attended_classes = models.PositiveIntegerField()

class Performance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    aggregate_points = models.DecimalField(max_digits=4, decimal_places=2)
    agp = models.CharField(max_length=10)

class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)

class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

class CourseOfInterest(models.Model):
    name = models.CharField(max_length=100)
    fields_of_interest = models.ManyToManyField(FieldOfInterest, related_name='courses_of_interest')
    required_high_school_subjects = models.ManyToManyField(HighSchoolSubject, related_name='required_for_courses')

<<<<<<< HEAD
class Recommender_training_data(models.Model):
    Course_name = models.CharField(max_length=100)
    Course_objectives = models.CharField(max_length=100)
    Course_general_info_and_about = models.CharField(max_length=100)
    General_prereuisites = models.CharField(max_length=100)
    Subject_prerequisites = models.CharField(max_length=100)


=======

# to save the excel data to a db.sqlite3

class Course_data_for_recommender(models.Model):
    Course_name = models.CharField(max_length=255)
    Course_Objectives = models.TextField()
    Course_General_Info_and_About = models.TextField()
    Prerequisites = models.TextField()



>>>>>>> c05bfde20735bbfed350f994a5a4c930eba30e28
    def __str__(self):
        return self.name
