import pandas as pd
import re

def parse_body(x):
    # remove irrelevant
    x = re.sub(pattern=r"this/these", repl=" ", string=x)
    x = re.sub(pattern=r"\\n_+|\(_+\)", repl=" ", string=x) # removes _______
    x = re.sub(pattern=r"(\\n+|\\t+|(\s)+)", repl=" ", string=x) # removes tabs, newlines, whitespace
    x = re.sub(pattern=r"\*\*([^\]]*)\]", repl="", string=x) # removes strings in betwee ** and ]
    x = re.sub(pattern=r"\[([^\]]*)\]", repl="", string=x) # removes strings like [ANYTHINGHERE...]
    # Tokenize
    x = x.lower()
    x = re.sub(pattern=r"[^\w\s]", repl="", string=x) # removes punctuation
    x = re.sub(pattern=r"\d+", repl="", string=x) # removes numbers
    x = re.sub(pattern=r"(name)\w+", repl="", string=x) # removes strings like '(name)ANYTHINGHERE...'
    x = re.sub(pattern=r"(date)\w+", repl="", string=x) # removes strings like '(date)ANYTHINGHERE...
    x = re.sub(pattern=r"(noted)\w+", repl="", string=x) # removes strings like '(noted)ANYTHINGHERE...'
    x = re.sub(pattern=r"(id)\w+", repl="", string=x) # removes strings like '(id)ANYTHINGHERE...'
    return x.strip()

def main():
    pd.options.display.max_colwidth = 20
    pd.options.display.max_rows = 1000

    print("Creating DataFrame...")
    df = pd.read_csv("pitt-delimited.txt", sep="\n\n\n\n\n\n", header=None)
    df.rename(columns={0 : "raw_report"}, inplace=True)

    print("Separating report...")
    df[["report_num", "type_patient", "type_report", "chief_comp", "code", "rel_codes", "year", "body"]] = df["raw_report"].str.split("|", expand=True)

    print("Tokenizing body...")
    df["tok_body"] = df["body"].apply(parse_body)

    print("Saving dataset...")
    df.to_csv("./pitt-dataset.csv", index=False)
    
    print("Done!")

if __name__ == "__main__":
    main()