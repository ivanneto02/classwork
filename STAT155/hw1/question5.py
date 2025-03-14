import pandas as pd

def main():

    df = pd.read_csv("filtered-dataset.csv")

    intervals = [10, 20, 30, 40, 50, 60, 70, 80]

    print("IDT:`")
    for i in range(len(intervals) - 1):
        df_count = len( df.loc[ (df["IDT"] >= intervals[i]) & (df["IDT"] < intervals[i+1]) ] )
        print(f"{intervals[i]} -< {intervals[i+1]}: {df_count}")

    intervals = [1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9]

    print("\nlog_10(IDT):")
    for i in range(len(intervals) - 1):
        df_count = len( df.loc[ (df["log 10 of IDT"] >= intervals[i]) & (df["log 10 of IDT"] < intervals[i+1]) ] )
        print(f"{intervals[i]} -< {intervals[i+1]}: {df_count}")

    return

if __name__ == "__main__":
    main()