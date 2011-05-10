/*
 * inflate_stream.h
 *
 *  Created on: 25.04.2010
 *      Author: snowwlex
 */

#ifndef INFLATE_STREAM_H_
#define INFLATE_STREAM_H_

#include "modify_stream.h"
#include <zlib.h>

class InflaterStream : public ModifyStream {

public:
	InflaterStream(Stream* stream);
	virtual ~InflaterStream();

public:
	virtual size_t read(char* ptr, size_t count);
	virtual size_t read(char* byte);

private:
	z_stream myZipStream;
	static const unsigned long myBufferSize;
	unsigned char* myBuffer;
};


#endif /* INFLATE_STREAM_H_ */
