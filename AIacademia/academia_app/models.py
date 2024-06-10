from django.conf import settings
from django.contrib.auth.models import AbstractUser, BaseUserManager, Group
from django.db import models
from django.db.models.signals import post_save
from django.dispatch import receiver


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


# Intermediate model for BaseUser-Group many-to-many relationship
class BaseUserGroup(models.Model):
    base_user = models.ForeignKey(BaseUser, on_delete=models.CASCADE)
    group = models.ForeignKey(Group, on_delete=models.CASCADE)


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
    graduation_probability = models.FloatField(default=0.0)

    def __str__(self):
        return self.name

# Student User Model
class StudentUser(BaseUser):
    student_field = models.CharField(max_length=100)
    name = models.CharField(max_length=100)
    registration_number = models.CharField(max_length=20, unique=True)
    course = models.ForeignKey(Course, on_delete=models.CASCADE)
    school = models.ForeignKey(School, on_delete=models.CASCADE)
    graduation_probability = models.FloatField(default=0.0)
    profile_picture = models.ImageField(upload_to='profile_pictures/', null=True, blank=True)
    Lessons_Attended = models.FloatField()
    Total_lessons_in_that_period = models.FloatField(default=234)
    Aggregate_points = models.FloatField()
    pcnt_of_lessons_attended = models.FloatField()
    homework_submission_rates = models.FloatField()
    activity_on_learning_platforms = models.FloatField()
    CAT_1_marks = models.FloatField()
    CAT_2_marks = models.FloatField()
    Deadline_Adherence = models.TextField()
    teachers_comments_so_far = models.TextField()
    activity_on_elearning_platforms = models.FloatField()

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

# Fee Information Model
class FeeInformation(models.Model):
    student = models.ForeignKey(StudentUser, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    required_fees = models.DecimalField(max_digits=10, decimal_places=2)
    fees_paid = models.DecimalField(max_digits=10, decimal_places=2)

# Attendance Model
class Attendance(models.Model):
    student = models.ForeignKey(StudentUser, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    total_classes = models.PositiveIntegerField()
    attended_classes = models.PositiveIntegerField()

# Performance Model
class Performance(models.Model):
    student = models.ForeignKey(StudentUser, on_delete=models.CASCADE)
    semester = models.CharField(max_length=20)
    aggregate_points = models.DecimalField(max_digits=4, decimal_places=2)
    agp = models.CharField(max_length=10)


class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)


class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

    def __str__(self):
        return self.name


class CourseOfInterest(models.Model):
    name = models.CharField(max_length=100)
    fields_of_interest = models.ManyToManyField(FieldOfInterest, related_name='courses_of_interest')
    required_high_school_subjects = models.ManyToManyField(HighSchoolSubject, related_name='required_for_courses')

# Course Data for Recommender Model
class Recommender_training_data(models.Model):
    course_name = models.CharField(max_length=100)
    course_objectives = models.CharField(max_length=100)
    course_general_info_and_about = models.CharField(max_length=100)
    general_prerequisites = models.CharField(max_length=100)
    subject_prerequisites = models.CharField(max_length=100)

# Model to store the optimizations for the recommender model
class Recommender_training_data_tokenized_sentences(models.Model):
    course_name = models.CharField(max_length=100)
    course_objectives = models.CharField(max_length=100)
    course_general_info_and_about = models.CharField(max_length=100)
    general_prerequisites = models.CharField(max_length=100)
    subject_prerequisites = models.CharField(max_length=100)


class Recommender_training_data_byte_vectors(models.Model):
    course_name = models.CharField(max_length=200)
    course_objectives = models.BinaryField()
    course_general_info_and_about = models.BinaryField()
    general_prerequisites = models.BinaryField()
    subject_prerequisites = models.BinaryField()


# to store hexadec values, seemingly direct numbers cant be stored
    
class Recommender_training_data_number_vectors(models.Model):
    course_name = models.CharField(max_length=200)
    course_objectives = models.CharField(max_length=5000) 
    course_general_info_and_about = models.CharField(max_length=5000)
    general_prerequisites = models.CharField(max_length=5000)
    subject_prerequisites = models.CharField(max_length=5000)

class RecommenderSBERTVectors(models.Model):
    course_name = models.CharField(max_length=255, unique=True)
    description_embedding = models.CharField(max_length=10000)
    objectives_embedding = models.CharField(max_length=10000) 


    def __str__(self):
        return self.course_name

#model for messages
class Message(models.Model):
    sender = models.ForeignKey(BaseUser, on_delete=models.CASCADE, related_name='sent_messages')
    recipient = models.ForeignKey(BaseUser, on_delete=models.CASCADE, related_name='received_messages')
    content = models.TextField()
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.sender} to {self.recipient} at {self.timestamp}'    

class NewMessageNotification(models.Model):
    user = models.ForeignKey(BaseUser, on_delete=models.CASCADE, related_name='notifications')
    is_new = models.BooleanField(default=True)


class UserProfile(models.Model):
    user = models.OneToOneField(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    bio = models.TextField(max_length=500, blank=True)
    full_name = models.CharField(max_length=100, blank=True)
    phone_number = models.CharField(max_length=20, blank=True)
    parents_phone_number = models.CharField(max_length=20, blank=True)

    def __str__(self):
        return f'Profile of {self.user.username}'
    
class Unit(models.Model):
    title = models.CharField(max_length=100)
    semester = models.CharField(max_length=20)  # For simplicity, we're using a CharField
    def __str__(self):
        return self.username
    
class probabilitydatatable(models.Model):
    Lessons_Attended = models.FloatField()
    Total_lessons_in_that_period = models.FloatField()
    Aggregate_points = models.FloatField()
    pcnt_of_lessons_attended = models.FloatField()
    homework_submission_rates = models.FloatField()
    activity_on_learning_platforms = models.FloatField()
    CAT_1_marks = models.FloatField()
    CAT_2_marks = models.FloatField()
    Deadline_Adherence = models.FloatField()
    teachers_comments_so_far = models.TextField()
    activity_on_elearning_platforms = models.FloatField()
    passed_or_not = models.FloatField()
