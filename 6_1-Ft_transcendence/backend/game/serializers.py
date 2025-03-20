from rest_framework import serializers
from django.contrib.auth.password_validation import validate_password
from django.contrib.auth import get_user_model
from .models import Dashboard

# Obtenir le modèle utilisateur
User = get_user_model()

class Registration(serializers.ModelSerializer):
    password = serializers.CharField(write_only=True)

    class Meta:
        model = User
        fields = ('username', 'password')

    def validate_user(selfself, value):
        '''
        check si user existe deja
        '''
        if User.objects.filter(username=value).exists():
            raise serializers.ValidationError("erreur: cet username existe deja")
        return value

    def create(self, validated_data):
        '''
        creer et sauvegarde new user
        '''
        user = User(
            username=validated_data['username']
        )
        user.set_password(validated_data['password'])
        user.save()
        return user

class ChangePasswordSerializer(serializers.Serializer):
    new_password = serializers.CharField(write_only=True)

    def validate_new_password(self, value):
        """
        Vérifie que le nouveau mot de passe respecte les règles de sécurité.
        """
        validate_password(value)  # Utilise les validations Django
        return value

class ChangeUsernameSerializer(serializers.Serializer):
    new_username = serializers.CharField(max_length=25)

    def validate_new_username(self, value):
        """
        Vérifie que le username est unique et valide.
        """
        if User.objects.filter(username=value).exists():
            raise serializers.ValidationError("Ce nom d'utilisateur est déjà pris.")
        return value

class DashboardSerializer(serializers.ModelSerializer):
    class Meta:
        model = Dashboard
        fields = ['username', 'enemy_name', 'user_score', 'enemy_score', 'created_at']
        read_only_fields = ['created_at']

class UserAvatarSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ["avatar"]

class UserSerializer(serializers.ModelSerializer):
    friends = serializers.PrimaryKeyRelatedField(many=True, queryset=User.objects.all())

    class Meta:
        model = User
        fields = ["id", "username", "avatar", "match_lost", "match_win", "created_at", "friends"]


