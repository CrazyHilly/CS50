import sys

if len(sys.argv) < 2:
    print("Too few command-line arguments")
    sys.exit(1)
if len(sys.argv) > 2:
    print("Too many command-line arguments")
    sys.exit(1)
if not sys.argv[1].endswith(".py"):
    print("Not a Python file")
    sys.exit(1)

try:
    file = open(sys.argv[1])
except FileNotFoundError:
    print("File does not exist")
    sys.exit(1)

counter = 0
for line in file.readlines():
    line = line.strip()
    if line != "" and not line.startswith("#"):
        counter += 1
print(counter)
file.close()