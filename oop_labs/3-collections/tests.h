/* 
 * File:   tests.h
 * Author: snowwlex
 *
 * Created on 4 Май 2010 г., 3:43
 */

#ifndef _TESTS_H
#define	_TESTS_H

#include <iostream>
#define CATCH_STD_EXCEPTIONS
#include "cppUnitLite/TestHarness.h"


class MyTestResult : public TestResult {
public:
	virtual void addFailure (const Failure & failure) {
		std::cout << failure;
		TestResult::addFailure(failure);
	}
        virtual void testWasRun () {
            ++testCount;

            std::cout << "Test #" << testCount << " has finished" << std::endl;
        }
};

void tests();

#endif	/* _TESTS_H */

