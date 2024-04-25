# COMP2113_Proj

## Table of Contents
- [Team members](#tab-1)
- [Game Intro](#tab-2)
- [Key Features](#tab-3)
- [Coding Features](#tab-4)
  
## Team members:
1.	CHUNG SIU HO, Neil 3035921851
2.	BORAR SNEHA, 3036254138
3.	LEE YEDAM, 3036181551
4.	BHATTACHARJI AYUSHMAAN, 3036102787
5.	BYUN YEJI, 3036136752

## Game Intro
You are Batman, the Dark Knight of Gotham City.  Your dearest “friend”, Riddler, came to Gotham and kidnapped four key city personnel away last night. To save them, you need to go through a series of perilous challenges set by the Riddler. Every day comes with a new challenge, tests of intelligence, luck, and gut! Do you dare to face whatever challenges lie ahead? Join and save the City!

## Key Features:
1.	Interactive storytelling: 
The player makes choices from time to time that could influence the narrative and outcome of the game.
2.	High stakes:
We are not talking money here, but lives! For every challenge you overcome, you save a life. But if you lose, there is no guarantee of what might happen to the personnel.
3.	Dynamic Gameplay:
There is a wide range of text-based games included, such as Hangman, Cursed Number, etc. You will follow the dialogues of Batman and Riddler and experience more than just text-based games.


## Coding Features
**maingame.cpp**  
Set the background  

	The style of printing (computer typing) and a little pause in between the dialogues make the game more engaging and mysterious  
	The colours of the dialogues from Batman and Riddler are light blue and green respectively. This helps catch the player’s attention to the instruction  
	Program codes in multiple files (all other header and C++ source files) 
<br>
<br>
<br>
**riddle.cpp**   
The player solves the riddle by guessing the answer of the question.
  
	The riddle is imported from a text file (File Input)  
	The riddle being picked is random (Generation of random game sets or events)  
	Program codes in multiple files (riddle.h) 
<br>
<br>
<br>
**hangman.cpp**  
The player will be given letters to guess a word chosen by the Riddler in limited number of trials.  

	The list of words for hangman is imported from a text file (File Input)  
	The word being picked is random (Generation of random game sets or events)  
	Program codes in multiple files (hangman.h)  
	Storing imported words in a vector (Data structures for storing game status)  
	Initialising the guessing word (Dynamic memory management)  
<br>
<br>
<br>
**cursednum.cpp**  
The player and DA take turns to guess a number from 1-100. After every guess, the system will reduce the range of numbers the player can choose from.  

	The cursed number being picked is random (Generation of random game sets or events)  
	Program codes in multiple files (cursednum.h)  
<br>
<br>
<br>
**anagram.cpp**  
The player need to rearrange the letter into a word.  

	The list of words for anagram is imported from a text file (File Input)  
	The word being picked is random (Generation of random game sets or events)  
	Used “Shuffle” to randomise the order of the characters of the chosen word  
	Program codes in multiple files (anagram.h)  
	Storing imported words in a vector (Data structures for storing game status )  


 


List of Non-standard C/C++ libraries used:
Main:
thread: This library creates and manages threads in the code. It is used in the functions styledisp and styledisp2 to introduce delays between character outputs.

chrono: This library measures and manipulates time durations. It is used in the functions stypedisp and styledisp2 to control the timing of the character outputs.


Anagram:
stream: This library provides functionalities for file input and output. It is used to open and read from a file named "anagram_words.txt" in the function anagram(). 

string: This library provides functionalities for working with strings. It is used to store words read from the file, as well as user inputs and jumbled words.

vector: This library provides functionalities for working with dynamic arrays, known as vectors. It is used to store the words read from the file in a vector.

algorithm: This library provides various algorithms for manipulating sequences, such as sorting and shuffling. In the game, it is used for shuffling the characters of the chosen word using the shuffle function and for transforming strings to lowercase using the transform function.

random: This library provides functionalities for generating pseudo-random numbers. It is used to seed the random number generator (default_randon_engine) and to generate a random index for choosing a word from the vector of words.

chrono: This library is used to measure and manipulate time durations. It is used to seed the random number generator based on the current system clock time in the function anagram().


Cursedum:
cstdlib: This library provides general-purpose functions in the C standard library. In this code, it is used for generating random numbers using the rand function and for initializing the random number generator using srand.

ctime: This library provides functionalities for working with time and date. In the code, it is used to seed the random number generator based on the current time using srand.

cctype: This library provides functions for working with character types. 

string: This library provides functionalities for working with strings. It is used to store the player's and antagonist's inputs as well as the output message.


Hangman:
cstdlib: This library provides general-purpose functions in the C standard library. In this code, it is used for generating random numbers using the rand function and for initializing the random number generator using srand.

fstream: This library provides functionalities for working with files. It is used to read the words from the file "words.txt" using an ifstream object.

string: This library provides functionalities for working with strings. It is used to store the randomly chosen word from the file, as well as other string operations such as finding substrings.

vector: This library provides functionalities for working with dynamic arrays or vectors. It is used to store the words read from the file.


Riddle:
algorithm: This library provides a collection of functions for a variety of purposes, including algorithms for working with containers. In this code, it is used to transform strings to lowercase using the transform function.

fstream: This library provides functionalities for workign with files. It is used to read the riddles and answers from the file "riddle.txt" using an ifstream object.

string: This library provides functionalities for working with strings. It is used to store the riddle, the user's answer, and the correct answer.

ctime: This library provides functions to work with time and date. It is used to seed the random number generator using the srand function.



Compilation and execution instructions:

