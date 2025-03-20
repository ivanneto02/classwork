"""django_react URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
# from django.contrib import admin # NOT NEEDED FOR NOW
from django.urls import path, include

from emnistmodel import views
from emnistdetecto import views

urlpatterns = [
    # path('admin/', admin.site.urls),
    path('', include('images.urls')),

    # machine learning model
    path("model/", views.call_model.as_view()),

    # detecto machine learning model
    path("modeld/", views.call_model.as_view()),
]