total = 50

while total > 0:
    print("Amount Due:", total)
    paid = int(input("Insert Coin: "))
    if paid not in [5, 10, 25]:
        continue
    total -= paid

if total <= 0:
    print("Change Owed:", abs(total))