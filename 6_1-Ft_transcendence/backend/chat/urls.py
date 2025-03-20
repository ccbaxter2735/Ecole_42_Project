from . import views
from django.urls import path

urlpatterns = [
    # path('rooms/', views.rooms, name='rooms'),
    path('', views.room, name='room'),
    ]