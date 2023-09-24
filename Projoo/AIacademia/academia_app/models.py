# models.py

from django.db import models

class School(models.Model):
    name = models.CharField(max_length=100)

<<<<<<< HEAD
class School_database(models.Model):
    School = models.CharField(max_length=200)
    Department = models.CharField(max_length=200)
    Courses = models.CharField(max_length=199)
=======
class Department(models.Model):
    name = models.CharField(max_length=100)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
>>>>>>> c72239a8c7043d92c1944b7878f78d759b57d527

class Course(models.Model):
    name = models.CharField(max_length=100)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)
