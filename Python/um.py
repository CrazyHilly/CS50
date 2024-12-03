import re
import sys


def main():
    print(count(input("Text: ")))


def count(s):
    substrings = re.findall(r"\b[Uu]m\b", s.strip())
    return len(substrings)


if __name__ == "__main__":
    main()