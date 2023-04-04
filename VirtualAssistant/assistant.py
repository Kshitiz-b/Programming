# Import libraries
import sports
import imdb
from googlesearch import search
import requests
from bs4 import BeautifulSoup
import datetime
import speech_recognition as sr
import pyttsx3
import config
# import smtplib


# Initialize Text to Speech
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)

# Speak Function


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


# Listen to user input


def listen():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        speak("I'm Listening")
        print("Listening...")
        r.pause_threshold = 1
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)
    try:
        print("Recognizing...")
        speak('Recognizing')
        query = r.recognize_google(audio, language='en-IN')
        print("User said: {}".format(query))
    except sr.UnknownValueError:
        print("I cannot hear you")
        speak("I cannot hear you")
    except sr.RequestError:
        print("Say that again please")
        speak("Say that again please")
        return "None"
    return query


# Greeting Function


def greet():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour <= 12:
        speak("Good Morning!")
        print("Good Morning!")
    elif hour > 12 and hour < 16:
        speak("Good Afternoon!")
        print("Good Afternoon!")
    elif hour > 16 and hour < 20:
        speak("Good Evening!")
        print("Good Evening!")
    else:
        speak("Good Night!")
        print("Good Night!")
    print("Hi, I am your virtual assistant. How can I help?")
    speak("Hi, I am your virtual assistant. How can I help?")


# Configure Browser Header and URL
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36'}
URL = ''

# Check Price of stock


def check_price():
    try:
        page = requests.get(URL, headers=headers)
        soup = BeautifulSoup(page.content, 'html.parser')
        price = soup.find(
            class_='Trsdu(0.3s) Fw(b) Fz(36px) Mb(-4px) D(ib)').get_text()
        title = soup.find(class_='D(ib) Fz(18px)').get_text()
        currency = soup.find(class_='C($tertiaryColor) Fz(12px)').get_text()
        currency = currency[-3:]
    except AttributeError as e:
        return False
    return currency, title, price


# Make Google Query

def google_query(query):
    link = []
    for j in search(query, tld="in", num=10, stop=10, pause=2):
        link.append(j)
    return link


# Get Location
def get_location():
    try:
        URL = 'https://iplocation.com/'
        page = requests.get(URL, headers=headers)
        soup = BeautifulSoup(page.content, 'html.parser')
        city = soup.find(class_='city').get_text()
        country = soup.find(class_='country_name').get_text()
        latitude = soup.find(class_='lat').get_text()
        longitude = soup.find(class_='lng').get_text()
        return city, country, latitude, longitude
    except Exception as e:
        print('Error, location could not be retrieved')
        speak('Error, location could not be retrieved')

# city,country,latitude, longitude = get_location()

# Check Weather


def weather(latitude, longitude):
    try:
        api_key = config.api_key
        base_url = 'http://api.openweathermap.org/data/2.5/weather?'
        complete_url = base_url + "lat=" + \
            str(latitude) + "&lon=" + str(longitude) + "&appid=" + api_key
        response = requests.get(complete_url)
        x = response.json()
    except Exception as e:
        print("An error occurred while retrieving weather information")
        speak("An error occurred while retrieving weather information")
    if x["cod"] != "404":
        return x
    else:
        return False
# print(weather(latitude, longitude))


# Find IMDB
def find_imdb(query):
    try:
        query += ' IMDB'
        URL = google_query(query)[0]
        page = requests.get(URL, headers=headers)
        html_content = page.text
        soup = BeautifulSoup(html_content, 'lxml')
        title = soup.title.string
        title = title[0:-7]
        return title
    except Exception as e:
        print('Movie could not be found')
        speak('Movie could not be found')


# Rotten Tomatoes Score

def rotten_tomatoes_score(query):
    try:
        query += query + " Rotten Tomatoes"
        URL = google_query(query)[0]
        page = requests.get(URL, headers=headers)
        soup = BeautifulSoup(page.content, 'html.parser')
        res = soup.find(class_='mop-ratings-wrap__percentage').get_text()
        check = res.split(' ')
        for i in check:
            if len(i) > 1:
                return i
    except Exception as e:
        print('Could not retrieve tomatometer score')
        speak('Could not retrieve tomatometer score')


# Test Movie methods
query = "The Karate Kid"
moviesDB = imdb.IMDb()
movies = moviesDB.search_movie(find_imdb(query))
id = movies[0].getID()
score = rotten_tomatoes_score(find_imdb(query))
movie = moviesDB.get_movie(id)
title = movie['title']
year = movie['year']
rating = movie['rating']
directors = movie['directors']
casting = movie['cast']
print(f"{title} ({year})\nIMDB Score : {rating} ; Rotten Tomatoes Score : {score}\nDirector(s) : {directors}\nCast : {casting}")


# Sports function
def scores(query):
    try:
        result = []
        all_matches = sports.all_matches()
        keys = list(all_matches.keys())
        for j in range(len(keys)):
            temp = all_matches[keys[j]]
            matches = []
            for i in range(len(temp)):
                matches.append((str(temp[i])).lower())
            for text in matches:
                if query in text:
                    result.append(True)
                    print(
                        f'{keys[j]} : The last updated score was {text}')
                    speak(
                        f'The last updated score was {text} : {keys[j]}')
                else:
                    result.append(False)
        if True not in result:
            print('Could not retrieve game scores')
            speak('Could not retrieve game scores')
    except Exception as e:
        print('An error occurred, please try again')
        speak('An error occurred, please try again')


# def send_mail(subject, body, reciever):
#     server = smtplib.SMTP('smtp.gmail.com', 587)
#     server.ehlo()
#     server.starttls()
#     server.ehlo()
#     server.login(config.email, config.password)
#     msg = f"Subject: {subject}\n\n{body}"
#     server.sendmail(config.email, reciever, msg)
#     server.quit()


# # Main Method
# if __name__ == "__main__":
#     greet()
#     city, country, latitude, longitude = get_location()
#     while True:
#         query = listen().lower()
#         if 'stock' in query:
#             query += query + " Yahoo Finance"
#             print('Searching...')
#             speak('Searching...')
#             URL = google_query(query)[0]
#             if check_price() == False:
#                 print("Stock Price could not be calculated")
#                 speak("Stock Price could not be calculated")
#             else:
#                 currency, title, price = check_price()
#                 print("The price of {} is {} {}".format(title, price, currency))
#                 speak("The price of {} is {} {}".format(title, price, currency))
#         elif 'weather' in query or 'temperature' in query:
#             if 'in' in query and query[query.find('in') + 2:query.find('in') + 3] == ' ':
#                 try:
#                     city_name = query[query.find('in') + 3:]
#                     api_key = config.api_key
#                     base_url = 'http://api.openweathermap.org/data/2.5/weather?'
#                     complete_url = base_url + "q=" + city_name + "&appid=" + api_key
#                     response = requests.get(complete_url)
#                     x = response.json()
#                 except Exception as e:
#                     print("City could not be found")
#                     speak("City could not be found")
#                 if x["cod"] == "404":
#                     print('Please try again')
#                     speak('Please try again')
#                 else:
#                     temp = (int)((x["main"]["temp"]) - 273.15)
#                     feel = (int)((x["main"]["feels_like"]) - 273.15)
#                     min_ = (int)((x["main"]["temp_min"]) - 273.15)
#                     max_ = (int)((x["main"]["temp_max"]) - 273.15)
#                     sunrise = x["sys"]["sunrise"]
#                     sunrise = datetime.datetime.fromtimestamp(
#                         sunrise).strftime('%H:%M')
#                     sunset = x["sys"]["sunset"]
#                     sunset = datetime.datetime.fromtimestamp(
#                         sunset).strftime('%H:%M')
#                     description = x["weather"][0]["description"]
#                     print(
#                         f'The temperature is {temp}°C and it feels like {feel} °C\nThe low is {min_}°C and the high is {max_}°C\nThe predicted forecast is {description}')
#                     speak(
#                         f'The temperature is {temp} degrees celsius. It feels like {feel} degrees celsius. The low is {min_} degrees celsius and the high is {max_} degrees celsius. The predicted forecast is {description}')
#             else:
#                 x = weather(latitude, longitude)
#                 if x == False:
#                     print('Please try again')
#                     speak('Please try again')
#                 else:
#                     temp = (int)((x["main"]["temp"]) - 273.15)
#                     feel = (int)((x["main"]["feels_like"]) - 273.15)
#                     min_ = (int)((x["main"]["temp_min"]) - 273.15)
#                     max_ = (int)((x["main"]["temp_max"]) - 273.15)
#                     sunrise = x["sys"]["sunrise"]
#                     sunrise = datetime.datetime.fromtimestamp(
#                         sunrise).strftime('%H:%M')
#                     sunset = x["sys"]["sunset"]
#                     sunset = datetime.datetime.fromtimestamp(
#                         sunset).strftime('%H:%M')
#                     description = x["weather"][0]["description"]
#                     print(
#                         f'The temperature is {temp}°C and it feels like {feel} °C\nThe low is {min_}°C and the high is {max_}°C\nThe predicted forecast is {description}')
#                     speak(
#                         f'The temperature is {temp} degrees celsius. It feels like {feel} degrees celsius. The low is {min_} degrees celsius and the high is {max_} degrees celsius. The predicted forecast is {description}')
#                     now = int(datetime.datetime.now().hour)
#                     temp = sunrise[0:2]
#                     temp = int(temp)
#                     delta_og = int(sunset[0:2])
#                     if delta_og > 12:
#                         delta = delta_og - 12
#                     if now > temp and now < delta_og:
#                         minutes = sunset.find(":")
#                         time = '' + str(delta) + sunset[minutes:]
#                         print(f"The sun will fall at {time} pm today")
#                         speak(f"The sun will fall at {time} pm today")
#                     elif now < temp:
#                         print(f"The sun will rise at {sunrise} am today")
#                         speak(f"The sun will rise at {sunrise} am today")
#         elif 'movie' in query or 'documentary' in query:
#             try:
#                 print(f'Searching for {query}...')
#                 speak(f'Searching database for {query}')
#                 moviesDB = imdb.IMDb()
#                 movies = moviesDB.search_movie(find_imdb(query))
#                 id = movies[0].getID()
#                 score = rotten_tomatoes_score(find_imdb(query))
#                 movie = moviesDB.get_movie(id)
#                 title = movie['title']
#                 year = movie['year']
#                 rating = movie['rating']
#                 directors = movie['directors']
#                 casting = movie['cast']
#                 this = ''
#                 for i in range(8):
#                     this += str(casting[i]) + ', '
#                 if len(directors) != 1:
#                     out = (f'Directed by {str(directors[0])} and ')
#                     del directors[0]
#                     for i in range(len(directors)):
#                         if i != len(directors) - 1:
#                             out += (f'{str(directors[i])} and ')
#                         else:
#                             out += (str(directors[i]))
#                 else:
#                     out = (f'Directed by : {str(directors[0])}')
#                 print(
#                     f'{title} ({year})\nIMDB - {rating}\nRotten Tomato - {score}')
#                 print(out)
#                 print(f'Cast includes : {this}')
#                 speak(
#                     f'{title} is a {year} movie with an IMDB rating of {rating} and a Rotten Tomato score of {score} {out}. Notable cast members include {this}')
#                 print('Would you like to hear the synopsis?')
#                 speak('Would you like to hear the synopsis?')
#                 query = listen().lower()
#                 keys = list(movie.keys())
#                 if 'yes' in query:
#                     if 'plot outline' not in keys:
#                         synopsis = movie['plot'][0]
#                     else:
#                         synopsis = movie['plot outline']
#                     print(synopsis)
#                     speak(synopsis)
#             except Exception as e:
#                 print('Could not retrive movie title')
#                 speak('Could not retrive movie title')
#         elif 'series' in query or 'tv' in query:
#             try:
#                 print(f'Searching for {query}...')
#                 speak(f'Searching database for {query}')
#                 seriesDB = imdb.IMDb()
#                 query = find_imdb(query)
#                 query = query[0:query.find('(TV Series')]
#                 res = seriesDB.search_movie(query)
#                 id = res[0].getID()
#                 score = rotten_tomatoes_score(query)
#                 series = seriesDB.get_movie(id)
#                 name = series['smart canonical title']
#                 kind = series['kind']
#                 length = series['series years']
#                 keys = list(series.keys())
#                 if 'seasons' in keys:
#                     seasons = series['seasons']
#                 else:
#                     seasons = ''
#                 rating = series['rating']
#                 if 'plot outline' not in keys:
#                     synopsis = series['plot'][0]
#                 else:
#                     synopsis = series['plot outline']
#                 casting = series['cast']
#                 if seasons != '':
#                     print(
#                         f'{name} is a {kind} that has an IMDB rating of {rating} and a Rotten Tomato score of {score} with {seasons} seasons. The series has been ongoing from {length}')
#                     speak(
#                         f'{name} is a {kind} that has an IMDB rating of {rating} and a Rotten Tomato score of {score}with {seasons} seasons. The series has been ongoing from {length}')
#                 else:
#                     print(
#                         f'{name} is a {kind} that has an IMDB rating of {rating} and a Rotten Tomato score of {score}. The series has been ongoing from {length}')
#                     speak(
#                         f'{name} is a {kind} that has an IMDB rating of {rating} and a Rotten Tomato score of {score}. The series has been ongoing from {length}')
#                 this = ''
#                 for i in range(8):
#                     this += str(casting[i]) + ', '
#                 print(f'Cast includes : {this}')
#                 speak(f'Cast includes : {this}')
#                 print('Would you like to hear the synopsis?')
#                 speak('Would you like to hear the synopsis?')
#                 query = listen().lower()
#                 if 'yes' in query:
#                     print(f'{synopsis}')
#                     speak(synopsis)
#             except Exception as e:
#                 print('Could not retrive requested information')
#                 speak('Could not retrive requested information')
#         elif 'score' in query:
#             query = query.replace(' score', '')
#             scores(query)
#         elif 'send' in query and 'email' in query:
#             try:
#                 print('Who do you want to send the email to?')
#                 speak('Who do you want to send the email to?')
#                 reciever = listen()
#                 print('What is the subject?')
#                 speak('What is the subject?')
#                 subject = listen()
#                 print('What is the message?')
#                 speak('What is the message?')
#                 message = listen()
#                 print(
#                     f'Send to : {reciever}\nSubject : {subject}\nMessage : {message}\nAre you sure you want to send the message?')
#                 speak(
#                     f'Email is being sent to {reciever}. The subject is {subject}. The message says {message}. Are you sure you want to send the message?')
#                 query = listen().lower()
#                 if 'yes' in query:
#                     send_mail(subject, message, reciever)
#                     print('Email successfully sent!')
#                     speak('Email successfully sent!')
#                 else:
#                     print('Cancelled!')
#                     speak('Cancelled!')
#             except Exception as e:
#                 print('An error occurred, email could not be sent!')
#                 speak('An error occurred, email could not be sent!')
#         elif "my name" in query:
#             print('Zaki')
#             speak('Zaki')
#         elif 'the time' in query:
#             time = datetime.datetime.now().strftime("%H:%M")
#             now = int(datetime.datetime.now().hour)
#             if now < 12:
#                 print(f"It is {time} am now")
#                 speak(f"It is {time} am now")
#             else:
#                 if now > 12:
#                     now = now - 12
#                 minutes = int(datetime.datetime.now().minute)
#                 print(f"It is {now}:{minutes} pm now")
#                 speak(f"It is {now}:{minutes} pm now")
#         elif ('hey' in query and query[query.find('hey') + 3:query.find('hey') + 4] == '' or query[query.find('hey') + 3:query.find('hey') + 4] == ' ') or ('hi' in query and query[query.find('hi') + 2:query.find('hi') + 3] == '' or query[query.find('hi') + 2:query.find('hi') + 3] == ' ') or ('hello' in query and query[query.find('hello') + 5:query.find('hello') + 6] == '' or query[query.find('hello') + 5:query.find('hello') + 6] == ' '):
#             print('Hey there')
#             speak('Hey there!')
#         elif ('stop' in query and query[query.find('stop') + 4:query.find('stop') + 5] == '') or ('thank you' in query and query[query.find('thank you') + 9:query.find('thank you') + 10] == ''):
#             print('Have a wonderful day!')
#             speak('Have a wonderful day!')
#             break
