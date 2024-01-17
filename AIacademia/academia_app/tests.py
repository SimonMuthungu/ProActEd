from django.contrib.auth import get_user_model
from django.test import Client, TestCase


class UserAuthenticationTest(TestCase):
    def setUp(self):
        User = get_user_model()
        self.user = User.objects.create_user(username='qw', password='changeme')
        self.client = Client()

    def test_login(self):
        login_successful = self.client.login(username='qw', password='changeme')
        self.assertTrue(login_successful)