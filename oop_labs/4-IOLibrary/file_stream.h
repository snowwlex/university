#ifndef FILESTREAM_H_
#define FILESTREAM_H_

#include <cstdio>
#include "stream.h"

class FileStream : public Stream {

public:
	FileStream(const char* filename, Stream::OpenMode openMode);
	virtual ~FileStream();

public:
	virtual size_t write(const char* ptr, size_t count);
	virtual size_t write(char byte);
	virtual size_t read(char* ptr, size_t count);
	virtual size_t read(char* byte);

private:
	FILE* myFile;
	Stream::OpenMode myOpenMode;
};

#endif /* FILESTREAM_H_ */
