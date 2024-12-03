class Jar:
    def __init__(self, capacity=12):
        self.volume = capacity
        self.amount = 0
        if self.volume < 0 or not isinstance(self.volume, int):
            raise ValueError

    def __str__(self):
        string = '🍪' * self.amount
        return string

    def deposit(self, n):
        if self.amount + n > self.volume or n < 0:
            raise ValueError
        self.amount += n

    def withdraw(self, n):
        if n > self.amount or n < 0:
           raise ValueError
        self.amount -= n

    @property
    def capacity(self):
        return self.volume

    @property
    def size(self):
        return self.amount


def main():
    jar = Jar(5)
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(6)
    print(str(jar))
    jar.withdraw(5)
    print(str(jar))
    print(str(jar.amount))

main()