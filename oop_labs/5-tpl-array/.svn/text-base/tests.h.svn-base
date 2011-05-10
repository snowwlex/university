/* 
 * File:   tests.h
 * Author: snowwlex
 *
 * Created on 4 Май 2010 г., 3:43
 */

#ifndef _TESTS_H
#define	_TESTS_H

#include <iostream>
#include "cppUnitLite/TestHarness.h"


class MyTestResult : public TestResult {
public:
	virtual void addFailure (const Failure & failure) {
		std::cout << failure;
		TestResult::addFailure(failure);
	}
        virtual void testWasRun () {
            ++testCount;
            std::cout << "Test #" << testCount << " is finished" << std::endl;
        }
};

void tests();

#endif	/* _TESTS_H */

