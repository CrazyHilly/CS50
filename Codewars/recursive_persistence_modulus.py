import math

def persistence(n):
    num = 0
    digits = convert_to_digits(n)
    while len(digits) > 1:
        num += 1
        product = math.prod(digits)
        if product < 10:
            return num
        digits = convert_to_digits(product)
    return 0

def convert_to_digits(n):
    digits = []
    while n > 0:
        digits.append(int(n % 10))
        n //= 10
    return digits