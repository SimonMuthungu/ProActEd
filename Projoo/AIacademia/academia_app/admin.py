from django.contrib import admin
<<<<<<< HEAD
from .models import School_database 

# Register your models here.
admin.site.register(School_database)
=======
from .models import School, Department, Course

admin.site.register(School)
admin.site.register(Department)
admin.site.register(Course)
>>>>>>> c72239a8c7043d92c1944b7878f78d759b57d527
