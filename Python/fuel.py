percents = -1
while percents < 0:
    fraction = input("Fraction: ").strip().split("/")
    try:
        x = int(fraction[0])
        y = int(fraction[1])
    except ValueError:
        pass
    else:
        if x > y:
            continue
        try:
            percents = round(x / y * 100)
        except ZeroDivisionError:
            pass

if percents <= 1:
    print("E")
elif percents >= 99:
    print("F")
else:
    print(f"{percents}%")
