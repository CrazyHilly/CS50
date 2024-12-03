def main():
    text = input("Text: ").strip()

    letters, words, sentences = count(text)
    grade = calculate_index(letters, words, sentences)

    if grade < 2:
        print("Before Grade 1")

    elif 2 <= grade <= 16.5:
        print("Grade", grade)

    else:
        print("Grade 16+")


# Coleman-Liau index readability test
def calculate_index(letters, words, sentences):
    index = 0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8
    return round(index)


# Count letters, words, sentences
def count(text):
    letters = sentences = 0

    for c in text:
        if c.isalpha():
            letters += 1

    words = len(text.split())

    for i in range(len(text)):
        if text[i] in (".", "!", "?") and (i == len(text) - 1 or text[i + 1] == " "):
            sentences += 1

    return letters, words, sentences


if __name__ == "__main__":
    main()
