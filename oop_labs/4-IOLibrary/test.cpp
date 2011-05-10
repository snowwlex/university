/*
 * test.cpp
 *
 *  Created on: 25.04.2010
 *      Author: snowwlex
 */
#include "test.h"


TEST(Stream, IOCorrectCheck ){

	try {

		char ch[] = "Test string number one.";
		Stream* os = new FileStream("output.txt", Stream::WRITE);
		size_t resulted = os->write( ch, sizeof(ch) );
		delete os;

		Stream* is = new FileStream("output.txt", Stream::READ);
		char* ch2 = new char[1000];
		resulted = is->read(ch2, 1000);
		ch2[resulted] = '\0';
		CHECK_STRINGS_EQUAL((char*)ch,(char*)ch2);
		delete ch2;
		delete is;
	} catch ( std::exception& exception ) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}


TEST(Stream, ZlibIOCorrectCheck ){

	try {
		char ch[] = "Test string number two.";
		Stream* os = new DeflaterStream( new FileStream("output.txt", Stream::WRITE) );
		size_t resulted = os->write( ch, sizeof(ch) );
		delete os;

		Stream* is = new InflaterStream ( new FileStream("output.txt", Stream::READ) );
		char* ch2 = new char[1000];
		resulted = is->read(ch2, 1000);
		ch2[resulted] = '\0';
		CHECK_STRINGS_EQUAL((char*)ch,(char*)ch2);
		delete ch2;
		delete is;
	} catch (std::exception& exception ) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

TEST(Stream, OpenFileErrorCheck ) {
	CHECK_THROWS_EX(
					new FileStream("not-exist.txt", Stream::READ) ,
					StreamException
			       );
}
TEST(Stream, ReadErrorCheck) {

	char a = '1';
	Stream* is = new FileStream("output.txt", Stream::READ);
	CHECK_THROWS_EX( is->write(a), StreamException );
	delete is;
}

TEST(Stream, DeflatingErrorCheck) {
	Stream* os = new FileStream("output.txt", Stream::WRITE);
	char text[] = "Test string number three.";
	os->write(text, sizeof(text) );
	delete os;

	Stream* is = new InflaterStream( new FileStream( "output.txt", Stream::READ ) );
	char text2[1000];
	CHECK_THROWS_EX (is->read(text2, 1000) , StreamException);
	delete is;
}

void test() {



	TestRegistry::addTest(&IOCorrectCheckStreamInstance);
	TestRegistry::addTest(&ZlibIOCorrectCheckStreamInstance);
	TestRegistry::addTest(&OpenFileErrorCheckStreamInstance);
	TestRegistry::addTest(&ReadErrorCheckStreamInstance);
	TestRegistry::addTest(&DeflatingErrorCheckStreamInstance);


	StreamTestResult results;
	TestRegistry::runAllTests(results);

	std::cout <<  "errors (of tests executions): " << results.getFailureCount() << std::endl;

}
