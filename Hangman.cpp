#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string get_word() {
    string word;
    vector<string> words;
    ifstream fin;
    fin.open("words.txt");

    while (getline(fin, word)) {
        words.push_back(word);
    }

    fin.close();

    srand((unsigned)time(NULL));

    return words[rand() % words.size()];
}

void initial_hangman(char hangman[][6]) {
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
    hangman[1][4] = ' ';  // add
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

    // hangman figure
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

void print_hangman(char hangman[][6]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << hangman[i][j];
        }
        cout << endl;
    }
}

void attempt_failure(char hangman[][6], char item, int delete_x, int delete_y) {
    // erase a part of body
    hangman[delete_x][delete_y] = item;
}

int main() {
    bool guess = false;
    int attempt = 0;

    // delete order: arms -> legs -> body -> head
    int aOrder[7][3] = {{1, 4}, {2, 4}, {3, 4}, {3, 3}, {3, 5}, {4, 3}, {4, 5}};
    char bOrder[7] = {'|', 'O', '|', '/', '\\', '/', '\\'};

    // get a random word
    string word = get_word();

    // initalize the hangman figure
    char hangman[6][6] = {};
    initial_hangman(hangman);
    print_hangman(hangman);

    while (not guess && attempt < 7) {
        attempt_failure(hangman, bOrder[attempt], aOrder[attempt][0], aOrder[attempt][1]);
        print_hangman(hangman);
        ++attempt;
    }

    return 0;
}