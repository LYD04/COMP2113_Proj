hangman.o: hangman.cpp hangman.h
	g++ -c hangman.cpp

riddle.o: riddle.cpp riddle.h
	g++ -c riddle.cpp

cursednum.o: cursednum.cpp cursednum.h
	g++ -c cursednum.cpp

anagram.o: anagram.cpp anagram.h
	g++ -c anagram.cpp

maingame.o: maingame.cpp hangman.h riddle.h cursednum.h anagram.h
	g++ -c maingame.cpp

game: hangman.o maingame.o riddle.o cursednum.o anagram.o
	g++ hangman.o riddle.o cursednum.o maingame.o anagram.o -o game

clean:
	rm -f hangman.o riddle.o maingame.o cursednum.o anagram.o

.PHONY: clean
