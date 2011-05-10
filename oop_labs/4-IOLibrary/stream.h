#ifndef IO_H_
#define IO_H_

#include <cstdio>
#include "stream_exception.h"

class Stream {
public:
	enum OpenMode {
		READ,
		WRITE
	};

public:
	virtual ~Stream() { };

public:
	virtual size_t write(const char* ptr, size_t count) = 0;
	virtual size_t write(char byte) = 0;
	virtual size_t read(char* ptr, size_t count) = 0;
	virtual size_t read(char* byte) = 0;

protected:
	Stream() { }

private:
	Stream(const Stream&) { }
};


#endif /* IO_H_ */
