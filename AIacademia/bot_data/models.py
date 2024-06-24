from django.db import models

# Create your models here.
from django.db import models

class MasenoInfo(models.Model):
    category = models.CharField(max_length=255)
    detail = models.CharField(max_length=255)
    additional_info = models.TextField()

    def __str__(self):
        return f"{self.category} - {self.detail}"
