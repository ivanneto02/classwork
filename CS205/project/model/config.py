from dotenv import load_dotenv
import os

load_dotenv()  # take environment variables from .env.
env = os.environ

DATA_PATH = env["DATA_PATH"]
TRAIN_FILE = env["TRAIN_FILE"]
TEST_FILE = env["TEST_FILE"]
MAP_FILE = env["MAP_FILE"]

# Generation of images
IMG_SAVE_PATH = "./../client/src/galleryimages/"

# Model training
NUM_CLASSES = int(env["NUM_CLASSES"])

EPOCHS = int(env["EPOCHS"])