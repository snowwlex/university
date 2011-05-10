
#include <cstring>
#include "string.h"


String::String() {
    myString = 0;
}


String::String(const char* chars) {
    copyString(chars);
}

String::String(const String& string) {
    copyString(string.myString);
}

String & String::operator=(const String& String) {
    delete myString;
    copyString(String.myString);
    return *this;
}

void String::copyString(const char* chars) {
    size_t len = strlen(chars);
    myString = new char[len + 1];
    memcpy(myString, chars, len + 1);
}

String::~String() {
    delete[] myString;
}

const char* String::c_str() const {
    return myString;
}

std::ostream & operator<<(std::ostream& stream, const String& string) {
    stream << string.myString;
    return stream;
}
