from django.conf import settings
from django.contrib import admin
from .models import Dashboard
from django.contrib.auth import get_user_model
# Obtenir le modèle utilisateur
User = get_user_model()

admin.site.register(User)
admin.site.register(Dashboard)