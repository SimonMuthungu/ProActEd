from django.db import models

# Create your models here.

class School_database(models.Model):
    School = models.CharField(max_length=200)
    Department = models.CharField(max_length=200)
    Courses = models.CharField(max_length=200)


# class Choice(models.Model):
#     question = models.ForeignKey(Question, on_delete=models.CASCADE)
#     choice_text = models.CharField(max_length=200)
#     votes = models.IntegerField(default=0)
