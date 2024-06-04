# Generated by Django 4.2.3 on 2024-03-04 15:50

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0004_userprofile_full_name_and_more'),
    ]

    operations = [
        migrations.CreateModel(
            name='Unit',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(max_length=100)),
                ('semester', models.CharField(max_length=20)),
            ],
        ),
        migrations.DeleteModel(
            name='CustomUser',
        ),
    ]
