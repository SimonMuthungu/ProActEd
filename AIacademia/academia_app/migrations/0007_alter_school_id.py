# Generated by Django 4.2.6 on 2023-10-26 18:11

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0006_course_prefix'),
    ]

    operations = [
        migrations.AlterField(
            model_name='school',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
