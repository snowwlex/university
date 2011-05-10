#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "common.h"

#include <TestHarness.h>

class StreamTestResult : public TestResult {
public:
	virtual void addFailure (const Failure & failure) {
		std::cout << failure;
		TestResult::addFailure(failure);
	}
};

void test();
