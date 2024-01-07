<<<<<<< HEAD
from django.db import models


class School(models.Model):
    id = models.AutoField(primary_key=True)  # Explicitly define an 'id' field
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)

=======
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
    def __str__(self):
        return f"Base User: {self.username}"

    # If needed, add any common fields here

# Admin User Model
class AdminUser(BaseUser):
    admin_field = models.CharField(max_length=100)
    def __str__(self):
        return f"Admin User: {self.username}"

# Super Admin User Model
class SuperAdminUser(BaseUser):
    superadmin_field = models.CharField(max_length=100)
    def __str__(self):
        return f"SuperAdmin User: {self.username}"

# Student User Model
class StudentUser(BaseUser):
    student_field = models.CharField(max_length=100)

# School Model
class School(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)

# Course Model
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class Course(models.Model):
    # program_code = models.CharField(max_length=15, null=True, unique=True, default='Course')
    name = models.CharField(max_length=100)
    prefix = models.CharField(max_length=15)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    students_count = models.PositiveIntegerField(default=0)
    graduation_probability = models.FloatField(default=0.0)

<<<<<<< HEAD
class Student(models.Model):
=======
# Student Model
class Student(models.Model):
    user = models.OneToOneField(
        StudentUser,
        on_delete=models.CASCADE,
        related_name='student_profile',
        null=True  # Allow null values for the user field
    )
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    graduation_probability = models.FloatField(default=0.0)

<<<<<<< HEAD
=======
# Fee Information Model
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class FeeInformation(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    required_fees = models.DecimalField(max_digits=10, decimal_places=2)
    fees_paid = models.DecimalField(max_digits=10, decimal_places=2)

<<<<<<< HEAD
=======
# Attendance Model
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class Attendance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    total_classes = models.PositiveIntegerField()
    attended_classes = models.PositiveIntegerField()

<<<<<<< HEAD
=======
# Performance Model
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class Performance(models.Model):
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    aggregate_points = models.DecimalField(max_digits=4, decimal_places=2)
    agp = models.CharField(max_length=10)

<<<<<<< HEAD
class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)
    
class userAuthorisation(models.Model):
    username=  models.CharField(max_length=100)
    password=  models.CharField(max_length=100)

class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

=======
# Field of Interest Model
class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)

# High School Subject Model
class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

# Course of Interest Model
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class CourseOfInterest(models.Model):
    name = models.CharField(max_length=100)
    fields_of_interest = models.ManyToManyField(FieldOfInterest, related_name='courses_of_interest')
    required_high_school_subjects = models.ManyToManyField(HighSchoolSubject, related_name='required_for_courses')

<<<<<<< HEAD
=======
# Course Data for Recommender Model

>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
class Recommender_training_data(models.Model):
    Course_name = models.CharField(max_length=100)
    Course_objectives = models.CharField(max_length=100)
    Course_general_info_and_about = models.CharField(max_length=100)
    General_prereuisites = models.CharField(max_length=100)
    Subject_prerequisites = models.CharField(max_length=100)

    def __str__(self):
<<<<<<< HEAD
        return self.name
=======
        return self.course_name
>>>>>>> 00d3a7fd4ff67c9407df1d0bc90c897b7cad7c51
