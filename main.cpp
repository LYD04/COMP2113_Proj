#include <iostream>

#include "hangman.h"
using namespace std;

int main() {
    bool win = hangman();
    return 0;
}

// g++ -pedantic-errors -std=c++11 -c hangman.cpp
// g++ -pedantic-errors -std=c++11 -c main.cpp
// g++ -pedantic-errors -std=c++11 hangman.o main.o -o Hangman