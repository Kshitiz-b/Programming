import re
if re.match("^k[^a-z][^0-9]$", "k*&"):
    print("Match")
else:
    print("Not Match")
