from django.db import models


class School(models.Model):
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)
    departments_count = models.PositiveIntegerField(default=0)

class Department(models.Model):
    name = models.CharField(max_length=100)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    courses_count = models.PositiveIntegerField(default=0)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

class Course(models.Model):
    name = models.CharField(max_length=100)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

class Student(models.Model):
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
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


    def __str__(self):
        return self.name
