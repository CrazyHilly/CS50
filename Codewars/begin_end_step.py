def sequence_sum(begin_number, end_number, step):
    if begin_number > end_number or step == 0:
        return 0
    numbers = []
    numbers.append(begin_number)
    i = next = 0
    while True:
        next = numbers[i] + step
        if next > end_number:
            break
        numbers.append(next)
        i += 1
    return sum(numbers)

print(sequence_sum(20, 0, 100))


def sequence_sum2(begin_number, end_number, step):
    return sum(range(begin_number, end_number+1, step)) if step !=0 else 0

print(sequence_sum2(1, 2, 1))
