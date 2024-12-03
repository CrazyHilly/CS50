text = list(input("camelCase: "))

for i in range(len(text)):
    if 65 <= ord(text[i]) <= 90:
        text[i] = text[i].lower()
        text.insert(i, "_")

print("snake_case:", "".join(text))