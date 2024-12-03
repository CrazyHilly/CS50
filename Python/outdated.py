months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

while True:
    date = input("Date: ").strip()

    if "/" in date:
        list = date.split("/")

        if len(list) != 3:
            continue

        valid = True
        for i in range(3):
            try:
                list[i] = int(list[i])
            except ValueError:
                valid = False
                break

        if valid and 0 < list[0] <= 12 and 0 < list[1] <= 31:
            break

    else:
        list = date.split(" ")

        if len(list) != 3:
            continue

        for i in range(len(months)):
            if list[0] == months[i]:
                list[0] = i + 1
            else:
                continue

        try:
            list[1] = int(list[1][:-1])
        except ValueError:
            continue

        if 0 < list[1] <= 31 and isinstance(list[0], int):
            break

print(f"{list[2]}-{list[0]:02}-{list[1]:02}")