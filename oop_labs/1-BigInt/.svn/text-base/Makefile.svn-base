default: bigint

bigint.o: bigint.cpp bigint.h
	g++ -Wall -c bigint.cpp

main.o: main.cpp bigint.h
	g++ -Wall -c main.cpp 

bigint: main.o bigint.o
	g++ -Wall -o bigint main.o bigint.o

clean: 
	rm *.o bigint

all: default

