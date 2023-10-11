# Generated by Django 4.2.1 on 2023-10-04 14:37

import django.db.models.deletion
from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Course',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('students_count', models.PositiveIntegerField(default=0)),
                ('graduation_probability', models.FloatField(default=0.0)),
            ],
        ),
        migrations.CreateModel(
            name='Department',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('courses_count', models.PositiveIntegerField(default=0)),
                ('students_count', models.PositiveIntegerField(default=0)),
                ('graduation_probability', models.FloatField(default=0.0)),
            ],
        ),
        migrations.CreateModel(
            name='School',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('abbreviation', models.CharField(max_length=10)),
                ('departments_count', models.PositiveIntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='Student',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('registration_number', models.CharField(max_length=20, unique=True)),
                ('graduation_probability', models.FloatField(default=0.0)),
                ('course', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.course')),
                ('department', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.department')),
                ('school', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.school')),
            ],
        ),
        migrations.AddField(
            model_name='department',
            name='school',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.school'),
        ),
        migrations.AddField(
            model_name='course',
            name='department',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.department'),
        ),
        migrations.AddField(
            model_name='course',
            name='school',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.school'),
        ),
    ]
