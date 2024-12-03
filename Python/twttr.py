input = list(input("Input: "))
length = len(input)
output = ""

for i in range(length):
    if input[i].lower() not in ['e', 'u', 'i', 'o', 'a']:
        output += input[i]

print("Output:", output)