# Generated by Django 4.2.6 on 2023-10-26 19:34

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0009_alter_course_prefix'),
    ]

    operations = [
        migrations.AlterField(
            model_name='course',
            name='name',
            field=models.CharField(default=None, max_length=100, null=True, unique=True),
        ),
    ]