import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    if not re.search(r"^<iframe src=\"https?://(?:www\.)?youtube\.com/embed/.*\"></iframe>$", s):
        return None
    video_name = s.split("/")
    return "https://youtu.be/" + video_name[-2][:-3]


if __name__ == "__main__":
    main()