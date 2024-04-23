# COMP2113_Proj

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

