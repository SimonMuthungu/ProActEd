from django.db import migrations


def set_user_field_null(apps, schema_editor):
    # Get the Student model. 'YourAppName' should be replaced with the name of your app.
    Student = apps.get_model('academia_app', 'Student')

    # Iterate over each student and set the user field to None
    for student in Student.objects.all():
        student.user = None
        student.save()

class Migration(migrations.Migration):

    dependencies = [
        ('academia_app', '0011_merge_20231210_1441'),
    ]

    operations = [
        migrations.RunPython(set_user_field_null),
    ]
