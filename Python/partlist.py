lst = ["I", "wish", "I", "hadn't", "come"]
output = []
number = len(lst) - 1

for i in range(number):
    first_part = " ".join(lst[:i+1])
    second_part = " ".join(lst[i+1:])
    element = (first_part, second_part)
    output.append(element)

print(output)