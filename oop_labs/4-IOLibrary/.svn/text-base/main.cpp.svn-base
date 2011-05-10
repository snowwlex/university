#include <iostream>
#include <cstdio>
#include <cstring>

#include "common.h"
#include "test.h"


void foo(const char* filename, const char* filename2) {
	char ch;
	char chars[200];
	int length;
	Stream *os = new DeflaterStream (new FileStream(filename, Stream::WRITE) );
	while ( feof(stdin) == 0) {
		fgets (chars, 200, stdin);
		length = strlen(chars);
		if (feof(stdin) == 0) {
			os->write(chars, length);
		}
	}
	delete os;
	Stream *is = new InflaterStream (new FileStream(filename, Stream::READ) );
	os = new FileStream(filename2, Stream::WRITE);
	while (is->read(&ch) != 0) {
		os->write(ch);
	}
	delete is;
}

void fillFile(const char* filename, const char* string, size_t size) {
	Stream *os = new DeflaterStream (new FileStream(filename, Stream::WRITE) );
	os->write(string, size);
	delete os;
}

int main() {

	test();
	//foo("file_compressed.cpp", "file_copy.cpp");
	fillFile("input.txt", "Hello world!", 13);

	Stream *os = new DeflaterStream ( new FileStream("output.txt", Stream::WRITE) );
	Stream *is = new InflaterStream(
				new FileStream("input.txt", Stream::READ)
	             );

    char buf[1024];
    int qty = is->read(&buf[0], 5);
	qty += is->read(&buf[qty], 1024);

	buf[qty] = '\0';
	std::cout << buf << std::endl;

	os->write('l');
	os->write(&buf[0], qty);

	delete os;
	delete is;

	return 0;
}
