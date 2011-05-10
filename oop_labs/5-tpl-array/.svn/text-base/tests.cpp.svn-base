#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include <stdexcept>

#include "VarArray.h"
#include "tests.h"
#include "string.h"

template <>
struct traits<String> {
    int compare(const String& a, const String& b) {
        int cmp = strcmp(a.c_str(), b.c_str());
        if (cmp < 0) {
            return -1;
        }
        if (cmp > 0) {
            return 1;
        }
        return 0;
    }
};


TEST(VarArray, int) {
    VarArray<int> array;

    CHECK(array.empty() == true);
    srand(time(0));
    for (int i = 0; i < 1000; ++i) {
        int r = rand() % 10;
        array.add(r);
    }
    CHECK(array.empty() == false);
    CHECK(array.length() == 1000);

}

TEST(VarArray, at) {
    VarArray<int> array;
    CHECK_THROWS_EX(array[0], std::out_of_range);
    array.add(10);
    CHECK_THROWS_EX(array[2], std::out_of_range);
    array[0];
}

TEST(VarArray, sort) {
    VarArray<int> array;

    for (int i = 0; i < 20; ++i) {
        array.add(rand() % 100);
    }

    std::cout << "Sort test. " << " before: ";
    for (size_t i = 0; i < array.length(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << "After: ";
    array.sort();
    for (size_t i = 0; i < array.length(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

}

TEST(VarArray, binSearch) {
    VarArray<int> array;

    CHECK(array.binarySearch(rand() % 10) == false);

    for (int i = 0; i < 1000; i += 2) {
        array.add(i);
    }

    std::cout << "BinSearch test. ";
    for (size_t i = 0; i < array.length(); i++) {
        //std::cout << array[i] << " ";
    }
    //std::cout << std::endl;

    for (int i = 0; i < 1000; ++i) {
        // std::cerr << "Try to find " << i << " ";
        bool found = array.binarySearch(i);
        if (i % 2 == 0) {
            CHECK(found == true);
        } else {
            CHECK(found == false);
        }
        //std::cout << (found == true ? "found" : "not found") << std::endl;
    }



}

TEST(VarArray, StringTest) {
    VarArray<String> strings;
    strings.add("Decorator");
    strings.add("Expect");
    strings.add("Color");
    strings.add("Cave");
    strings.add("Alexander");

    std::cout << "StringTest: before sort: ";
    for (int i = 0; i < strings.length(); ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    strings.sort();

    std::cout << "After sort: ";
    for (int i = 0; i < strings.length(); ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Searching 'Decorator': " << (strings.binarySearch("Decorator") == true ? "found" : "not found") << std::endl;
    std::cout << "Searching 'Lex': " << (strings.binarySearch("Lex") == true ? "found" : "not found") << std::endl;

}


TEST(VarArray, CharTest) {
    VarArray<const char*> chars;
    chars.add("Daddy");
    chars.add("Elena");
    chars.add("Baby");
    chars.add("Color");
    chars.add("Camera");

    std::cout << "CharTest: before sort: ";
    for (int i = 0; i < chars.length(); ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;

    chars.sort();

    std::cout << "After sort: ";
    for (int i = 0; i < chars.length(); ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Searching Baby: " << (chars.binarySearch("Baby") == true ? "found" : "not found") << std::endl;
    std::cout << "Searching Goal: " << (chars.binarySearch("Goal") == true ? "found" : "not found") << std::endl;

}

void tests() {
    srand(time(0));
    MyTestResult results;
    TestRegistry::runAllTests(results);
    std::cout << "Errors number: " << results.getFailureCount() << std::endl;
}
