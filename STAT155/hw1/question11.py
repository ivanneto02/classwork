import pandas as pd
import math
import matplotlib.pyplot as plt

def main():

    BL = "1.02	1.21	1.12	1.62	1.31	1.28	1.27	0.80	1.07	0.63 0.92	2.87	1.03	0.76	0.07	0.79	1.61	1.26	0.94	0.82".strip().replace("\t", " ").replace("\n", " ")

    BL = sorted([ float(i) for i in BL.split(" ") ])

    print(BL)

    mean = sum(BL) / len(BL)

    print(f"Mean: {mean}")

    median = 0
    if (len(BL) % 2 == 0):
        median = (BL[len(BL)//2] + BL[len(BL) // 2 - 1]) / 2 
    else:
        median = BL[len(BL) // 2]

    print(f"Median: {median}")

    print(f"Sum: {sum(BL)}")

    num = [ (i - mean)**2 for i in BL]
    num = sum(num)
    denom = len(BL) - 1
    Sx = math.sqrt(num / denom)
    
    print(f"Sx: {Sx}")

    df = pd.DataFrame(data=BL, columns=["data"])
    df["data"].plot(kind="box")
    plt.show()

    GR = "	0.53	1.05	1.24	2.15	1.53	1.00	1.09	1.06	1.80	2.04 0.90	0.81	1.40	0.62	1.51	1.01	1.09	1.77	0.99	1.13".strip().replace("\t", " ").replace("\n", " ")

    GR = sorted([ float(i) for i in GR.split(" ") ])

    print(GR)

    mean = sum(GR) / len(GR)

    print(f"Mean: {mean}")

    median = 0
    if (len(GR) % 2 == 0):
        median = (GR[len(GR)//2] + GR[len(GR) // 2 - 1]) / 2 
    else:
        median = GR[len(GR) // 2]

    print(f"Median: {median}")

    print(f"Sum: {sum(GR)}")

    num = [ (i - mean)**2 for i in GR]
    num = sum(num)
    denom = len(GR) - 1
    Sx = math.sqrt(num / denom)
    
    print(f"Sx: {Sx}")

    df = pd.DataFrame(data=GR, columns=["data"])
    df["data"].plot(kind="box")
    plt.show()

    return

if __name__ == "__main__":
    main()