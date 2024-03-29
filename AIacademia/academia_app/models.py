from django.contrib.auth.models import AbstractUser, BaseUserManager, Group
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

# Intermediate model for BaseUser-Group many-to-many relationship
class BaseUserGroup(models.Model):
    base_user = models.ForeignKey('BaseUser', on_delete=models.CASCADE)
    group = models.ForeignKey(Group, on_delete=models.CASCADE)

# Base User Model
class BaseUser(AbstractUser):
    objects = CustomUserManager()
    groups = models.ManyToManyField(Group, through='BaseUserGroup')

    def __str__(self):
        return f"Base User: {self.username}"

    def has_module_perms(self, app_label):
        if self.groups.filter(name='Student Users').exists():
            return False
        return super().has_module_perms(app_label)

    def has_perm(self, perm, obj=None):
        if self.groups.filter(name='Student Users').exists():
            return False
        return super().has_perm(perm, obj)
    
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

    def __str__(self):
        return f"Student User: {self.username}"

# Proxy Models for different user roles
class AdminUserProxy(AdminUser):
    class Meta:
        proxy = True
        verbose_name = 'Staff User'
        verbose_name_plural = 'Staff Users'

class StudentUserProxy(StudentUser):
    class Meta:
        proxy = True
        verbose_name = 'Student User'
        verbose_name_plural = 'Student Users'

class SuperAdminUserProxy(SuperAdminUser):
    class Meta:
        proxy = True
        verbose_name = 'Super Admin'
        verbose_name_plural = 'Super Admins'

# School Model
class School(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    abbreviation = models.CharField(max_length=10)

    def __str__(self):
        return self.name

# Course Model
class Course(models.Model):
    name = models.CharField(max_length=100)
    prefix = models.CharField(max_length=15)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    students_count = models.PositiveIntegerField(default=0)

    def __str__(self):
        return f"{self.prefix} - {self.name}"

# Student Model
class Student(models.Model):
    user = models.OneToOneField(
        StudentUser,
        on_delete=models.CASCADE,
        related_name='student_profile',
        null=True
    )
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.name} ({self.registration_number})"


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
        # other fields...

    def __str__(self):
        return self.name

# Course of Interest Model
class CourseOfInterest(models.Model):
    name = models.CharField(max_length=100)
    fields_of_interest = models.ManyToManyField(FieldOfInterest, related_name='courses_of_interest')
    required_high_school_subjects = models.ManyToManyField(HighSchoolSubject, related_name='required_for_courses')
        # other fields...

    def __str__(self):
        return self.name

# Course Data for Recommender Model
class Recommender_training_data(models.Model):
    course_name = models.CharField(max_length=100)
    course_objectives = models.CharField(max_length=100)
    course_general_info_and_about = models.CharField(max_length=100)
    general_prerequisites = models.CharField(max_length=100)
    subject_prerequisites = models.CharField(max_length=100)

    def __str__(self):
        return self.course_name