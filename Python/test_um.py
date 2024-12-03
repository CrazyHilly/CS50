from um import count


def test_count():
    assert count("Um, thanks, um... Um, thanks, um... Um, thanks, um...") == 6
    assert count("um?") == 1
    assert count("um") == 1
    assert count("Um, thanks, um...") == 2
    assert count("") == 0
    assert count("0123") == 0
    assert count("umumum") == 0
    assert count("Umumum") == 0
    assert count("Ummm") == 0
