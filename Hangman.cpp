#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string get_word()
{
  string word;
  vector<string> words;
  ifstream fin;
  fin.open("words.txt");

  while (getline(fin, word))
  {
    words.push_back(word);
  }

  fin.close();

  srand((unsigned)time(NULL));

  return words[rand() % words.size()];
}

int main()
{
  cout << get_word() << endl;
  return 0;
}