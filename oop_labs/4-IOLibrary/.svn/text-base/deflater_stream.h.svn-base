#ifndef ZIPMODIFIERSTREAM_H_
#define ZIPMODIFIERSTREAM_H_

#include "modify_stream.h"
#include <zlib.h>

class DeflaterStream : public ModifyStream {

public:
	DeflaterStream(Stream* stream);
	virtual ~DeflaterStream();

public:
	virtual size_t write(const char* ptr, size_t count);
	virtual size_t write(char byte);

private: //help methods
	void deflateThis(int flush);

private:
	z_stream myZipStream;
	unsigned char* myBuffer;
	static const unsigned long myBufferSize;
};

#endif /* ZIPMODIFIERSTREAM_H_ */
