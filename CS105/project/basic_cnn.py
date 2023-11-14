from re import X
from turtle import tilt
from xml.etree.ElementPath import prepare_child
from xml.sax import default_parser_list
import pandas as pd
import matplotlib.pyplot as plt
from nltk.corpus import stopwords
from collections import Counter
import my_stopwords
import nltk
import matplotlib as mpl
import numpy as np

import keras
import tensorflow as tf

from sklearn import preprocessing
from sklearn.utils import shuffle

FILENAME_LABEL = "pitt-dataset-tfidf.csv"
FILENAME_DATA = "tfidf-train.csv"

def main():
    features = 100

    print(f"Reading {FILENAME_DATA}...")
    df_data = pd.read_csv(FILENAME_DATA)
    print(f"Reading {FILENAME_LABEL}...")
    df_label = pd.read_csv(FILENAME_LABEL)

    # Put together the label and the training
    df = pd.concat([df_label["code"], df_data], axis=1)
    # Shuffle the dataset
    df = shuffle(df)

    print("Slicing DataFrame...")
    common_labels = ["780.99", "786.50", "789.00", "786.05", "959.8", "486", "428.0", "729.5", "414.01", "786.09"]
    df = df.loc[df["code"].isin(common_labels)]
    encode = preprocessing.LabelEncoder()
    encode.fit(df["code"])
    df["code"] = encode.transform(df["code"])

    print(df.head(10))
    print(df.shape)

    test_split = 0.2
    test_size = int(len(df)*test_split)
    val_split = 0.1
    val_size = int(len(df)*val_split)

    df_train = df[:test_size]
    df_test = df[test_size:]
    df_val = df_train[:val_size]
    df_train = df_train[val_size:]

    print("Get data...")
    x_train = df_train[[ str(i) for i in range(features) ]].astype(float)
    y_train = df_train["code"]

    x_test = df_test[[ str(i) for i in range(features) ]].astype(float)
    y_test = df_test["code"]

    x_val = df_val[[ str(i) for i in range(features) ]].astype(float)
    y_val = df_val["code"]

    print(x_train.head(10))

    print("Data shape")
    print(f"    - x_train shape: {x_train.shape}")
    print(f"    - y_train shape: {y_train.shape}")

    x_in = keras.layers.Input(shape=(features))
    x = keras.layers.Conv1D(filters=5, kernel_size=6, activation="relu", name="conv_1")(x_in)
    x = keras.layers.MaxPooling1D(pool_size=10, name="maxpool_2")(x)
    x = keras.layers.Conv1D(filters=5, kernel_size=6, activation="relu", name="conv_3")(x)
    x = keras.layers.MaxPooling1D(pool_size=5, name="maxpool_4")(x)
    x = keras.layers.Dense(1024, activation="relu", name="dense_5")(x)
    x = keras.layers.Dense(1024, activation="relu", name="dense_6")(x)
    x = keras.layers.Dense(1024, activation="relu", name="dense_7")(x)
    x_out = keras.layers.Dense(10, activation="softmax", name="softmax")(x)

    model = keras.Model(inputs=x_in, outputs=x_out)

    # Hyperparameters
    epochs = 100
    batch_size = 128

    model.compile(
        optimizer = 'adam',
        loss = keras.losses.SparseCategoricalCrossentropy(),
        metrics = [ keras.metrics.SparseCategoricalAccuracy() ]
    )

    model.fit(
        x = x_train,
        y = y_train,
        batch_size = batch_size,
        epochs = epochs,
        validation_data=(x_val, y_val)
    )

    # print("Creating common words image...")
    # common_words(df=df, save=True)

    # print("Creating common codes image...")
    # common_codes(df=df, num=10, save=True)
    
def common_codes(df, num=10, save=True):
    plt.figure(figsize=(20, 10))
    df["code"].value_counts()[:num].plot(kind="bar")
    plt.title(f"{num} common codes")
    plt.xlabel("Code")
    plt.ylabel("Code Count")
    if save:
        plt.savefig(fname="./imgs/code_counts.png", dpi=1000)

def common_words(df, save=True):
    words = " ".join(df["tok_body"]).split()
    words = filter(lambda w: w not in SW, words)

    count_words = Counter(words).most_common(100)[50:]
    print(count_words)

    x = [ count_words[i][0] for i in range(len(count_words)) ]
    y = [ count_words[i][1] for i in range(len(count_words)) ]

    plt.figure(figsize=(20, 10))
    plt.bar(x, y)
    plt.xticks(rotation=75)
    plt.xlabel("Word")
    plt.ylabel("Word Count")
    plt.title("Distribution of common words")
    if save:
        plt.savefig(fname="./imgs/word_counts.png", dpi=1000)

if __name__ == "__main__":
    main()