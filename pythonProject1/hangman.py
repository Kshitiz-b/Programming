import random

# Choose a random word from the list
word_list = ["aardvark", "baboon", "camel"]
random.choice(word_list)
chosen_word = random.choice(word_list)

# Print '_' for each letter of the word
display = []
for letter in chosen_word:
    display.append("_")
# print(chosen_word)
print(display)

# keep count of tries and number of lives
lives = 6
tries = 0
game_over = False

while not game_over:
    # Ask the user to guess a letter
    guessed_letter = input("Guess a letter: ").lower()
    tries += 1

    # Check if the guessed letter is one of the letters in the chosen word
    for i in range(len(chosen_word)):
        letter = chosen_word[i]
        if letter == guessed_letter:
            display[i] = guessed_letter
    
    if guessed_letter not in chosen_word:
        lives -= 1
        if lives == 0:
            game_over = True
            print("You lose.")

    if "_" not in display:
        game_over = True
        print("You win.")

    print(f"Number of tries: {tries}\tNumber of lives: {lives}")
    print(display)
