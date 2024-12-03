my_list = {}
while True:
    try:
        item = input("").strip().upper()
    except EOFError:
        print()
        break
    else:
        if item in my_list:
            my_list[item] += 1
        else:
            my_list[item] = 1

my_list = dict(sorted(my_list.items()))

for item in my_list:
    print(my_list[item], item)