from validator_collection import validators


def main():
    if validate(input("What's your email address? ").strip()):
        print("Valid")
    else:
        print("Invalid")


def validate(email):
    try:
        validators.email(email)
    except:
        return False
    else:
        return True


if __name__ == "__main__":
    main()