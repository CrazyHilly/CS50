import re

text = "12:00 AM to 12:00 PM"
if match := re.search(r"^((?:\d|1[0-2])(?::[0-5]\d)? (A|P)M) to ((?:\d|1[0-2])(?::[0-5]\d)? [AP]M)$", text):
    print("yes")
else:
    print("No")