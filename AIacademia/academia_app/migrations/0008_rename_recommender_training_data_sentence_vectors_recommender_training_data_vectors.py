# Generated by Django 4.2.5 on 2024-01-25 15:31

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0007_rename_recommender_training_data_vectorized_sentences_recommender_training_data_sentence_vectors'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='Recommender_training_data_sentence_vectors',
            new_name='Recommender_training_data_vectors',
        ),
    ]
