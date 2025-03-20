from django.apps import AppConfig
from pathlib import Path

import tensorflow.keras as keras
from keras.datasets import mnist
from keras import models
from keras.layers import Dense, Input, Conv2D, MaxPooling2D, Dropout, Flatten, BatchNormalization
from keras import backend as k
from keras.utils import to_categorical

class EmnistmodelConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'emnistmodel'

    # Define paths
    PRETRAINED_PATH = Path("emnistmodel/model/emnist_cnn2.keras")

    # load the model
    PRETRAINED_MODEL = models.load_model(PRETRAINED_PATH)

