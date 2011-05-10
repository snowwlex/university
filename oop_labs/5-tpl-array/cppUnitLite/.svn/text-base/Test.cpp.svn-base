
#include "Test.h"
#include "TestRegistry.h"
#include "TestResult.h"
#include "Failure.h"

const double UTLITE_DEFAULT_PRECISION = 1e-8;

Test::Test (const std::string& testName) : name (testName) 
{
	TestRegistry::addTest (this);
}

void Test::run (TestResult& result) 
{
    try
    {
        S_TRY_BEGIN
        setup();
        runTest (result);
        S_TRY_END

    SPECIAL_CATCHERS
    }
    catch (...) {
        result.addFailure (Failure ("Unhandled exception", name, "", 0)); 
    }
    teardown();
    result.testWasRun();
}
