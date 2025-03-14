import pandas as pd

def main():

    dataword = "383 352 356 360 379 425 324 395 404 373 374 371 364 367	366	328	337	393 390	369	378	357	352	407	333	398".replace('\t', ' ')
    dataword = [int(i) for i in dataword.split(" ") ]

    dataword.sort()

    if (len(dataword) % 2 == 0):
        print((dataword[ len(dataword)//2 ] + dataword[ len(dataword)//2 - 1])/2)
    else:
        print(dataword[len(dataword) // 2])

    print(dataword)

    print(f"Mean: {sum(dataword) / len(dataword)}")

    dataword = "383 352 356 360 379 425 324 395 404 373 374 371 364 367	366	328	337	393 390	369	378	357	352	407	333	398".replace('\t', ' ')
    dataword = [int(i)/60 for i in dataword.split(" ") ]

    dataword.sort()

    if (len(dataword) % 2 == 0):
        print((dataword[ len(dataword)//2 ] + dataword[ len(dataword)//2 - 1])/2)
    else:
        print(dataword[len(dataword) // 2])

    print(dataword)

    print(f"Mean: {sum(dataword) / len(dataword)}")

    return

if __name__ == "__main__":
    main()