from django.shortcuts import render
from django.conf import settings
from django.contrib.auth import login
from django.shortcuts import redirect
from django.http import JsonResponse
import requests
import os
from django.core.files.base import ContentFile
from django.contrib.auth import get_user_model
# Obtenir le modèle utilisateur
User = get_user_model()

def oauth_callback(request):
    """
    Gère le callback OAuth2 après redirection de l'API 42.
    Récupère le token et les infos utilisateur, puis connecte l'utilisateur.
    """
    code = request.GET.get("code")
    if not code:
        return JsonResponse({"error": "Code OAuth2 manquant"}, status=400)
    # Échange du code contre un token d'accès
    token_data = {
        "grant_type": "authorization_code",
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET,
        "code": code,
        "redirect_uri": "https://localhost:8080/api/oauth/callback/",
    }
    try:
        token_response = requests.post("https://api.intra.42.fr/oauth/token", data=token_data)
        token_response.raise_for_status()
        token_info = token_response.json()
    except requests.RequestException as e:
        return JsonResponse({"error": "Impossible d'obtenir le token", "details": str(e)}, status=400)

    access_token = token_info.get("access_token")
    if not access_token:
        return JsonResponse({"error": "Token d'accès manquant"}, status=400)

    # Récupération des infos utilisateur
    headers = {"Authorization": f"Bearer {access_token}"}
    try:
        user_response = requests.get(settings.OAUTH2_USER_INFO_URL, headers=headers)
        user_response.raise_for_status()
        user_data = user_response.json()
    except requests.RequestException as e:
        return JsonResponse({"error": "Impossible d'obtenir les infos utilisateur", "details": str(e)}, status=400)

    # Vérification si l'utilisateur existe déjà
    username = user_data.get("login")  # `login` est l'identifiant unique chez 42
    if not username:
        return JsonResponse({"error": "Nom d'utilisateur manquant"}, status=400)

    user, created = User.objects.get_or_create(username=username)

    image_url = user_data.get("image", {}).get("link")
    if image_url:
        try:
            # Télécharger l'image
            response = requests.get(image_url)
            response.raise_for_status()
            
            # Définir un nom de fichier unique
            image_name = f"{username}.jpg"
            image_path = os.path.join("", image_name)

            # Sauvegarder l'image dans le dossier `media/`
            user.profile_image.save(image_path, ContentFile(response.content), save=True)

        except requests.RequestException as e:
            return JsonResponse({"error": "Impossible de télécharger l'image", "details": str(e)}, status=400)

    if created:
        user.save()

    # Connexion de l'utilisateur
    try:
        login(request, user)
        user.is_42 = True
        user.is_online = True  # Met l'utilisateur en ligne
        user.save()
    except requests.RequestException as e:
        return JsonResponse({"error": "Impossible de se login", "details": str(e)}, status=400)
    # return JsonResponse({"success": True, "message": "Inscription réussie", "is_42": user.is_42, "username": user.username })# Redirige vers la page d'accueil
    return redirect("/")