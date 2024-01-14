from django.contrib.auth.models import Group, User
from django.db.models.signals import m2m_changed
from django.dispatch import receiver


@receiver(m2m_changed, sender=User.groups.through)
def ensure_super_admin_superuser(sender, instance, action, pk_set, **kwargs):
    if action in ["post_add", "post_remove", "post_clear"]:
        try:
            super_admin_group = Group.objects.get(name='Super Admins')
        except Group.DoesNotExist:
            return

        if super_admin_group in instance.groups.all():
            instance.is_superuser = True
        else:
            instance.is_superuser = False
        instance.save()
