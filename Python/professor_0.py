import random

while True:
    try:
        level = int(input("Level: ").strip())
    except ValueError:
        continue

    if 1 <= level <= 3:
        break

match level:
    case 1:
        min = 0
        max = 9
    case 2:
        min = 10
        max = 99
    case 3:
        min = 100
        max = 999

tries = score = 0
for _ in range(10):
    if tries == 3:
        print(x + y)
    x = random.randint(min, max)
    y = random.randint(min, max)
    for _ in range(3):
        tries += 1
        try:
            answer = int(input(f"{x} + {y} = "))
        except ValueError:
            pass
        if answer == x + y:
            score += 1
            break
        print("EEE")

print(score)