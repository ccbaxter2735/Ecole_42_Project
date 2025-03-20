import uuid
from django.conf import settings
from django.db import models
from django.contrib.auth.models import AbstractUser
from django.core.serializers import serialize
from django.http import JsonResponse

class Dashboard(models.Model):
    username = models.CharField(max_length=100, null=True, blank=True)
    enemy_name = models.CharField(max_length=100)
    user_score = models.IntegerField()
    enemy_score = models.IntegerField()
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"{self.username}, {self.user_score} -/- {self.enemy_score}, {self.enemy_name}"

    @staticmethod
    def get_user_history(user):
        """
        Récupère tous les éléments Dashboard associés à un utilisateur,
        triés par date décroissante, et retourne les données en JSON.
        """
        dashboards = Dashboard.objects.filter(username=user.username).order_by("-created_at")
        data = [
            {   "username": dashboard.username,  # Récupère directement le username
                "enemy_name": dashboard.enemy_name,
                "user_score": dashboard.user_score,
                "enemy_score": dashboard.enemy_score,
                "created_at": dashboard.created_at,
            }
            for dashboard in dashboards
        ]
        return JsonResponse(data, safe=False)
    
    
def default_avatar():
    return 'images/default-profile.jpg'

class User(AbstractUser):
    """
    Utilisateur personnalise
    """
    id = models.UUIDField(primary_key=True, default=uuid.uuid4, editable=False, unique=True)
    username = models.CharField(max_length=25, unique=True, null=False)
    match_lost = models.IntegerField(default=0)
    match_win = models.IntegerField(default=0)
    created_at = models.DateTimeField(auto_now_add=True)
    profile_image = models.ImageField(null=True, blank=True, default="images/default-profile.jpg", upload_to="images/")
    friends = models.ManyToManyField("self", symmetrical=True, blank=True)
    is_online = models.BooleanField(default=False)
    is_42 = models.BooleanField(default=False)
    language = models.CharField(default="en")

    def __str__(self):
        return f"{self.username} - {self.id} - {self.created_at}"

    @staticmethod
    def addwin(user):
        user.match_win += 1
        user.save()

    @staticmethod
    def addlose(user):
        user.match_lost += 1
        user.save()

    

    @staticmethod
    def showuser(username):

        infos = User.objects.filter(username=username)
        user_data = [
            {
                "username": info.username,
                "match_win": info.match_win,
                "match_lost": info.match_lost,
                "created_at": info.created_at.strftime('%Y-%m-%d %H:%M:%S'),
            }
            for info in infos
        ]
        return JsonResponse(user_data, safe=False)

    @staticmethod
    def showfriend(user):
        user_data = [
            {"username": friend.username, "is_online": friend.is_online}
            for friend in user.friends.all()
        ]
        return JsonResponse(user_data, safe=False)

    @staticmethod
    def showleader():
        """
        donne la liste des joueurs trie par partie gagnee
        """
        users = User.objects.all().order_by('-match_win')  # Trier par match_win décroissant
        user_data = [
            {
                "username": user.username,
                "match_win": user.match_win,
                "match_lost": user.match_lost,
                "created_at": user.created_at.strftime('%Y-%m-%d %H:%M:%S'),
            }
            for user in users
        ]
        return JsonResponse(user_data, safe=False)
    
    @staticmethod
    def listUser(user):
        """
        donne la liste des joueurs 
        """
        users = User.objects.exclude(username=user.username).order_by('username')  # Trier par ordre alphabetique
        
        user_data = [
            {
                "username": us.username,
                "is_online": us.is_online, # Retourne True si l'utilisateur est connecté, sinon False.
                "is_friend": us in user.friends.all(), 
            }
            for us in users
        ]
        return JsonResponse(user_data, safe=False)
