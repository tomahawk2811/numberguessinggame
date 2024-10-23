#include <iostream> // include the input-output stream library.
#include <cstdlib> // include the library for rand and srand
#include <ctime> // include the library for time functions
//Copyright by Tom Sullivan, Number Guessing Game from Roadmap.sh .

// this will display the welcome message, as you can see.
void displayWelcomeMessage() { //starts the function displayWelcomeMessage()
    std::cout << "Welcome to the Number Guessing Game" <<std::endl; //this will print the sentence: "Welcome to the Number Guessing Game" then end the line using std::endl;.
    std::cout << "I am thinking of a number between 1 and 1 hundred." << std::endl; //this will print the sentence: "I am thinking of a number between 1 and 1 hundred." then end the line using std::endl;.
} //end the function.

int getDifficultyLevel() { //this starts the function getDifficultyLevel()
    int choice; //creates the integer "choice";
    std::cout << "Please select the difficulty:\n"; //this will print the line for the integer "choice", first stating "Please select the difficulty."
    std::cout << "1. Easy (10 chances)\n"; //this will print the line for the integer "choice" as the first option that the user can choose.
    std::cout << "2. Medium (5 chances)\n"; // this will print the line for the integer "choice" as the second option that the user can choose.
    std::cout << "3. Hard (3 chances)\n"; // this will print the line for the integer "choice" as the third and final option that the user can choose.
    std::cin >> choice; // this allows the user to type and choose their option by using the <iostream> header, and by using the cin function.
    return choice;  // this will finalize the function getDifficultyLevel()
} 
void playGame(int chances) { //this starts the void function playGame, and initializes a integer for the chances.
    int numberToGuess = rand() % 100 + 1; //this creates the integer function "numberToGuess", which will randomly select a number between 1 and 1 hundred.
    int userGuess; //creates a integer that allows the user to guess.

    for (int attempts = 0; attempts < chances; ++attempts) { //this will count how many chances the user has left.
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
