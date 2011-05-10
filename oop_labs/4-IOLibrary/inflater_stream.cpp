#include <cassert>
#include <iostream>
#include <cstring>
#include <zlib.h>

#include "inflater_stream.h"

const unsigned long InflaterStream::myBufferSize = 1024; //1 Kb

InflaterStream::InflaterStream(Stream* stream) :
	ModifyStream(stream) {

	myZipStream.zalloc = Z_NULL;
	myZipStream.zfree = Z_NULL;
	myZipStream.opaque = Z_NULL;
	inflateInit(&myZipStream);

	myZipStream.avail_in = 0;

	myBuffer = new unsigned char[myBufferSize];
}

size_t InflaterStream::read(char* ptr, size_t count) {

	//setting output buffer
	myZipStream.avail_out = count;
	myZipStream.next_out  = (unsigned char*)ptr;

	//inflate, while output buffer is not full
	do {
		// if buffer has reached end, read new portion
		if (myZipStream.avail_in == 0 ) {
			myZipStream.avail_in = ModifyStream::read((char*)myBuffer, myBufferSize);
			if (myZipStream.avail_in == 0) {
				break; // stop inflating if input stream is empty
			}
			myZipStream.next_in = myBuffer;
		}

		 int result = inflate(&myZipStream, Z_SYNC_FLUSH);

		 if (result != Z_STREAM_END && result != Z_OK) {
			 throw ( StreamException(myZipStream.msg) );
		 }

	} while ( myZipStream.avail_out != 0 );

	return count - myZipStream.avail_out; // return total inflated bytes

}
size_t InflaterStream::read(char* byte) {
	return read(byte, 1);
}

InflaterStream::~InflaterStream() {
	int result = inflateEnd(&myZipStream);
	if (result != Z_OK) {
		throw ( StreamException(myZipStream.msg) );
	}
	delete myBuffer;
}
