# Generated by Django 4.2.5 on 2024-06-10 14:28

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='studentuser',
            name='Aggregate_points',
            field=models.FloatField(default=50),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='CAT_1_marks',
            field=models.FloatField(default=18),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='CAT_2_marks',
            field=models.FloatField(default=21),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='Deadline_Adherence',
            field=models.TextField(default='on-time'),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='Lessons_Attended',
            field=models.FloatField(default=100),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='Total_lessons_in_that_period',
            field=models.FloatField(default=234),
        ),
        migrations.AddField(
            model_name='studentuser',
            name='activity_on_elearning_platforms',
            field=models.FloatField(default=75),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='activity_on_learning_platforms',
            field=models.FloatField(default=74),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='homework_submission_rates',
            field=models.FloatField(default=58),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='pcnt_of_lessons_attended',
            field=models.FloatField(default=47.0),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='studentuser',
            name='teachers_comments_so_far',
            field=models.TextField(default='showing great potential'),
            preserve_default=False,
        ),
    ]
