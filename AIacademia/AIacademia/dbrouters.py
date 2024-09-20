# AIacademia/dbrouters.py
class DatabaseRouter:
    def db_for_read(self, model, **hints):
        """Point all read operations on bot_data models to 'bot_db'."""
        if model._meta.app_label == 'bot_data':
            return 'bot_db'
        return None

    def db_for_write(self, model, **hints):
        """Point all write operations on bot_data models to 'bot_db'."""
        if model._meta.app_label == 'bot_data':
            return 'bot_db'
        return None

    def allow_relation(self, obj1, obj2, **hints):
        """Allow relations if a model in the bot_data app is involved."""
        if obj1._meta.app_label == 'bot_data' or \
           obj2._meta.app_label == 'bot_data':
            return True
        return None

    def allow_migrate(self, db, app_label, model_name=None, **hints):
        """Ensure that the bot_data app only appears in the 'bot_db' database."""
        if app_label == 'bot_data':
            return db == 'bot_db'
        return None
