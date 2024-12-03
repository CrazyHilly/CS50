from jar import Jar
import pytest


def test_init():
    assert Jar(capacity=15).capacity == 15
    assert Jar(capacity=1).capacity == 1
    assert Jar(capacity=150).capacity == 150


def test_str():
    my_jar = Jar()
    assert str(my_jar) == ""
    my_jar.deposit(1)
    assert str(my_jar) == "🍪"
    my_jar.deposit(5)
    assert str(my_jar) == "🍪🍪🍪🍪🍪🍪"


def test_deposit():
    my_jar = Jar()
    assert my_jar.deposit(1) == 1
    assert my_jar.deposit(11) == 12


def test_withdraw():
    my_jar = Jar()
    my_jar.deposit(1)
    assert my_jar.withdraw(1) == 0
    my_jar.deposit(12)
    assert my_jar.withdraw(10) == 2


def test_size():
    my_jar = Jar()
    my_jar.deposit(1)
    assert my_jar.size == 1
    my_jar.deposit(11)
    assert my_jar.size == 12
    my_jar.withdraw(10)
    assert my_jar.size == 2


with pytest.raises(ValueError):
    my_jar = Jar(capacity=-5)
    my_jar = Jar(capacity=5.5)
    my_jar.deposit(20)
    my_jar.withdraw(25)