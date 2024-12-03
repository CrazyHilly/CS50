word = "OG"
upper = lower = 0
for c in word:
    if not c.isalpha():
        continue
    if c.isupper():
        upper += 1
    else:
        lower += 1

print(word.upper()) if upper > lower else print(word.lower())
