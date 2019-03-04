main: main.o libr.o
	g++ main.o libr.o -o main
main.o: main.cpp libr.h
libr.o: libr.cpp libr.h
