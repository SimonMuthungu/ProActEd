from django.conf import settings
from django.contrib.auth.models import AbstractUser, BaseUserManager, Group
from django.db import models
from django.db.models.signals import post_save
from django.dispatch import receiver

# Custom User Manager
class CustomUserManager(BaseUserManager):
    def create_user(self, username, password=None, group_name=None, **extra_fields):
        if not username:
            raise ValueError('The Username must be set')
        user = self.model(username=username, **extra_fields)
        user.set_password(password)
        user.save(using=self._db)

        if group_name:
            group, created = Group.objects.get_or_create(name=group_name)
            user.groups.add(group)
            role_map = {
                'SuperAdminUser': 'Super Administrator',
                'Staff Users': 'Administrator',
                'Student Users': 'Student User',
            }
            user.role = role_map.get(group_name, '')
            user.save()

        return user

    def create_superuser(self, username, password=None, **extra_fields):
        extra_fields.setdefault('is_staff', True)
        extra_fields.setdefault('is_superuser', True)

        if extra_fields.get('is_staff') is not True:
            raise ValueError('Superuser must have is_staff=True.')
        if extra_fields.get('is_superuser') is not True:
            raise ValueError('Superuser must have is_superuser=True.')

        return self.create_user(username, password, 'SuperAdminUser', **extra_fields)

# Base User Model
class BaseUser(AbstractUser):
    objects = CustomUserManager()
    groups = models.ManyToManyField(Group, through='BaseUserGroup')
    role = models.CharField(max_length=50, blank=True, null=True)

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


# Admin User Modelsuper
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
    profile_picture = models.ImageField(upload_to='profile_pictures/', null=True, blank=True)

    def __str__(self):
        return f"Student User: {self.username}"

# to track student perfomance
class PerformanceMetric(models.Model):
    student_user = models.ForeignKey('StudentUser', on_delete=models.CASCADE, related_name='performance_records')
    semester = models.PositiveIntegerField()
    year_of_study = models.PositiveIntegerField()
    date = models.DateField(auto_now_add=True)

    graduation_probability = models.FloatField(default=0.0)
    Lessons_Attended = models.FloatField(default=0)
    Total_lessons_in_that_period = models.FloatField(default=0)
    Aggregate_points = models.FloatField(default=0)
    pcnt_of_lessons_attended = models.FloatField(default=0)
    homework_submission_rates = models.FloatField(default=0)
    activity_on_learning_platforms = models.FloatField(default=0)
    CAT_1_marks = models.FloatField(default=0)
    CAT_2_marks = models.FloatField(default=0)
    Deadline_Adherence = models.TextField(blank=True, null=True)
    teachers_comments_so_far = models.TextField(blank=True, null=True)
    activity_on_elearning_platforms = models.FloatField(default=0)

    def __str__(self):
        return f"Performance Record of {self.student_user.username} - Semester {self.semester}, Year {self.year_of_study}"


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


class FieldOfInterest(models.Model):
    name = models.CharField(max_length=100)

    def __str__(self):
        return self.name

class HighSchoolSubject(models.Model):
    name = models.CharField(max_length=100)

    def __str__(self):
        return self.name

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
        
class ProbabilityDataTable(models.Model):
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

    def save(self, *args, **kwargs):
        float_fields = [
            'Lessons_Attended', 'Total_lessons_in_that_period', 'Aggregate_points',
            'pcnt_of_lessons_attended', 'homework_submission_rates', 'activity_on_learning_platforms',
            'CAT_1_marks', 'CAT_2_marks', 'Deadline_Adherence', 'activity_on_elearning_platforms',
            'passed_or_not'
        ]
        
        for field in float_fields:
            value = getattr(self, field)
            if value == 'poor':
                setattr(self, field, 0.0)

        super().save(*args, **kwargs)
