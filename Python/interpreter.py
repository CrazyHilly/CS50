input = input("Expression: ").split()

x = float(input[0])
y = input[1]
z = float(input[2])

match y:
    case "*":
        result = x * z
    case "/":
        result = x / z
    case "-":
        result = x - z
    case "+":
        result = x + z

print(f"{result:.1f}")