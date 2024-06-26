#include <iostream>
#include <vector>
#include <fstream>
#include "riddle.h"
#include "anagram.h"
#include "cursednum.h"
#include "hangman.h"
#include <thread>
#include <chrono>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

//this function print the text in a graphic game style format
void styledisp(string text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(75));
	}
    cout << endl;
}

void styledisp2(string text) { //this function outputs stylised text faster, for the graphic at the end
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(25));
        }
    cout << endl;
}

int main() {
	cout << "******************************************** GOTHAM'S GUARDIAN ********************************************" << endl;
	cout << " " << endl;
	this_thread::sleep_for(chrono::seconds(3)); //this function has been used often in order to create a mor game-like suspense

	//background set up
	styledisp("In the sprawling metropolis of Gotham City, darkness reigns as night falls upon its rain-soaked streets.");
	styledisp("Amidst the relentless downpour, a wave of crime engulfs the city,\ncasting a shadow of fear and uncertainty, awaiting the arrival of its ultimate protector.");
	cout << "BATMAN." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Batman: ";
	cout << "\033[36m";
	styledisp("The city needs me.");
	cout << "        ";
	styledisp("The deception of the day masks the darkness of the nights.");
	cout << "        ";
	styledisp("But I see it. From the shadows. There is a lot to be done.");
	cout << "        ";
	styledisp("I still have hope. There will be change.");
	cout << "\033[0m";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "The TV crackles." << endl;
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Reporter: ";
	styledisp("Now coming in, Gotham city is on the brink of collapse, once again.");
	cout << "          ";
	styledisp("We have received reports of three key city personnel missing since last night.");
	cout << "          ";
	styledisp("Those reported missing are Mayor Anthony Garcia, DA Carl Finch and Commissioner Andrew Howe.");
	cout << "          ";
	styledisp("We will keep our viewers upda -");
	styledisp("The feed cuts off into a form of live stream. A dark figure sits across with a mask on.");
	cout << "" << endl;
	cout << "Riddler: ";
	cout << "\033[32m";
	styledisp("GREEETINGS GOTHAM! Finally, we meet.");
	cout << "         ";
	styledisp("Needless to say, I think you know well enough where your leaders are, Gotham.");
	cout << "         ";
	styledisp("But don’t hate me. Hate THEM. Because justice has been DENIED.");
	cout << "         ";
	styledisp("And this, specifically, is for my dear friend, Batman.");
	cout << "         ";
	styledisp("If you want to deliver these people JUSTICE, play by my terms.");
	cout << "         ";
	styledisp("Four challenges shall be given to you in the next four days. One free hostage…per game.");
	cout << "         ";
	styledisp("Only if you win! I also have a surprise for you after the third game. Someone special for you to meet.");
	cout << "         ";
	styledisp("If you win the first three games though! See you on the other side, Batman!");
	cout << "\033[0m";
	cout << "" << endl;
	cout << "" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	vector<bool> results;
	//day 1 hangman
	styledisp("*** DAY 1 ***");
	cout << "" << endl;

	//game description
	cout << "Riddler: ";
	cout << "\033[32m";
	styledisp("Let me introduce you to a game you have probably heard of before. Let’s play some…Hangman.");
	cout << "         ";
	styledisp("I will give you some letters, but you have to guess the word.");
	cout << "         ";
	styledisp("Don’t be too confident! This game may prove to be not rewarding after all.");
	cout << "\033[0m";
	cout << "" << endl;
	
	//play hangman
	bool hangman_result = hangman();
	cout << "" << endl;
	results.push_back(hangman_result);
	if (hangman_result == true) {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Ah Batman. You've done it again. I am a man of my word. Here is your award.");
		cout << "\033[0m";
		cout << "" << endl;
		cout << "Reporter: ";
		styledisp("The Mayor has been discovered in the basement of the Gotham tower, alive, but with minor injuries-");
	}
	else {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Well well well. Mistakes were made. Looks like you can't save everyone.");
		cout << "\033[0m";
		cout << "" << endl;
		cout << "Reporter: ";
		styledisp("The Mayor's body has been found hanging from a massive tree in Robinson Park. Details inc...");
	}
	cout << "" << endl;
	this_thread::sleep_for(chrono::seconds(3));

	//Day 2 Anagram
	styledisp("*** Day 2 ***");
	cout << "" << endl;

	//game description
	cout << "Riddler: ";
	cout << "\033[32m";
	styledisp("We have seen how you perform with hangman, Batman. Let's see how good you are at decoding anagrams.");
	cout << "         ";
	styledisp("I have some \"easy\" anagrams for you, which I am sure, you can solve in a snap. GRIND ON, BATMAN!");
	cout << "\033[0m";
	cout << "" << endl;
	
	//play anagram
	bool anagram_result = anagram();
	cout << endl;
	results.push_back(anagram_result);
	if (anagram_result == true) {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Looks like you have come prepared this time... Well, I will release the next hostage.");
		cout << "         ";
		styledisp("But be rest assured, the next round will not be easy");
		cout << "\033[0m";
		cout << "" << endl;
		cout << "Reporter: ";
		styledisp("The Police have discovered the Comissioner in an abandoned apartment. He is safe -...");
	}
	else {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Ah Batman. I think you've lost your edge. How disappointing...");
		cout << "         ";
		styledisp("Maybe you prefer my way of justice...");
		cout << "\033[0m";
		cout << "" << endl;
		cout << "Reporter: ";
		styledisp("We have just received the message that the Commissioner has been found dead at the parking lot of the tower. Details...");
	}
	cout << "" << endl;
	this_thread::sleep_for(chrono::seconds(3));

	// Day 3 Cursed num
	styledisp("*** Day 3 ***");
	cout << "" << endl;
	
	//
	cout << "Riddler: ";
	cout << "\033[32m";
	styledisp("My next challenge for you is the Gambit of Gloom.");
	cout << "         ";
	styledisp("I have asked our friend, the DA to choose a number between 0 and 100. And not tell me, of course.");
	cout << "         ";
	styledisp("You have to guess a number from 1-100. After your guess, my system will reduce the range of numbers we can choose from.");
	cout << "         ";
	styledisp("And then…its my turn. The same range reduction would be executed after my turn.");
	cout << "         ";
	styledisp("Whoever lands on the cursed number first loses! Let’s play.");
	cout << "\033[0m";
	cout << "" << endl;

	//play cursed_num
	bool cursednum_result = cursednum();
	results.push_back(cursednum_result);
	if (cursednum_result == true) {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Looks like it is your lucky day, Batman.");
		cout << "         ";
		styledisp("Well, I won't hold back on you. A deal is a deal.");
		cout << "\033[0m";
		cout << "" << endl;
		cout << "Reporter: ";
		styledisp("Gotham's DA has been safely found in the city port. We think this terror reign is coming to an end...");
	}
	else {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("The Batman fails...once again.");
		cout << "         ";
		styledisp("I really expected more from you. Now the DA has to pay for your mistakes.");
		cout << "\033[0m";
		cout << "Reporter: ";
		styledisp("Shocking news coming in...The city's DA has been found dead at the City Railway office. The police are ...");
	}
	cout << "" << endl;
	//player is allowed to play the 4th game only if he/she wins the first three
	if (hangman_result == 1 && anagram_result == 1 && cursednum_result == 1) {
		//Day 4 Anagram
		this_thread::sleep_for(chrono::seconds(3));
		styledisp("*** Day 4 ***");
		cout << "" << endl;
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("You've proved yourself this time, Batman. I am impressed.");
		cout << "         ";
		styledisp("As promised, I want you to meet my final hostage. And it is...Janice Porter. Ex-DA? Remember?");
		cout << "         ";
		styledisp("Play my final challenge, and maybe you can save her...");
		cout << "         ";
		styledisp("I have added a personal touch for this final game. You guessed it correct! RIDDLES!");
		cout << "" << endl;
		cout << "\033[0m";
		
		//play riddle
		bool riddle_result = riddle();
		results.push_back(riddle_result);
		cout << endl;
		if (riddle_result = true) {
			
			cout << "Riddler: ";
			cout << "\033[32m";
			styledisp("Batman, Batman. You make my life tough. You won't get away with this next time.");
			cout << "         ";
			styledisp("You might've freed the hostages, but I have gotten my message out.");
			cout << "\033[0m";
		}
		else {
			cout << "Riddler: ";
			cout << "\033[32m";
			styledisp("Batman, Batman. You broke such a good streak. I feel sorry for you.");
			cout << "\033[0m";
			cout << "Reporter: ";
			styledisp("Another body has been discovered. It is said to be Janice Porter...Public fear is rising.");
		}
		
	}
	else {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Ah the Dark Knight fails...yet again! You have not won all challenges. So, you don't get to meet the special guest.");
		cout << "         ";
		styledisp("Maybe you can save her next time...or not?");
		cout << "\033[0m";
	}

	cout << "" << endl;

	cout << "Riddler: ";
	cout << "\033[32m";
	styledisp("Well, we will meet again. Until then, riddle me this, Batman.");
	cout << "         ";
	styledisp("The more there is of me, the less you see. What am I?");
	cout << "\033[0m";
	string ans;
	cin >> ans;
	cout << endl;
	transform(ans.begin(),ans.end(),ans.begin(),::tolower);
	if (ans == "darkness") {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Impressive...Until we meet again!");
	}
	else {
		cout << "Riddler: ";
		cout << "\033[32m";
		styledisp("Try again next time......Until we meet again!");
	}
	cout << "\033[0m";
	cout << "" << endl;
	cout << "\033[32m";
	//graphic: riddler logo
	styledisp2(" |||||||||||||||||||");
	styledisp2(" |                 |");
	styledisp2(" |       ***       |");
	styledisp2(" |    **    **     |");
	styledisp2(" |   **       **   |");
	styledisp2(" |           **    |");
	styledisp2(" |          **     |");
	styledisp2(" |         **      |");
	styledisp2(" |         **      |");
	styledisp2(" |         **      |");
	styledisp2(" |                 |");
	styledisp2(" |         **      |");
	styledisp2(" |         **      |");
	styledisp2(" |                 |");
	styledisp2(" |||||||||||||||||||");
	cout << "\033[0m";
	cout << "" << endl;
	
	//saving work progress
        int wins = 0;
        int losses = 0;
        for (int i = 0; i < results.size();i++) {
                if (results[i] == false)  {
                        losses ++;
                }
                else
                        wins ++;
        }
        ofstream fout;
        fout.open("Game_history.txt", ios::app);
        fout << "** " << wins << " wins, " << losses << " losses **" << endl;
        fout.close();
	return 0;
}

