#include "anagram.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

bool playAnagramGame()
{
    cout << "Ah, you've proven yourself worthy. Well, we meet again. Until then, solve the anagram below." << endl;

    // Open the file containing the words
    ifstream file("anagram_words.txt");

    // Read all the words from the file into a vector
    vector<string> words;
    string word;
    while (file >> word)
    {
        words.push_back(word);
    }

    // Close the file
    file.close();

    // Seed the random number generator
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine engine(seed);

    // Randomly choose a word from the vector
    uniform_int_distribution<int> dist(0, words.size() - 1);
    int randomIndex = dist(engine);
    string chosenWord = words[randomIndex];

    // Jumble the characters of the chosen word
    string jumbledWord = chosenWord;
    shuffle(jumbledWord.begin(), jumbledWord.end(), engine);

    // Present the jumbled word to the user
    cout << jumbledWord << endl;

    // Initialize the number of chances and user's guess
    const int maxChances = 3;
    int chances = 0;
    string guess;

    while (chances < maxChances)
    {
        cout << "";
        cin >> guess;

        // Convert both the chosen word and the guess to lowercase
        transform(chosenWord.begin(), chosenWord.end(), chosenWord.begin(), ::tolower);
        transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

        if (guess == chosenWord)
        {
            cout << "That is correct!" << endl;
            return true;
        }
        else
        {
            cout << "That is incorrect. Try again!" << endl;
            chances++;
        }
    }

    cout << "Ah, the Dark Knight fails, yet again." << endl;
    return false;
}
