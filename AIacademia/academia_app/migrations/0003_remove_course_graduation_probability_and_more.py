# Generated by Django 5.0.1 on 2024-01-26 02:11

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0002_alter_adminuserproxy_options_and_more'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='course',
            name='graduation_probability',
        ),
        migrations.RemoveField(
            model_name='student',
            name='graduation_probability',
        ),
    ]
