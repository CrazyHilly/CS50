from datetime import date
import sys
import inflect


def main():
    input_date = input("Date of Birth: ")
    print(convert(calculate(verify(input_date))), "minutes")


def verify(input_date):
    try:
        birth_date = date.fromisoformat(input_date)
    except:
        print("Invalid date")
        sys.exit(1)
    else:
        if birth_date > date.today():
            print("Date of birth cannot be later than today")
            sys.exit(1)
        return birth_date


def calculate(birth_date):
    difference = date.today() - birth_date
    return difference.days * 24 * 60


def convert(minutes):
    p = inflect.engine()
    words = p.number_to_words(minutes).capitalize()
    return words.replace("and ", "")


if __name__ == "__main__":
    main()