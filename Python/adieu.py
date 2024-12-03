names = []
while True:
    try:
        names.append(input("Name: ").strip().title())
    except EOFError:
        print()
        break

output = " and ".join(names)

n = len(names)
if n > 2:
    names[n-1] = "and " + names[n-1]
    output = ", ".join(names)

print("Adieu, adieu, to", output)