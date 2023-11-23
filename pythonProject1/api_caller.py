import requests

request = requests.get("https://randomuser.me/api")
print(request.status_code)
# print(request.json())

gender = request.json()['results'][0]['gender']
first_name = request.json()['results'][0]['name']['first']
last_name = request.json()['results'][0]['name']['last']
print(f"Gender is {gender} and Name is {first_name} {last_name}")
