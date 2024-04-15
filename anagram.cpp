#include "anagram.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cctype>
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

bool anagram()
{
    std::cout << "Ah, you've proven yourself worthy. Well, we meet again. Until then, solve the anagram below." << std::endl;

    // Open the file containing the words
    std::ifstream file("anagram_words.txt");

    // Read all the words from the file into a vector
    std::vector<std::string> words;
    std::string word;
    while (file >> word)
    {
        words.push_back(word);
    }

    // Close the file
    file.close();

    // Seed the random number generator
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);

    // Randomly choose a word from the vector
    std::uniform_int_distribution<int> dist(0, words.size() - 1);
    int randomIndex = dist(engine);
    std::string chosenWord = words[randomIndex];

    // Jumble the characters of the chosen word
    std::string jumbledWord = chosenWord;
    std::shuffle(jumbledWord.begin(), jumbledWord.end(), engine);

    // Present the jumbled word to the user
    std::cout << jumbledWord << std::endl;

    // Initialize the number of chances and user's guess
    const int maxChances = 3;
    int chances = 0;
    std::string guess;

    while (chances < maxChances)
    {
        std::cout << "";
        std::cin >> guess;

        // Convert both the chosen word and the guess to lowercase
        std::transform(chosenWord.begin(), chosenWord.end(), chosenWord.begin(), ::tolower);
        std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess == chosenWord)
        {
            std::cout << "That is correct!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "That is incorrect. Try again!" << std::endl;
            chances++;
        }
    }

    std::cout << "Ah, the Dark Knight fails, yet again." << std::endl;
    return false;
}
