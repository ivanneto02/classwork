from django.apps import AppConfig
from pathlib import Path

from tensorflow import keras
import keras.models

class EmnistdetectoConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'emnistdetecto'

    # Define paths
    PRETRAINED_PATH = Path("emnistmodel/model/emnist_cnn2.keras")

    # load the model
    PRETRAINED_MODEL = keras.models.load_model(PRETRAINED_PATH)