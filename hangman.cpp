#include "hangman.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// call a random word from word.txt
// no input parameters
string getWord() {
    string word;
    vector<string> words;
    ifstream fin;
    fin.open("words.txt");

    while (getline(fin, word)) {
        words.push_back(word);
    }

    fin.close();

    srand((unsigned)time(NULL));

    // get a random index and return a word of the index position
    return words[rand() % words.size()];
}

// initial hangman figure (no hangman only hanger)
// input: an empty 2D array
// no return value
void initialHangman(char hangman[][6]) {
    // hanger figure
    // first row (_____)
    hangman[0][0] = '_';
    hangman[0][1] = '_';
    hangman[0][2] = '_';
    hangman[0][3] = '_';
    hangman[0][4] = '_';

    // second row (|   |)
    hangman[1][0] = '|';
    hangman[1][1] = ' ';
    hangman[1][2] = ' ';
    hangman[1][3] = ' ';
    hangman[1][4] = ' ';

    // third row (|    )
    hangman[2][0] = '|';
    hangman[2][1] = ' ';
    hangman[2][2] = ' ';

    // fourth row (|    )
    hangman[3][0] = '|';
    hangman[3][1] = ' ';
    hangman[3][2] = ' ';

    // fifith row (|    )
    hangman[4][0] = '|';
    hangman[4][1] = ' ';
    hangman[4][2] = ' ';

    // sixth row (|    )
    hangman[5][0] = '|';

    // hangman figure position
    // first row
    hangman[2][3] = ' ';
    hangman[2][4] = ' ';
    hangman[2][5] = ' ';

    // second row
    hangman[3][3] = ' ';
    hangman[3][4] = ' ';
    hangman[3][5] = ' ';

    // thrid row
    hangman[4][3] = ' ';
    hangman[4][4] = ' ';
    hangman[4][5] = ' ';
}

// print hangman
// input: 2D array of hangman
// no return value
void printHangman(char hangman[][6]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << hangman[i][j];
        }
        cout << endl;
    }
}

// if failed to guess a letter, add a part of hangman body
// input: hangman 2D array, an item (part of body) that will be added, row (X) and column (y) index where to add item
// no return values, change an element of hangman[x][y] (act as pass by reference)
void attemptFailure(char hangman[][6], char item, int add_x, int add_y) {
    // erase a part of body
    hangman[add_x][add_y] = item;
}

// show letter that hasn't been guessed yet
// input 1D array of alphabet
// no return value, output elements in the alphabet array
void printAlphabet(char alphabet[]) {
    cout << "\n";
    for (int i = 0; i < 26; ++i) {
        cout << alphabet[i] << " ";
        if (i == 12 || i == 25) {
            cout << endl;
        }
    }
}

// check if the player has already tried the letter
// input: alphabet array, letter that the player tried this turn
// return true if the player hasn't tried before and return false if the player had tried
bool findAlphabet(char alphabet[], char letter) {
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] == letter) {
            return true;
        }
    }
    return false;
}

// initializing guessing_word array
// input 1D array of gussing word and length of the array
// no return value
void initializeGuessingword(char guessed_word[], int len) {
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 1) {
            guessed_word[i] = ' ';
        } else {
            guessed_word[i] = '_';
        }
    }
}

// show correctly guessed letter
// input 1D array of gussing word and length of the array
// no return value, output elements of guessing_word in two rows
void printGuessingword(char guessed_word[], int len) {
    cout << "\n\n";
    for (int i = 0; i < len; ++i) {
        cout << guessed_word[i];
    }
    cout << endl;
}

// check if the player have a whole correct letters
// input the word has to be guessed and a guessed word by the player
// return true if the player guessed a whole word correctly otherwise return false
bool checkAnswer(string word, char guessed_word[]) {
    for (int i = 0; i < word.length(); ++i) {
        if (char(word[i]) != guessed_word[i * 2]) {
            return false;
        }
    }
    return true;
}

// main function
// return true if the player win or return false
bool hangman() {
    bool guess = false;
    int attempt = 0;

    // delete order: arms -> legs -> body -> head
    int add_order[7][3] = {{1, 4}, {2, 4}, {3, 4}, {3, 3}, {3, 5}, {4, 3}, {4, 5}};
    char body_order[7] = {'|', 'O', '|', '/', '\\', '/', '\\'};

    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'z', 'y'};

    // get a random word
    string word = getWord();

    // initialize guessing word
    int len = word.length() * 2;
    char *guessed_word = new char[len];
    initializeGuessingword(guessed_word, len);

    // initalize the hangman figure
    char hangman[6][6] = {};
    initialHangman(hangman);

    bool correct = false;

    while (not guess && attempt < 7 && not correct) {
        // print
        printHangman(hangman);
        printGuessingword(guessed_word, len);
        printAlphabet(alphabet);

        // get a guess letter from the player
        char letter;
        cin >> letter;
        letter = tolower(letter);

        // check if the letter is alphabet
        if (int(letter) < 97 || int(letter) > 122) {
            // nothing will happen / no reduction in attempts
        } else {
            // check if the player has already guessed this letter
            if (not findAlphabet(alphabet, letter)) {
                // nothing happen & no reduction in attempts
            } else {
                // check if the letter is in the word
                if (word.find(letter) == -1) {
                    attemptFailure(hangman, body_order[attempt], add_order[attempt][0], add_order[attempt][1]);
                    ++attempt;
                } else {
                    // find position of letter and add to guessingword
                    int i = 0;
                    while (word.find(letter, i) != -1 && i < word.length()) {
                        int pos = word.find(letter, i);
                        guessed_word[pos * 2] = letter;
                        i = pos + 1;
                    }
                }

                alphabet[int(letter) - 97] = ' ';

                // check if the player got correct answer and update the status
                correct = checkAnswer(word, guessed_word);
            }
        }
    }
    printHangman(hangman);
    printGuessingword(guessed_word, len);

    if (correct) {
        return true;
    } else {
        // show correct answer if the player couldn't get the word right
        cout << "Answer: " << word << endl;
    }

    return false;
}