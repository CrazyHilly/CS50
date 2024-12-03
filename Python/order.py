order = "sandwichchickenburger-burger chicken sandwich"
menu = ["burger", "fries", "chicken", "pizza", "sandwich", "onionrings", "milkshake", "coke"]
output = ""

for item in menu:
    if item in order:
        number = order.count(item)
        output += (item.capitalize() + " ") * number

print(output.strip())