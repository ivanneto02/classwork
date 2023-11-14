from numpy import ndarray
import pandas as pd
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import CountVectorizer

def clean_list(x):
    x.replace
    return x

def main():

    pd.options.display.max_colwidth = 250
    
    df = pd.read_csv("./test.csv")
    df["tfidf"] = df["tfidf"].apply(eval)

    for i, l in enumerate(df["tfidf"]):
        print("list", i, "is", type(l))

    print(df.head(10))

if __name__ == "__main__":
    main()