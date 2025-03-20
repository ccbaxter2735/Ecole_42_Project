from django.conf import settings
from django.db import models
# from django.contrib.auth import get_user_model
#
# # Obtenir le modèle utilisateur
# User = get_user_model()

# room de chat
class Room(models.Model):
    name = models.CharField(max_length=255)
    slug = models.SlugField(unique=True)

# partie chat du site
class Message(models.Model):
    # room = models.ForeignKey(Room, related_name='messages', on_delete=models.CASCADE)
    user = models.ForeignKey(settings.AUTH_USER_MODEL, related_name='user_message', on_delete=models.CASCADE)
    content = models.TextField()
    date_added = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.content[:50]

    class Meta:
        ordering = ('date_added',)
