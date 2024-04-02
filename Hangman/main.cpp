// this main function is only to check if hangman.cpp is working well
#include <iostream>

#include "hangman.h"
using namespace std;

int main() {
    bool win = hangman();
    if (win) {
        cout << "you win" << endl;
    } else {
        cout << "you lost" << endl;
    }
    return 0;
}

// g++ -pedantic-errors -std=c++11 -c hangman.cpp
// g++ -pedantic-errors -std=c++11 -c main.cpp
// g++ -pedantic-errors -std=c++11 hangman.o main.o -o Hangman
// rm -f Hangman main.o hangman.o