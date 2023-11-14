import pandas as pd
import fasttext as ft
from nltk.corpus import stopwords
import nltk
from regex import W
import my_stopwords
from collections import Counter
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer

nltk.download("stopwords")

# Load in stopwords
SW = stopwords.words("english")
# Adding my own stopwords
for word in my_stopwords.more_stopwords:
    SW.append(word)
# Remove duplicates
SW = set(SW)

FILENAME = "./pitt-dataset.csv"

def filter_words(x):
    words = x.split()
    words = filter(lambda w: w not in SW, words)
    words = " ".join(words)
    return words

def main():
    pd.options.display.max_colwidth = 500
    pd.options.display.max_rows = 50

    features = 100

    print(f"Reading {FILENAME}...")
    df = pd.read_csv(FILENAME)

    print("Filling NaN vaules with ''...")
    df["tok_body"].fillna("", inplace=True)

    print("Filter all words...")
    df["tok_body_filt"] = df["tok_body"].apply(filter_words)

    print("Compute counter...")
    cv = CountVectorizer(max_features=features)
    word_counts = cv.fit_transform(df["tok_body_filt"])

    print("Computing TFIDF...")
    tfidf = TfidfTransformer()
    tfidf.fit(word_counts)
    tfidf_corpus = tfidf.transform(word_counts)

    # for x in tfidf_corpus:
    #     print(x.toarray())

    # return

    print("Creating TFIDF column...")
    new_df = pd.DataFrame(np.array([ x.toarray()[0] for x in tfidf_corpus ]), columns=[ str(i) for i in range(features) ])

    print("Saving...")
    new_df.to_csv("./tfidf-train.csv", index=False)

if __name__ == "__main__":
    main()