import math


def persistence(n, steps=0):
    if n < 10:
        return steps
    digits = list(str(n))
    prod = math.prod(int(d) for d in digits)
    steps += 1
    return persistence(prod, steps)

result = persistence(0)
print(result)
