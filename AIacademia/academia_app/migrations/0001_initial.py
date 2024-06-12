# Generated by Django 5.0.3 on 2024-06-12 01:24

import django.contrib.auth.validators
import django.db.models.deletion
import django.utils.timezone
from django.conf import settings
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        ('auth', '0012_alter_user_first_name_max_length'),
    ]

    operations = [
        migrations.CreateModel(
            name='BaseUser',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('password', models.CharField(max_length=128, verbose_name='password')),
                ('last_login', models.DateTimeField(blank=True, null=True, verbose_name='last login')),
                ('is_superuser', models.BooleanField(default=False, help_text='Designates that this user has all permissions without explicitly assigning them.', verbose_name='superuser status')),
                ('username', models.CharField(error_messages={'unique': 'A user with that username already exists.'}, help_text='Required. 150 characters or fewer. Letters, digits and @/./+/-/_ only.', max_length=150, unique=True, validators=[django.contrib.auth.validators.UnicodeUsernameValidator()], verbose_name='username')),
                ('first_name', models.CharField(blank=True, max_length=150, verbose_name='first name')),
                ('last_name', models.CharField(blank=True, max_length=150, verbose_name='last name')),
                ('email', models.EmailField(blank=True, max_length=254, verbose_name='email address')),
                ('is_staff', models.BooleanField(default=False, help_text='Designates whether the user can log into this admin site.', verbose_name='staff status')),
                ('is_active', models.BooleanField(default=True, help_text='Designates whether this user should be treated as active. Unselect this instead of deleting accounts.', verbose_name='active')),
                ('date_joined', models.DateTimeField(default=django.utils.timezone.now, verbose_name='date joined')),
                ('role', models.CharField(blank=True, max_length=50, null=True)),
                ('user_permissions', models.ManyToManyField(blank=True, help_text='Specific permissions for this user.', related_name='user_set', related_query_name='user', to='auth.permission', verbose_name='user permissions')),
            ],
            options={
                'verbose_name': 'user',
                'verbose_name_plural': 'users',
                'abstract': False,
            },
        ),
        migrations.CreateModel(
            name='FieldOfInterest',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name='HighSchoolSubject',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name='ProbabilityDataTable',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('Lessons_Attended', models.FloatField()),
                ('Total_lessons_in_that_period', models.FloatField()),
                ('Aggregate_points', models.FloatField()),
                ('pcnt_of_lessons_attended', models.FloatField()),
                ('homework_submission_rates', models.FloatField()),
                ('activity_on_learning_platforms', models.FloatField()),
                ('CAT_1_marks', models.FloatField()),
                ('CAT_2_marks', models.FloatField()),
                ('Deadline_Adherence', models.FloatField()),
                ('teachers_comments_so_far', models.TextField()),
                ('activity_on_elearning_platforms', models.FloatField()),
                ('passed_or_not', models.FloatField()),
            ],
        ),
        migrations.CreateModel(
            name='Recommender_training_data',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('course_name', models.CharField(max_length=100)),
                ('course_objectives', models.CharField(max_length=100)),
                ('course_general_info_and_about', models.CharField(max_length=100)),
                ('general_prerequisites', models.CharField(max_length=100)),
                ('subject_prerequisites', models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name='Recommender_training_data_byte_vectors',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('course_name', models.CharField(max_length=200)),
                ('course_objectives', models.BinaryField()),
                ('course_general_info_and_about', models.BinaryField()),
                ('general_prerequisites', models.BinaryField()),
                ('subject_prerequisites', models.BinaryField()),
            ],
        ),
        migrations.CreateModel(
            name='Recommender_training_data_number_vectors',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('course_name', models.CharField(max_length=200)),
                ('course_objectives', models.CharField(max_length=5000)),
                ('course_general_info_and_about', models.CharField(max_length=5000)),
                ('general_prerequisites', models.CharField(max_length=5000)),
                ('subject_prerequisites', models.CharField(max_length=5000)),
            ],
        ),
        migrations.CreateModel(
            name='Recommender_training_data_tokenized_sentences',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('course_name', models.CharField(max_length=100)),
                ('course_objectives', models.CharField(max_length=100)),
                ('course_general_info_and_about', models.CharField(max_length=100)),
                ('general_prerequisites', models.CharField(max_length=100)),
                ('subject_prerequisites', models.CharField(max_length=100)),
            ],
        ),
        migrations.CreateModel(
            name='RecommenderSBERTVectors',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('course_name', models.CharField(max_length=255, unique=True)),
                ('description_embedding', models.CharField(max_length=10000)),
                ('objectives_embedding', models.CharField(max_length=10000)),
            ],
        ),
        migrations.CreateModel(
            name='School',
            fields=[
                ('id', models.AutoField(primary_key=True, serialize=False)),
                ('name', models.CharField(max_length=100)),
                ('abbreviation', models.CharField(max_length=10)),
            ],
        ),
        migrations.CreateModel(
            name='Unit',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(max_length=100)),
                ('semester', models.CharField(max_length=20)),
            ],
        ),
        migrations.CreateModel(
            name='AdminUser',
            fields=[
                ('baseuser_ptr', models.OneToOneField(auto_created=True, on_delete=django.db.models.deletion.CASCADE, parent_link=True, primary_key=True, serialize=False, to=settings.AUTH_USER_MODEL)),
                ('admin_field', models.CharField(max_length=100)),
            ],
            options={
                'verbose_name': 'user',
                'verbose_name_plural': 'users',
                'abstract': False,
            },
            bases=('academia_app.baseuser',),
        ),
        migrations.CreateModel(
            name='SuperAdminUser',
            fields=[
                ('baseuser_ptr', models.OneToOneField(auto_created=True, on_delete=django.db.models.deletion.CASCADE, parent_link=True, primary_key=True, serialize=False, to=settings.AUTH_USER_MODEL)),
                ('superadmin_field', models.CharField(max_length=100)),
            ],
            options={
                'verbose_name': 'user',
                'verbose_name_plural': 'users',
                'abstract': False,
            },
            bases=('academia_app.baseuser',),
        ),
        migrations.CreateModel(
            name='BaseUserGroup',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('base_user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
                ('group', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='auth.group')),
            ],
        ),
        migrations.AddField(
            model_name='baseuser',
            name='groups',
            field=models.ManyToManyField(through='academia_app.BaseUserGroup', to='auth.group'),
        ),
        migrations.CreateModel(
            name='CourseOfInterest',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('fields_of_interest', models.ManyToManyField(related_name='courses_of_interest', to='academia_app.fieldofinterest')),
                ('required_high_school_subjects', models.ManyToManyField(related_name='required_for_courses', to='academia_app.highschoolsubject')),
            ],
        ),
        migrations.CreateModel(
            name='Message',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('content', models.TextField()),
                ('timestamp', models.DateTimeField(auto_now_add=True)),
                ('recipient', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='received_messages', to=settings.AUTH_USER_MODEL)),
                ('sender', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='sent_messages', to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='NewMessageNotification',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('is_new', models.BooleanField(default=True)),
                ('user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='notifications', to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='Course',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('prefix', models.CharField(max_length=15)),
                ('students_count', models.PositiveIntegerField(default=0)),
                ('graduation_probability', models.FloatField(default=0.0)),
                ('school', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.school')),
            ],
        ),
        migrations.CreateModel(
            name='UserProfile',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('bio', models.TextField(blank=True, max_length=500)),
                ('full_name', models.CharField(blank=True, max_length=100)),
                ('phone_number', models.CharField(blank=True, max_length=20)),
                ('parents_phone_number', models.CharField(blank=True, max_length=20)),
                ('user', models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='AdminUserProxy',
            fields=[
            ],
            options={
                'verbose_name': 'Staff User',
                'verbose_name_plural': 'Staff Users',
                'proxy': True,
                'indexes': [],
                'constraints': [],
            },
            bases=('academia_app.adminuser',),
        ),
        migrations.CreateModel(
            name='StudentUser',
            fields=[
                ('baseuser_ptr', models.OneToOneField(auto_created=True, on_delete=django.db.models.deletion.CASCADE, parent_link=True, primary_key=True, serialize=False, to=settings.AUTH_USER_MODEL)),
                ('student_field', models.CharField(max_length=100)),
                ('name', models.CharField(max_length=100)),
                ('registration_number', models.CharField(max_length=20, unique=True)),
                ('graduation_probability', models.FloatField(default=0.0)),
                ('profile_picture', models.ImageField(blank=True, null=True, upload_to='profile_pictures/')),
                ('Lessons_Attended', models.FloatField(default=100)),
                ('Total_lessons_in_that_period', models.FloatField(default=234)),
                ('Aggregate_points', models.FloatField(default=50)),
                ('pcnt_of_lessons_attended', models.FloatField(default=47)),
                ('homework_submission_rates', models.FloatField(default=74)),
                ('activity_on_learning_platforms', models.FloatField(default=75)),
                ('CAT_1_marks', models.FloatField(default=20)),
                ('CAT_2_marks', models.FloatField(default=18)),
                ('Deadline_Adherence', models.TextField()),
                ('teachers_comments_so_far', models.TextField()),
                ('activity_on_elearning_platforms', models.FloatField(default=74)),
                ('course', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.course')),
                ('school', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.school')),
            ],
            options={
                'verbose_name': 'user',
                'verbose_name_plural': 'users',
                'abstract': False,
            },
            bases=('academia_app.baseuser',),
        ),
        migrations.CreateModel(
            name='Performance',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('semester', models.CharField(max_length=20)),
                ('aggregate_points', models.DecimalField(decimal_places=2, max_digits=4)),
                ('agp', models.CharField(max_length=10)),
                ('student', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.studentuser')),
            ],
        ),
        migrations.CreateModel(
            name='FeeInformation',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('semester', models.CharField(max_length=20)),
                ('required_fees', models.DecimalField(decimal_places=2, max_digits=10)),
                ('fees_paid', models.DecimalField(decimal_places=2, max_digits=10)),
                ('student', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.studentuser')),
            ],
        ),
        migrations.CreateModel(
            name='Attendance',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('semester', models.CharField(max_length=20)),
                ('total_classes', models.PositiveIntegerField()),
                ('attended_classes', models.PositiveIntegerField()),
                ('student', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.studentuser')),
            ],
        ),
        migrations.CreateModel(
            name='StudentUserProxy',
            fields=[
            ],
            options={
                'verbose_name': 'Student User',
                'verbose_name_plural': 'Student Users',
                'proxy': True,
                'indexes': [],
                'constraints': [],
            },
            bases=('academia_app.studentuser',),
        ),
        migrations.CreateModel(
            name='SuperAdminUserProxy',
            fields=[
            ],
            options={
                'verbose_name': 'Super Admin',
                'verbose_name_plural': 'Super Admins',
                'proxy': True,
                'indexes': [],
                'constraints': [],
            },
            bases=('academia_app.superadminuser',),
        ),
    ]
