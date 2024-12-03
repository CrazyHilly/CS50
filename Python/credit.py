def main():
    number = input("Number: ").strip()

    if not is_valid_by_luhn(number):
        print("INVALID")

    elif len(number) == 15 and number[:2] in ("34", "37"):
        print("AMEX")

    elif len(number) == 16 and number[:2] in ("51", "52", "53", "54", "55"):
        print("MASTERCARD")

    elif len(number) in (13, 16) and number[0] == "4":
        print("VISA")

    else:
        print("INVALID")


# Hans Peter Luhn algorithm that checks card validity
def is_valid_by_luhn(number):
    sum = get_sum(int(number))
    return sum % 10 == 0


def get_sum(number):
    index = sum = 0

    while number > 0:
        digit = number % 10  # get last digit
        number //= 10  # truncate last digit from number

        if digit == 0:
            index += 1
            continue

        if index % 2 != 0:
            digit *= 2  # multiply digits from odd positions

            if digit >= 10:
                digit = digit % 10 + digit // 10

        sum += digit  # add all digits from even positions and multiplied digits from odd postitions
        index += 1

    return sum


if __name__ == "__main__":
    main()
