import pytest
from response import validate


def test_validate():
    assert validate("malan@harvard.edu") == True
    assert validate("juliadudych@gmail.com") == True
    assert validate("1@g.com") == True
    assert validate("malan@@@harvard.edu") == False
    assert validate("juliadudych@gmail..com") == False
    assert validate("") == False
    assert validate("@") == False
    assert validate("@.com") == False
    assert validate("1@.com") == False
