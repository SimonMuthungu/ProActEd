# Generated by Django 4.2.6 on 2023-10-26 20:01

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0013_alter_course_name'),
    ]

    operations = [
        migrations.AlterField(
            model_name='course',
            name='prefix',
            field=models.CharField(default=None, max_length=15, unique=True),
        ),
        migrations.AlterField(
            model_name='course',
            name='program_code',
            field=models.CharField(default=None, max_length=15, unique=True),
        ),
    ]
