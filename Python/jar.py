class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        self.size += n
        if self.size > self.capacity:
            raise ValueError
        return self.size

    def withdraw(self, n):
        self.size -= n
        if self.size < 0:
            raise ValueError
        return self.size

    @property
    def capacity(self):
        return self._capacity

    @capacity.setter
    def capacity(self, capacity):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError
        self._capacity = capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, size):
        self._size = size

def main():
    my_jar = Jar()
    my_jar.deposit(1)
    print(my_jar)
    my_jar.deposit(4)
    print(my_jar)
    my_jar.withdraw(1)
    print(my_jar)
    print(my_jar.size)


if __name__ == "__main__":
    main()