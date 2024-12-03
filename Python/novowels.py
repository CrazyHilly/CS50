sentence = "I love you"
vowels = ["a", "e", "u", "i", "o"]
output = ""
for c in sentence:
    a = c.isalpha()
    b = c.lower()
    if c.isalpha() and c.lower() not in vowels:
        output += c
    elif not c.isalpha():
        output += c

print(output)