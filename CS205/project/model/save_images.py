from config import *
import gzip
import matplotlib.pyplot as plt
import numpy as np 
import pandas as pd
import os

from util import *

def save_images(images, labels, mappings):
  length = len(images)

  if not os.path.exists(IMG_SAVE_PATH):
    os.makedirs(IMG_SAVE_PATH)

  for i in range(0, length):
    plt.imshow(images[i], cmap=plt.cm.binary)
    plt.axis("off")
    plt.title(
        label=f"Drawing of \"{mappings[labels[i][0]]}\"",
        fontdict={
          'fontsize': 20,
          'fontweight' : 5,
          'verticalalignment': 'baseline'
        })
    plt.savefig(IMG_SAVE_PATH + f"image{i}.png", transparent=True)

def main():
  n_samples = 100

  print("> Loading mapping")
  mapping = load_map(DATA_PATH  + MAP_FILE)
  print("> Loading labels")
  y_train = load_labs(DATA_PATH + TRAIN_Y_FILE, n_samples)
  print("> Loading images")
  x_train = load_imgs(DATA_PATH + TRAIN_X_FILE, n_samples)
  print("> Saving images")
  save_images(x_train, y_train, mapping)

if __name__ == "__main__":
    main()