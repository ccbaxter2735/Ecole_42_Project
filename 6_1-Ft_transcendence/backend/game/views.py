from .models import Dashboard
from .forms import ProfileImageForm
from rest_framework import viewsets, status
from rest_framework.decorators import action
from rest_framework.decorators import api_view
from rest_framework.response import Response
from django.utils.decorators import method_decorator
from rest_framework.parsers import MultiPartParser, FormParser
from rest_framework import status
from rest_framework.views import APIView
from rest_framework.permissions import IsAuthenticated
from .serializers import *
from .forms import ProfileImageForm
from django.contrib.auth import get_user_model
from django.http import JsonResponse
from django.contrib.auth import authenticate, login, logout
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from django.shortcuts import get_object_or_404
import json
from rest_framework.authentication import TokenAuthentication
from rest_framework.permissions import IsAuthenticated

# Obtenir le modèle utilisateur
User = get_user_model()

# @csrf_exempt
def signup_api(request):
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            username = data.get("username")
            password = data.get("password")

            if not username or not password:
                return JsonResponse({"success": False, "message": "Champs requis manquants"}, status=400)

            if User.objects.filter(username=username).exists():
                return JsonResponse({"success": False, "message": "Nom d'utilisateur déjà pris"}, status=400)

            user = User.objects.create_user(username=username, password=password)
            login(request, user)  # 🔹 Connecte immédiatement l'utilisateur après l'inscription
            user.is_online = True  # Met l'utilisateur en ligne
            user.save()

            return JsonResponse({"success": True, "message": "Inscription réussie", "username": user.username})

        except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)

    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
def login_api(request):
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            username = data.get("username")
            password = data.get("password")
            
            user = authenticate(request, username=username, password=password)
            if user is not None:
                login(request, user)
                user.is_online = True  # Met l'utilisateur en ligne
                user.save()

                return JsonResponse({"success": True, "message": "Connexion réussie"}, status=200)
            else:
                return JsonResponse({"success": False, "message": "Identifiants incorrects"}, status=400)
        except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)
    
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
def logout_api(request):
    if request.method == "POST":
        user = request.user
        user.is_online = False  # Met l'utilisateur hors ligne
        user.save()
        logout(request)
        return JsonResponse({"success": True, "message": "Déconnexion réussie"}, status=200)
    
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

@api_view(['GET'])
@login_required
def leaderboard(request):
    """
    affiche le leaderboard trie par partie gagne
    """
    return User.showleader()

@api_view(['GET'])
@login_required
def viewHistory(request):
    """
    affiche le dashboard des parties jouees par l user
    """
    user = request.user
    return Dashboard.get_user_history(user)

@api_view(['GET'])
@login_required
def showuser(request):
    """
    donne les informations sur le present utilisateur
    """
    user = request.user  # Récupère l'utilisateur connecté
    return JsonResponse({
        "username": user.username,
        "match_win": user.match_win,
        "match_lost": user.match_lost,
        "profile_image": user.profile_image.url,
        "is_42": user.is_42,
        "lang":user.language,
    })

@login_required
def listFriend(request):
    """
    Retourne la liste des usernames des amis de l'utilisateur connecté.
    """
    if request.method == "GET":
        return User.showfriend(request.user)
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
@login_required
def addFriend(request):
    """
    Ajoute un utilisateur à la liste d'amis de l'utilisateur connecté.
    """
    try:
        data = json.loads(request.body)
        username = data.get("username")
    except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)
    user = request.user
    friend = get_object_or_404(User, username=username)
    # normalement ok car listuser n affiche pas notre nom
    if friend == user:
        return JsonResponse({"error": "Vous ne pouvez pas vous ajouter vous-même."}, status=400)

    user.friends.add(friend)
    return JsonResponse({"message": f"{friend.username} a été ajouté à votre liste d'amis."})

# @csrf_exempt
@login_required
def rmFriend(request):
    """
    Supprime un utilisateur de la liste d'amis de l'utilisateur connecté.
    """
    try:
        data = json.loads(request.body)
        username = data.get("username")
    except json.JSONDecodeError:
        return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)
    
    user = request.user
    try:
        friend = User.objects.get(username=username)
        
        if friend not in user.friends.all():
            return JsonResponse({"error": f"{friend.username} n'est pas dans votre liste d'amis."}, status=400)
        
        user.friends.remove(friend)
        return JsonResponse({"message": f"{friend.username} a été supprimé de votre liste d'amis."})
        
    except User.DoesNotExist:
        return JsonResponse({"error": "L'utilisateur n'existe pas"}, status=404)

@login_required
def listuser(request):
    """
    donne la liste de tous les utilisateur par ordre alpha
    """
    if request.method == "GET":
        return User.listUser(request.user)
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
@login_required
def addwin(request):
    """
    ajoute 1 a match win
    """
    if request.method == "POST":
        User.addwin(request.user)
        return JsonResponse({"success": True, "message": "+1 match gagné"}, status=200)
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
@login_required
def addlose(request):
    """
    ajoute 1 a match lost
    """
    if request.method == "POST":
        User.addlose(request.user)
        return JsonResponse({"success": True, "message": "+1 match perdu"}, status=200)
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# @csrf_exempt
@login_required
def changeName(request):
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            newName = data.get("newName")
            if User.objects.filter(username=newName).exists():
                return JsonResponse({"success": False, "message": "l'username n'est pas conforme ou existe deja"}, status=400)
            else:
                user = request.user
                oldName = user.username
                user.username = newName
                user.save()
                # Mise à jour des anciennes parties associées à l'ancien username
                Dashboard.objects.filter(username=oldName).update(username=newName)

                return JsonResponse({"success": True, "message": "nouveau username "}, status=200)
        except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)
    
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)


from django.middleware.csrf import get_token

from django.http import JsonResponse
from django.views.decorators.csrf import csrf_protect
from django.contrib.auth.decorators import login_required
import json

@csrf_protect  # Assure la protection CSRF
@login_required  # Vérifie que l'utilisateur est bien connecté
def changePass(request):
    if request.method == "POST":
        try:
            print("🔍 Headers reçus :", request.headers)  # Vérifie si le CSRF est bien envoyé
            print("🔍 Utilisateur connecté :", request.user)

            data = json.loads(request.body)
            new_password = data.get("new_password")

            if not new_password:
                return JsonResponse({"success": False, "message": "Nouveau mot de passe requis"}, status=400)

            user = request.user
            user.set_password(new_password)
            user.save()
            login(request, user)
            return JsonResponse({"success": True, "message": "Mot de passe mis à jour avec succès"}, status=200)

        except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)

    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

# Vue pour récupérer le CSRF token
def get_csrf_token(request):
    return JsonResponse({"csrfToken": get_token(request)})

# @csrf_exempt  # Désactiver la protection CSRF si utilisé sans authentification session
@login_required
def create_history_entry(request):
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            username = data.get("username")
            enemy_name = data.get("enemy_name")
            user_score = data.get("user_score")
            enemy_score = data.get("enemy_score")

            entry = Dashboard.objects.create(username=username, enemy_name=enemy_name, user_score=user_score, enemy_score=enemy_score)
            if entry is not None:
                return JsonResponse({"success": True, "message": "donnees sauvegarder avec succes"}, status=200)
            else:
                return JsonResponse({"success": False, "message": "donnees corrompu"}, status=400)
        except json.JSONDecodeError:
            return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)
    
    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)


@csrf_protect
@login_required
def changeImage(request):
    if request.method == 'POST':
        image_file = request.FILES.get('avatar') 

        if not image_file:
            return JsonResponse({'success': False, 'error': 'No file uploaded'}, status=400)

        request.user.profile_image = image_file
        request.user.save()

        return JsonResponse({'success': True, 'profile_image_url': request.user.profile_image.url})

    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)

def changeLanguage(request):
    if request.method == "POST":
        try:
            data = json.loads(request.body)
            lang = data.get("lang")
            user = request.user
            user.language = lang
            user.save()
            return JsonResponse({"success": True, "message": "Inscription réussie"})
        except json.JSONDecodeError:
                return JsonResponse({"success": False, "message": "Requête invalide"}, status=400)

    return JsonResponse({"success": False, "message": "Méthode non autorisée"}, status=405)      

