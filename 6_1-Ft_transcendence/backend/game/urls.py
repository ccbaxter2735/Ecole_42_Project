from . import views
from .views import *
from django.contrib.auth import views as auth_views
from django.urls import path
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    # ---------  profile + modif profile ----------------
    path('profile/', views.showuser, name='profile'),
    path("modifuser/", views.changeName, name="modiusername"),
    path("modiflang/", views.changeLanguage, name="modiflang"),
    path("modifpass/", views.changePass, name="modifpass"),
    path("get_csrf_token/", views.get_csrf_token, name="get_csrf_token"),
    path("modifavatar/", views.changeImage, name="modifavatar"),
    # ------------ leaderboard --------------------------
    path('leaderboard/', views.leaderboard, name='leaderboard'),
    # ------------ gestion des points -------------------
    path('addwin/', views.addwin, name='win'),
    path('addlose/', views.addlose, name='lose'),
    # ------------- historique --------------------------
    path('history/', views.viewHistory, name='history'),
    path("createHistoryEntry/", views.create_history_entry, name="create_history_entry"),
    # ----------- authentification ----------------------
    path('signup/', views.signup_api, name='signUp'),
    path('login/', views.login_api, name='api-login'),
    path('logout/', views.logout_api, name='api-logout'),
    # --------------  friends ---------------------------
    path('listuser/', views.listuser, name='listuser'),
    path('listfriend/', views.listFriend, name='listfriend'),
    path('friends/add/', views.addFriend, name='add_friend'),
    path('friends/remove/', views.rmFriend, name='remove_friend'),
] + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
