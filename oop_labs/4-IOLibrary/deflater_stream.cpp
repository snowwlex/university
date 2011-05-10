#include <cassert>
#include <iostream>
#include <cstring>
#include <zlib.h>

#include "deflater_stream.h"

const unsigned long DeflaterStream::myBufferSize = 1024; //1 Kb

DeflaterStream::DeflaterStream(Stream* stream) :
	ModifyStream(stream) {

	myZipStream.zalloc = Z_NULL;
	myZipStream.zfree = Z_NULL;
	myZipStream.opaque = Z_NULL;
	deflateInit(&myZipStream, Z_DEFAULT_COMPRESSION);

	myBuffer = new unsigned char[myBufferSize];

}

size_t DeflaterStream::write(const char* ptr, size_t count) {
	//setting input buffer
	myZipStream.avail_in = count;
	myZipStream.next_in = (unsigned char*) ptr;
	deflateThis(Z_NO_FLUSH);
	return count;
}

void DeflaterStream::deflateThis(int flush) {

	// deflate, while output buffer (after deflating) is empty
	// that's enough condition, because:

	// if output buffer is more than deflated stream,
	// 		it will be not zero; all data is deflated

	// if output buffer is less than deflated stream:
	// 		function 'deflate' takes of all input  stream  to inner state,
	// 		and buffer will be filled completely each time.
	// 		It guarantee that all input stream will be deflated
	// 		and written to file

	do {

		 myZipStream.avail_out = myBufferSize;
		 myZipStream.next_out = myBuffer;

		 int result = deflate(&myZipStream, flush);

		 if (result != Z_STREAM_END && result != Z_OK) {
			 throw ( StreamException(myZipStream.msg) );
		 }
		 unsigned long bytesDeflated = myBufferSize - myZipStream.avail_out;
		 ModifyStream::write((char*)myBuffer, bytesDeflated);

	} while (myZipStream.avail_out == 0);

}
size_t DeflaterStream::write(char byte) {
	return write(&byte, 1);
}

DeflaterStream::~DeflaterStream() {
	// flush all z_stream's inner buffer to stream
	myZipStream.avail_in = 0;
	deflateThis(Z_FINISH);

	delete myBuffer;
	deflateEnd(&myZipStream);
}
