#include "riddle.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime> // Include for seeding random number generator

using namespace std;

bool riddle() {
    string user_answer;
    int line; // Declare line variable

    srand(time(nullptr));

    do {
        line = rand()%30 + 1; // Generate a new random number
    } while (line % 2 == 0); // Keep generating until line is odd

    ifstream inputFile("riddle.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return false;
    }

    string a;

    for (int i = 0; i < line; ++i) {
        getline(inputFile, a); // Read random odd-indexed line for 'string a'
    }
    cout << a << endl;

    string answer;
    getline(inputFile, answer); // Read the line immediately following 'string a'

    cout << "Please type an answer(answer is in one word): "<<endl;
    cin >> user_answer;

    transform(user_answer.begin(), user_answer.end(), user_answer.begin(), ::tolower); // Convert user input to lowercase
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower); // Convert answer to lowercase


    if (answer == user_answer) {
        cout << "CORRECT!" << endl;
        return true;
    } else {
        cout << "That is incorrect. The actual answer is: " << answer << endl;
        return false;
    }
}
