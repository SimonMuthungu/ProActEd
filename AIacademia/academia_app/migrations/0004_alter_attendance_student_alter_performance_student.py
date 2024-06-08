# Generated by Django 5.0.3 on 2024-06-07 19:39

import django.db.models.deletion
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0003_remove_probabilitydatatable_activity_in_group_discussions_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='attendance',
            name='student',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.studentuser'),
        ),
        migrations.AlterField(
            model_name='performance',
            name='student',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='academia_app.studentuser'),
        ),
    ]