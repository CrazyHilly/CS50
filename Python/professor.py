import random


def main():
    level = get_level()
    tries = score = 0

    for _ in range(10):
        if tries == 3:
            print(x + y)
        x = generate_integer(level)
        y = generate_integer(level)

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


def get_level():
    while True:
        try:
            level = int(input("Level: ").strip())
        except ValueError:
            continue

        if 1 <= level <= 3:
            return level


def generate_integer(level):
    match level:
        case 1:
            return random.randint(0, 9)
        case 2:
            return random.randint(10, 99)
        case 3:
            return random.randint(100, 999)


if __name__ == "__main__":
    main()