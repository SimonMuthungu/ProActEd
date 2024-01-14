from django.apps import AppConfig


class AcademiaAppConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'academia_app'

    def ready(self):
        # signal handlers are imported here
        from . import signals
