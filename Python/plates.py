def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    return False if (
            len(s) < 2 or len(s) > 6
        or
            not no_symbols(s)
        or
            not is_upper_char(s[0])
        or
            not is_upper_char(s[1])
        or
            not correct_order(s[2:])
    ) else True


def is_upper_char(c):
    c = ord(c)
    return True if 65 <= c <= 90 else False


def is_number(c):
    c = ord(c)
    return True if 48 <= c <= 57 else False


def no_symbols(s):
    for c in s:
        if is_number(c) or is_upper_char(c):
            continue
        else:
            return False
    return True


def correct_order(s):
    first_number = False
    for c in s:
        if first_number and is_upper_char(c):
            return False
        if not first_number and c == "0":
            return False
        if is_number(c):
            first_number = True
    return True


main()