import sys
import requests

try:
    n = float(sys.argv[1])
except ValueError:
    print("Command-line argument is not a number")
    sys.exit(1)
except IndexError:
    print("Missing command-line argument")
    sys.exit(1)

try:
    request = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
except BaseException:
    print("Error occurred")
    sys.exit(1)

response = request.json()

price = n * response["bpi"]["USD"]["rate_float"]

print(f"${price:,.4f}")