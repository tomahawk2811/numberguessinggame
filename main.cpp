#include <iostream>
#include <cstdlib>
#include <ctime>
//Copyright by Tom Sullivan, Number Guessing Game from Roadmap.sh .
void displayWelcomeMessage() {
    std::cout << "Welcome to the Number Guessing Game" <<std::endl;
    std::cout << "I am thinking of a number between 1 and 1 hundred." << std::endl;
}

int getDifficultyLevel() {
    int choice;
    std::cout << "Please select the difficulty:\n";
    std::cout << "1. Easy (10 chances)\n";
    std::cout << "2. Medium (5 chances)\n";
    std::cout << "3. Hard (3 chances)\n";
    std::cin >> choice;
    return choice;
} 
void playGame(int chances) {
    int numberToGuess = rand() % 100 + 1; 
    int userGuess;

    for (int attempts = 0; attempts < chances; ++attempts) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess == numberToGuess) {
            std::cout << "Congratulations! You guessed the correct number!\n";
            return;
        } else if (userGuess < numberToGuess) {
            std::cout << "Incorrect! The number is greater than " << userGuess << ".\n";
        } else {
            std::cout << "Incorrect! The number is less than " << userGuess << ".\n";
        }
    }
    std::cout << "Sorry! You've used all your chances. The correct number was " << numberToGuess << ".\n";
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    displayWelcomeMessage();

    int difficulty = getDifficultyLevel();
    int chances;

    switch (difficulty) {
      case 1:
      chances = 10;
      std::cout << "You have selected: Easy\n";
      break;
      case 2:
      chances = 5;
      std::cout << "You have selected: Medium\n";
      break;
      case 3:
      chances = 3;
      std::cout << "You have selected: Hard\n"; 
      break;
    }
    playGame(chances);
return 0;
}