all: main

main: TextInvaders.o CursesUtils.o
		g++ -std=c++11 TextInvaders.o CursesUtils.o -o main -lncurses

TextInvaders.o: TextInvaders.cpp
		g++ -std=c++11 -c TextInvaders.cpp -lncurses

CursesUtils.o: CursesUtils.cpp
		g++ -std=c++11 -c CursesUtils.cpp	-lncurses

clean: 
			rm -rf *o main TextInvaders CursesUtils