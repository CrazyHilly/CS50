import random

while True:
    try:
        level = int(input("Level: ").strip())
    except ValueError:
        continue

    if level > 0:
        break

number = random.randint(1, level)

while True:
    try:
        guess = int(input("Guess: ").strip())
    except ValueError:
        continue

    if guess <= 0:
        continue

    if guess == number:
        print("Just right!")
        break

    print("Too small!") if guess < number else print("Too large!")