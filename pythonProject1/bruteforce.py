import itertools
import string
def bruteforce(password):
    chars=string.printable.strip()
    attempts=0
    for length in range(1,len(password)+1):
        for guess in itertools.product(chars, repeat=length):
            attempts+=1
            guess=''.join(guess)
            if guess==password:
                return(attempts, guess)
    return (attempts, None)
    
password=input("Enter the Password: ")
attempts, guess=bruteforce(password)
if guess:
    print(f"Password Cracked in {attempts} attempts. The password is {guess}.")
else:
    print(f"Password Not Cracked after {attempts} attempts.")