#ifndef STREAMEXCEPTION_H_
#define STREAMEXCEPTION_H_

#include <exception>
class StreamException : public std::exception {

public:
	StreamException(const char* errorMessage): myErrorMessage(errorMessage) {	}
	virtual const char* what() const throw() {
		return myErrorMessage;
	}

private:
	const char* myErrorMessage;
};


#endif /* STREAMEXCEPTION_H_ */
