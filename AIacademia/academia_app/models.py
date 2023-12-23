from django.contrib.auth.models import AbstractUser, BaseUserManager
from django.db import models


# Custom User Manager
class CustomUserManager(BaseUserManager):
    def create_user(self, username, password=None, **extra_fields):
        if not username:
            raise ValueError('The Username must be set')
        user = self.model(username=username, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_superuser(self, username, password=None, **extra_fields):
        extra_fields.setdefault('is_staff', True)
        extra_fields.setdefault('is_superuser', True)

        if extra_fields.get('is_staff') is not True:
            raise ValueError('Superuser must have is_staff=True.')
        if extra_fields.get('is_superuser') is not True:
            raise ValueError('Superuser must have is_superuser=True.')

        return self.create_user(username, password, **extra_fields)

# Base User Model
class BaseUser(AbstractUser):
    objects = CustomUserManager()

    # If needed, add any common fields here

# Admin User Model
class AdminUser(BaseUser):
    admin_field = models.CharField(max_length=100)

# Super Admin User Model
class SuperAdminUser(BaseUser):
    superadmin_field = models.CharField(max_length=100)

# Student User Model
class StudentUser(BaseUser):
    student_field = models.CharField(max_length=100)

# School Model
class School(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)

# Course Model
class Course(models.Model):
    program_code = models.CharField(max_length=15, null=True, unique=True, default='Course')
    name = models.CharField(max_length=100)
    prefix = models.CharField(max_length=15)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

# Student Model
class Student(models.Model):
    user = models.OneToOneField(
        StudentUser,
        on_delete=models.CASCADE,
        related_name='student_profile',
        null=True  # Allow null values for the user field
    )
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    graduation_probability = models.FloatField(default=0.0)

# Fee Information Model
class FeeInformation(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    required_fees = models.DecimalField(max_digits=10, decimal_places=2)
    fees_paid = models.DecimalField(max_digits=10, decimal_places=2)

# Attendance Model
class Attendance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    total_classes = models.PositiveIntegerField()
    attended_classes = models.PositiveIntegerField()

# Performance Model
class Performance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    aggregate_points = models.DecimalField(max_digits=4, decimal_places=2)
    agp = models.CharField(max_length=10)

# Field of Interest Model
class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)

# High School Subject Model
class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

# Course of Interest Model
class CourseOfInterest(models.Model):
    name = models.CharField(max_length=100)
    fields_of_interest = models.ManyToManyField(FieldOfInterest, related_name='courses_of_interest')
    required_high_school_subjects = models.ManyToManyField(HighSchoolSubject, related_name='required_for_courses')

# Course Data for Recommender Model
class CourseDataForRecommender(models.Model):
    course_name = models.CharField(max_length=255)
    course_objectives = models.TextField()
    general_info = models.TextField()
    prerequisites = models.TextField()

    def __str__(self):
        return self.course_name
