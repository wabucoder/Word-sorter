Libraries and Constants:

The code includes necessary libraries (cs50.h, stdio.h, stdlib.h, string.h, time.h) and defines constants for game elements, such as the word list size and scoring values.
Main Function:

The main function initializes the game, loads a word list based on the user-specified word size, and randomly selects a word for the player to guess.
User input and command-line argument handling are implemented, ensuring correct usage and appropriate word size selection.
Word List and Random Word Selection:

The code reads a list of words from a file of a specified word size.
A word is pseudorandomly selected for each game using the srand and rand functions from time.h.
Game Loop:

The main game loop allows the player a limited number of guesses (one more than the length of the word).
For each guess, the player inputs a word, and the program calculates a score based on correctness and position.
Color-coded output is used to visually represent the correctness of each letter in the guessed word.
Feedback and Scoring:

The check_word function calculates the score for a given guess based on the selected word, distinguishing between correct letters in the correct position, correct letters in the wrong position, and incorrect letters.
User Input and Validation:

The get_guess function ensures that the player provides a guess of the correct length, prompting the user until a valid guess is provided.
Print Function:

The print_word function outputs the player's guess with color-coded feedback, enhancing the visual experience of the game.
Error Handling:

The code includes error messages for incorrect command-line usage and issues with opening the word list file.
Termination and Results:

The game terminates when the player correctly guesses the word or exhausts the allowed guesses.
The result of the game is not fully implemented, as indicated by the TODO comment.
Color Codes:

The code uses ANSI color codes to provide a visually appealing and interactive experience in the console, with different colors representing the correctness of guessed letters.

DOCUMENTATION 
I did this wordle project in 3 different languages and redid them in each language for thier own systems To prove I have the ability to delve further into fullstack realated projects.
