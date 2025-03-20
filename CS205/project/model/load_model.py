import tensorflow.keras as keras
from keras.datasets import mnist
from keras import models
from keras.layers import Dense, Input, Conv2D, MaxPooling2D, Dropout, Flatten, BatchNormalization
from keras import backend as k
from keras.utils import to_categorical

def main(): 
    model = models.load_model('saved_models/emnist_cnn.keras')
     
if __name__ == "__main__": 
    main() 