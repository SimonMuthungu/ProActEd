# Generated by Django 4.2.6 on 2023-10-26 20:30

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0020_alter_course_program_code'),
    ]

    operations = [
        migrations.AlterField(
            model_name='course',
            name='program_code',
            field=models.CharField(default='Course', max_length=15, unique=True),
        ),
    ]
