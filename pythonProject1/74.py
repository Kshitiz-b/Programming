import re
emailid=input("Enter your email: ")
if re.match('[a-zA-Z]*\.?\_?[a-zA-Z0-9]*\@[a-zA-Z]*\.[a-zA-Z]*$',emailid):
    print("Valid")
else:
    print("Invalid")