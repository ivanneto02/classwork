GR = [ float(i) for i in GR.split(" ") ]

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