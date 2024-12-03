while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        pass
    else:
        if 1 <= height <= 8:
            break

row = 1

while height > 0:
    print(" " * (height - 1) + "#" * row + "  " + "#" * row)
    height -= 1
    row += 1
