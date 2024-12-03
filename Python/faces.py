def main():
    print(convert(input("")))


def convert(text):
    text = text.replace(":)", "🙂")
    text = text.replace(":(", "🙁")
    return text


if __name__ == '__main__':
    main()