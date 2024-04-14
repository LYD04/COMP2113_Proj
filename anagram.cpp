#include "anagram.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
/* 
This anagram game presents the user with a riddle. 
The user is given 3 tries to get the correct answer.
If the user gets the correct answer within 3 trials, 
they win this part of the game and are awarded with a hostage.
However, if they fail to guess the correct answer, they lose the hostage.

The game starts with an opening sentence, congratulating the user for making it this far. 
Then it proceeds onto presenting them with a riddle. 
The user then tries to guess the answer by inputting what they think would be the right answer.
This goes on for 3 times until they have guessed the correct answer. 
Once that is done, if the user managed to get the right answer, they are congratulated
while if they fail to get the correct answer, they are presented with a dissapointing message.
*/

// prints the opening statements in a character plot animation
void typeText(const std::string& text) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << std::endl;
}

bool anagram() {
    typeText("Ah, you've proven yourself worthy. Well, we meet again. Until then, riddle me this, Batman.");
    typeText("The more there is of me, the less you see. What am I?");

    const int maxTries = 3;
    int tries = 0;

  // the user has 3 chances to get the right answer. The answer is case-insensitive.   
    while (tries < maxTries) {
        std::string userInput;
        std::cout << "";
        std::cin >> userInput;

        std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if (userInput == "darkness") {
            std::cout << "That is correct!" << std::endl;
            return true; // if the user gets the correct answer within 3 trials, they get a hostage released.
        } else {
            tries++;
            std::cout << "That is incorrect. Try again!" << std::endl;
        }
    }
// if the user fails the get it right within the 3 chances, they fail to get a hostage released
    std::cout << "Ah, the Dark Knight fails, yet again." << std::endl;
    return false;
}
