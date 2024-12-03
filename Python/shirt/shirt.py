import sys, os
from PIL import Image, ImageOps


def main():
    check_filenames()

    try:
        before = Image.open(sys.argv[1])
        shirt = Image.open("shirt.png")
    except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)

    size = shirt.size
    after = ImageOps.fit(before, size)
    after.paste(shirt, shirt)
    after.save(sys.argv[2])

    before.close()
    after.close()
    shirt.close()


def check_filenames():
    if len(sys.argv) < 3:
        print("Too few command-line arguments")
        sys.exit(1)
    if len(sys.argv) > 3:
        print("Too many command-line arguments")
        sys.exit(1)

    for arg in sys.argv[1:]:
        if not arg.lower().endswith((".jpeg",".jpg",".png")):
            print("Not an image file")
            sys.exit(1)

    if len(sys.argv[2]) < 5:
        print("Filename cannot be empty")
        sys.exit(1)

    infile_format = os.path.splitext(sys.argv[1])[1]
    outfile_format = os.path.splitext(sys.argv[2])[1]

    if infile_format != outfile_format:
        print("Input and output have different extensions")
        sys.exit(1)


if __name__ == "__main__":
    main()