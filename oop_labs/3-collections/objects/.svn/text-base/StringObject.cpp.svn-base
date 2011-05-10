#include <cstring>
#include <stdexcept>
#include "StringObject.h"

StringObject::StringObject(const char* chars) {
    copyString(chars);
}

StringObject::StringObject(const StringObject& string) {
    copyString(string.myString);
}

StringObject & StringObject::operator=(const Object& object) {

    const StringObject* stringObject = dynamic_cast<const StringObject*> (&object);
    if (stringObject == 0) {
        throw std::logic_error("StringObject: operator=() Can't assign to StringObject  non StringObject!");
    }

    delete myString;
    copyString(stringObject->myString);
    return *this;
}

void StringObject::copyString(const char* chars) {
    size_t len = strlen(chars);
    myString = new char[len + 1];
    memcpy(myString, chars, len + 1);
}

StringObject::~StringObject() {
    delete myString;
}

bool StringObject::operator<(const Object& object) const {
    const StringObject* stringObject = dynamic_cast<const StringObject*> (&object);
    if (stringObject == 0) {
        throw std::logic_error("StringObject: operator<() Can't comapre StringObject with  non StringObject!");
    }

    int cmp = strcmp(myString, stringObject->myString);
    if (cmp >= 0) {
        return false;
    }
    return true;

}

bool StringObject::operator==(const Object& object) const {
    const StringObject* stringObject = dynamic_cast<const StringObject*> (&object);
    if (stringObject == 0) {
        throw std::logic_error("StringObject: operator==() Can't compare to StringObject  non StringObject!");
    }

    int cmp = strcmp(myString, stringObject->myString);
    if (cmp != 0) {
        return false;
    }
    return true;
};

std::ostream & operator<<(std::ostream& stream, const StringObject& object) {
    stream << object.myString;
    return stream;
}

std::ostream& StringObject::printTo(std::ostream& stream) const {

    return operator<<(stream, *this);
}