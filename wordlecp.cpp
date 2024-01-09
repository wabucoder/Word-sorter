#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

// Define constants
constexpr int LISTSIZE = 1000;
constexpr int EXACT = 2;
constexpr int CLOSE = 1;
constexpr int WRONG = 0;

// Define ANSI color codes
const std::string GREEN = "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m";
const std::string YELLOW = "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m";
const std::string RED = "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m";
const std::string RESET = "\e[0;39m";

// Prototypes for functions
std::string get_guess(int wordsize);
int check_word(const std::string& guess, int wordsize, std::vector<int>& status, const std::string& choice);
void print_word(const std::string& guess, int wordsize, const std::vector<int>& status);

int main(int argc, char* argv[])
{
   if (argc != 2)
   {
       std::cout << "Usage: ./wordle wordsize\n";
       return 1;
   }

   int wordsize = atoi(argv[1]);

   // open correct file, each file has exactly LISTSIZE words
   std::ifstream wordlist((std::to_string(wordsize) + ".txt").c_str(), std::ios::in);
   if (!wordlist.is_open())
   {
       std::cerr << "Error opening file " << wordsize << ".txt.\n";
       return 1;
   }

   // load word file into an array of size LISTSIZE
   std::vector<std::string> options(LISTSIZE);
   for (int i = 0; i < LISTSIZE; i++)
   {
       wordlist >> options[i];
   }

   // pseudorandomly select a word for this game
   std::srand(std::time(0));
   std::string choice = options[std::rand() % LISTSIZE];

   // allow one more guess than the length of the word
   int guesses = wordsize + 1;
   bool won = false;

   // print greeting, using ANSI color codes to demonstrate
   std::cout << GREEN << "This is WORDLE50" << RESET << "\n";
   std::cout << "You have " << guesses << " tries to guess the " << wordsize << "-letter word I'm thinking of\n";

   // main game loop, one iteration for each guess
   for (int i = 0; i < guesses; i++)
   {
       std::string guess = get_guess(wordsize);

       // array to hold guess status, initially set to zero
       std::vector<int> status(wordsize, WRONG);

       // Calculate score for the guess
       int score = check_word(guess, wordsize, status, choice);

       std::cout << "Guess " << i + 1 << ": ";

       // Print the guess
       print_word(guess, wordsize, status);

       // if they guessed it exactly right, set terminate loop
       if (score == EXACT * wordsize)
       {
           won = true;
           break;
       }
   }

   // Print the game's result
   return 0;
}

std::string get_guess(int wordsize)
{
   std::string guess;

   // ensure users actually provide a guess that is the correct length
   do
   {
       std::cout << "Input a " << wordsize << "-letter word: ";
       std::cin >> guess;
   }
   while (guess.length() != wordsize);

   return guess;
}

int check_word(const std::string& guess, int wordsize, std::vector<int>& status, const std::string& choice)
{
   int score = 0;

   for (int i = 0; i < guess.length(); i++)
   {
       for (int j = 0; j < wordsize; j++)
       {
           if (guess[i] == choice[j])
           {
               if (i == j)
               {
                  score += EXACT;
                  status[i] = EXACT;
                  break;
               }
               else
               {
                  score += CLOSE;
                  status[i] = CLOSE;
               }
           }
       }
   }
   return score;
}

void print_word(const std::string& guess, int wordsize, const std::vector<int>& status)
{
   // print word character-for-character with correct color coding, then reset terminal font to normal
   for (int i = 0; i < wordsize; i++)
   {
       if (status[i] == EXACT)
       {
           std::cout << GREEN << guess[i] << RESET;
       }
       else if (status[i] == CLOSE)
       {
           std::cout << YELLOW << guess[i] << RESET;
       }
       else
       {
           std::cout << RED << guess[i] << RESET;
       }
   }
   std::cout << "\n";
   return;
}
