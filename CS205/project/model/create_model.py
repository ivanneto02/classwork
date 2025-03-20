# create + save model
# save models in folder saved_models 

# Imports 
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split

import keras
from keras.datasets import mnist
from keras import models
from keras.layers import Dense, Input, Conv2D, MaxPooling2D, Dropout, Flatten, BatchNormalization
from keras import backend as k
# from keras.utils.np_utils import to_categorical
from keras.utils import to_categorical

from config import *
import gzip
import idx2numpy

from util import *

def preprocess_data(x_train, y_train, x_test, y_test):
  img_rows, img_cols = (28, 28)

  # For 3D data, "channels_last" assumes (conv_dim1, conv_dim2, conv_dim3, channels) while 
  # "channels_first" assumes (channels, conv_dim1, conv_dim2, conv_dim3).

  if k.image_data_format() == 'channels_first':
    x_train = x_train.reshape(x_train.shape[0], 1, img_rows, img_cols)
    x_test = x_test.reshape(x_test.shape[0], 1, img_rows, img_cols)
    inpx = (1, img_rows, img_cols)
  else:
    x_train = x_train.reshape(x_train.shape[0], img_rows, img_cols, 1)
    x_test = x_test.reshape(x_test.shape[0], img_rows, img_cols, 1)
    inpx = (img_rows, img_cols, 1)

  x_train = np.rot90(np.fliplr(x_train.astype('float32')), axes=(2, 1))
  x_test = np.rot90(np.fliplr(x_test.astype('float32')), axes=(2, 1))
  x_train /= 255
  x_test /= 255

  # one hot encoding 
  y_train = to_categorical(y_train, num_classes=NUM_CLASSES)
  y_test = to_categorical(y_test, num_classes=NUM_CLASSES)

  return x_train, y_train, x_test, y_test

def plot_acc_curve(epochs, hist, list_of_metrics):
  """Plot a curve of one or more classification metrics vs. epoch."""  
  plt.figure()
  plt.xlabel("Epoch")
  plt.ylabel("Value")
  for m in list_of_metrics:
    x = hist[m]
    plt.plot(epochs[1:], x[1:], label=m)
  plt.legend()
  plt.savefig("./saved_figures/emnist_cnn2.png")
  
def create_model(my_learning_rate):
  model = models.Sequential()
  model.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(28, 28, 1)))   # defining shape  
  model.add(BatchNormalization())
  model.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(28, 28, 1)))   # defining shape  
  model.add(BatchNormalization())
  model.add(Dropout(0.2))
  model.add(Flatten())
  model.add(Dense(256, activation='relu'))
  model.add(Dropout(0.2))
  model.add(Dense(128, activation='relu'))
  model.add(Dropout(0.2))
  model.add(Dense(NUM_CLASSES, activation='softmax'))

  model.compile(optimizer=keras.optimizers.Adam(learning_rate=my_learning_rate),
                loss=keras.losses.categorical_crossentropy,
                metrics=['accuracy'])
  
  return model

def train_model(model, train_features, train_label, epochs,
                batch_size=None, validation_split=0.1):
  """Train the model by feeding it data."""
  
  history = model.fit(train_features, train_label, 
          validation_split=validation_split,
          batch_size=batch_size,
          epochs=epochs,
          shuffle=True,
          verbose=1)

  epochs = history.epoch
  hist = pd.DataFrame(history.history)

  return epochs, hist

def main():
  # Load MNIST (TODO EMNIST)
  n_train_samples = None
  n_test_samples = None

  print("> Loading and separating training data")
  train = pd.read_csv(DATA_PATH + TRAIN_FILE, nrows=n_train_samples)
  x_train = train.iloc[:, 1:].to_numpy()
  y_train = train.iloc[:, 0].to_numpy()

  print("> Loading and separating testing data")
  test = pd.read_csv(DATA_PATH + TEST_FILE, nrows=n_test_samples)
  x_test = test.iloc[:, 1:].to_numpy()
  y_test = test.iloc[:, 0].to_numpy()

  print("> Shapes:")
  print(f"    x_train: {x_train.shape}")
  print(f"    x_test: {x_test.shape}")

  print("> Preprocessing training and testing data")
  x_train, y_train, x_test, y_test = preprocess_data(x_train, y_train, x_test, y_test)

  # for i in range(0, 10):
  #   plt.imshow(x_train[i])
  #   plt.savefig(f"saved_figures/test{i}.png")
  #   print(y_train[i])

  # return

  # Hyperparameters a
  learning_rate = 0.001
  validation_split = 0.2
  batch_size = 128
  epochs = EPOCHS

  # Create Model
  print("> Creating model")
  model = create_model(learning_rate)

  # print(x_train)
  # print(y_train)

  # Train the model on the normalized training set.
  print("> Training model")
  epochs, hist = train_model(model, x_train, y_train, epochs, batch_size, validation_split)

  # Plot a graph of the metric vs. epochs.
  print("> Plotting curves")
  list_of_metrics_to_plot = ['accuracy']
  plot_acc_curve(epochs, hist, list_of_metrics_to_plot)

  # Evaluate against the test set.
  print("> Evaluating model")
  model.evaluate(x=x_test, y=y_test, batch_size=batch_size)

  print("> Saving model")
  # save model 
  if not os.path.exists("./saved_models/"):
    os.makedirs("./saved_models/")
  model.save('./saved_models/emnist_cnn2.keras')
  # once saved we can access it using
  # model = models.load_model('saved_models/emnist_cnn')

if __name__ == "__main__":
    main()

