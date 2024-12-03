import sys
from tabulate import tabulate


def main():
    file = open_file()
    table = []
    for line in file:
        row = line.strip().split(",")
        table.append(row)

    print(tabulate(table, headers="firstrow", tablefmt="grid"))
    file.close()


def open_file():
    if len(sys.argv) < 2:
        print("Too few command-line arguments")
        sys.exit(1)
    if len(sys.argv) > 2:
        print("Too many command-line arguments")
        sys.exit(1)
    if not sys.argv[1].endswith(".csv"):
        print("Not a CSV file")
        sys.exit(1)

    try:
        file = open(sys.argv[1])
    except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)

    return file


if __name__ == "__main__":
    main()