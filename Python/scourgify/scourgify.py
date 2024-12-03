import sys, csv


def main():
    infile, outfile = open_file()
    reader = csv.DictReader(infile)
    writer = csv.DictWriter(outfile, fieldnames=["first", "last", "house"])
    writer.writeheader()
    for row in reader:
        last, first = row["name"].split(", ")
        house = row["house"]
        writer.writerow({"first": first, "last": last, "house": house})

    infile.close()
    outfile.close()

def open_file():
    if len(sys.argv) < 3:
        print("Too few command-line arguments")
        sys.exit(1)
    if len(sys.argv) > 3:
        print("Too many command-line arguments")
        sys.exit(1)
    if not sys.argv[1].lower().endswith(".csv") or not sys.argv[2].lower().endswith(".csv"):
        print("Not a CSV file")
        sys.exit(1)
    if len(sys.argv[2]) < 5:
        print("Filename cannot be empty")
        sys.exit(1)

    try:
        infile = open(sys.argv[1])
        outfile = open(sys.argv[2], "w")
    except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)

    return infile, outfile


if __name__ == "__main__":
    main()