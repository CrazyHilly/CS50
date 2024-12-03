import pytest
from datetime import date, timedelta
import seasons


def test_verify():
    assert("2000-10-10") == "2000-10-10"
    assert("2022-01-01") == "2022-01-01"
    assert("1999-09-09") == "1999-09-09"


def test_verify_exit():
    with pytest.raises(SystemExit) as error:
        seasons.verify("")
        seasons.verify("2022-02")
        seasons.verify("2023.01.01")
        seasons.verify("01-01-2023")
        seasons.verify("01-2022")
        seasons.verify("22-01-01")
        seasons.verify("999-01-01")
        seasons.verify("2000-1-01")
        seasons.verify("2000-01-1")
    assert error.type == SystemExit
    assert error.value.code == 1


def test_calculate():
    assert seasons.calculate(date.today() - timedelta(days=1)) == 1440
    assert seasons.calculate(date.today() - timedelta(days=365)) == 525600
    assert seasons.calculate(date.today() - timedelta(days=(365 * 2))) == 1051200


def test_convert():
    assert seasons.convert(1440) == "One thousand, four hundred forty"
    assert seasons.convert(1) == "One"
    assert seasons.convert(0) == "Zero"
    assert seasons.convert(525600) == "Five hundred twenty-five thousand, six hundred"
    assert seasons.convert(1051200) == "One million, fifty-one thousand, two hundred"