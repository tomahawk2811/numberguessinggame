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
        std::cout << "Enter your guess: ";  //this calls out "Enter your guess:", so the user can see.
        std::cin >> userGuess; // this allows the user to guess what they think it is.

        if (userGuess == numberToGuess) { //if the user guesses the correct number.
            std::cout << "Congratulations! You guessed the correct number!\n"; // tells the user that they have guessed right.
            return; //ends the function.
        } else if (userGuess < numberToGuess) { // or if it is an incorrect guess.
            std::cout << "Incorrect! The number is greater than " << userGuess << ".\n"; //then tells the user that they guessed wrong, and the number they tried guessing is greater than what they gave.
        } else { // or else
            std::cout << "Incorrect! The number is less than " << userGuess << ".\n"; // it will tell the user if the number is less than their guess.
        }
    }
    std::cout << "Sorry! You've used all your chances. The correct number was " << numberToGuess << ".\n"; // tells the user that they failed.
}
int main() { //starts the main function.
    srand(static_cast<unsigned int>(time(0))); // initializes the srand function to cast a static and unsigned integer with time 0, to start the displayWelcomeMessage() function.
    displayWelcomeMessage(); // displayWelcomeMessage

    int difficulty = getDifficultyLevel(); //Creates an integer called "getDifficultyLevel()".
    int chances; //Creates an integer called "chances".

    switch (difficulty) { //switches to the difficulty class
      case 1: //case 1 retents the chances for Easy
      chances = 10;
      std::cout << "You have selected: Easy\n";
      break;
      case 2: //case 2 retents the chances for Medium
      chances = 5;
      std::cout << "You have selected: Medium\n";
      break;
      case 3: //case 3 retents the chances for Hard.
      chances = 3; 
      std::cout << "You have selected: Hard\n"; 
      break;
    }
    playGame(chances); // starts the chances game.
return 0; // end all.
}
