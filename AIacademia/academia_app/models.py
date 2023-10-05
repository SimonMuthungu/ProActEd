from django.db import models


class School(models.Model):
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)  # Add an abbreviation field
    departments_count = models.PositiveIntegerField(default=0)  # Add a departments count field (initialized to 0)

class Department(models.Model):
    name = models.CharField(max_length=100)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    courses_count = models.PositiveIntegerField(default=0)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

class Course(models.Model):
    name = models.CharField(max_length=100)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE,)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

class Student(models.Model):
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    graduation_probability = models.FloatField(default=0.0)

    def __str__(self):
        return self.name