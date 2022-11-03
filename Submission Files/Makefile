d2boh.o: d2boh.cpp d2boh.h
	g++ -c d2boh.cpp

main.o: main.cpp d2boh.h
	g++ -c main.cpp

main: d2boh.o main.o
	g++ d2boh.o main.o -o main

clean:
	rm -f main main.o d2boh.o

.PHONY: clean