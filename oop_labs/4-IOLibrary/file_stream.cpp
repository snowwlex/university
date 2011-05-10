#include <cstdio>
#include "file_stream.h"

FileStream::FileStream(const char* filename, Stream::OpenMode openMode) {
	myFile = 0;
	myOpenMode = openMode;
	switch (myOpenMode) {
	case READ:
		myFile = fopen(filename, "rb");
		break;
	case WRITE:
		myFile = fopen(filename, "wb");
		break;
	}
	if (myFile == 0) {
		throw StreamException("Cannot open file!");
	}

}
FileStream::~FileStream() {
	int result = fclose(myFile);
	if (result != 0) {
		throw(StreamException("Cannot close file!"));
	}
}

size_t FileStream::write(const char* ptr, size_t count) {
	if (myOpenMode != WRITE) {
		throw(StreamException(
				"Trying to write to file, that opened not for writing"));
	}
	size_t result = fwrite(ptr, sizeof(char), count, myFile);
	if (result != count) {
		throw(StreamException("Not all symbols has been written to file"));
	}
	return result;
}

size_t FileStream::read(char* ptr, size_t count) {
	if (myOpenMode != READ) {
		throw(StreamException(
				"Trying to read a file, that opened not for reading"));
	}
	size_t result = fread(ptr, sizeof( char), count, myFile);
	return result;
}

size_t FileStream::write(char byte) {
	return write(&byte, 1);
}
size_t FileStream::read(char* byte) {
	return read(byte, 1);
}

