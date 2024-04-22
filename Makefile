hangman.o: hangman.cpp hangman.h
	g++ -pedantic-errors -std=c++11 -c hangman.cpp

riddle.o: riddle.cpp riddle.h
	g++ -pedantic-errors -std=c++11 -c riddle.cpp

cursednum.o: cursednum.cpp cursednum.h
	g++ -pedantic-errors -std=c++11 -c cursednum.cpp

anagram.o: anagram.cpp anagram.h
	g++ -pedantic-errors -std=c++11 -c anagram.cpp

maingame.o: maingame.cpp hangman.h riddle.h cursednum.h anagram.h
	g++ -pedantic-errors -std=c++11 -c maingame.cpp

game: hangman.o maingame.o riddle.o cursednum.o anagram.o
	g++ -pedantic-errors -std=c++11 hangman.o riddle.o cursednum.o maingame.o anagram.o -o game

clean:
	rm -f hangman.o riddle.o maingame.o cursednum.o anagram.o game

.PHONY: clean
