default: streams

file_stream.o: file_stream.cpp file_stream.h stream.h
	g++ -Wall -c file_stream.cpp
	
inflater_stream.o: inflater_stream.cpp inflater_stream.h modify_stream.h stream.h
	g++ -Wall -c inflater_stream.cpp

deflater_stream.o: deflater_stream.cpp deflater_stream.h modify_stream.h stream.h
	g++ -Wall -c deflater_stream.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp 

streams: main.o deflater_stream.o inflater_stream.o file_stream.o
	g++ -Wall -o streams main.o deflater_stream.o inflater_stream.o file_stream.o

clean: 
	rm *.o streams

all: default

