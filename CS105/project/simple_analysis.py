from re import X
from turtle import tilt
import pandas as pd
import matplotlib.pyplot as plt
from nltk.corpus import stopwords
from collections import Counter
import my_stopwords
import nltk
import matplotlib as mpl

nltk.download("stopwords")

# Load in stopwords
SW = stopwords.words("english")
# Adding my own stopwords
for word in my_stopwords.more_stopwords:
    SW.append(word)
# Remove duplicates
SW = set(SW)

FILENAME = "pitt-dataset-tfidf.csv"

def main():
    print(f"Reading {FILENAME}...")
    df = pd.read_csv(FILENAME)
    print(df.head(10))

    print("Filling NaN vaules with ''...")
    df["tok_body"].fillna("", inplace=True)

    print("Slicing DataFrame...")
    common_labels = ["780.99", "786.50", "789.00", "786.05", "959.8", "486", "428.0", "729.5", "414.01", "786.09"]
    df = df.loc[df["code"].isin(common_labels)]

    print(df["code"].value_counts())

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