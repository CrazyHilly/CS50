import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    hours_24 = []
    minutes = "00"
    if hours_12 := re.search(r"^((?:\d|1[0-2])(?::[0-5]\d)? [AP]M) to ((?:\d|1[0-2])(?::[0-5]\d)? [AP]M)$", s.strip()):
        for i in range(2):
            time = hours_12.group(i + 1).split(" ")
            if ":" in time[0]:
                hours, minutes = time[0].split(":")
            else:
                hours = time[0]

            if "AM" in time:
                if int(hours) < 10:
                    hours = "0" + hours
                if hours == "12":
                    hours = "00"
            else:
                if hours != "12":
                    hours = str(int(hours) + 12)

            hours_24.append(hours + ":" + minutes)

        return hours_24[0] + " to " + hours_24[1]

    raise ValueError("Invalid time")


if __name__ == "__main__":
    main()