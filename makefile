main: RationalMain.o Rational.o
	g++ -pedantic -Wall RationalMain.o Rational.o -o main
RationalMain.o: RationalMain.cpp  Rational.cpp Rational.h
	g++ -pedantic -Wall RationalMain.cpp -c
Rational.o: Rational.cpp Rational.h
	g++ -pedantic -Wall Rational.cpp -c
