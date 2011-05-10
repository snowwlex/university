#include <iostream>
#include <stdexcept>
#include "IntObject.h"

IntObject::IntObject(int i) : myInt(i) {
}

IntObject::IntObject(const IntObject& intObject) {
    myInt = intObject.myInt;
}

bool IntObject::operator<(const Object& object) const {
    const IntObject* intObject = dynamic_cast<const IntObject*> (&object);
    if (intObject == 0) {
        throw std::logic_error("IntObject: operator<() Can't compare IntObject with non IntObject!");
    }
    return myInt < intObject->myInt;
}

bool IntObject::operator==(const Object& object) const {
    const IntObject* intObject = dynamic_cast<const IntObject*> (&object);
    if (intObject == 0) {
        throw std::logic_error("IntObject: operator==() Can't compare IntObject with non IntObject!");
    }
    return myInt == intObject->myInt;
}

IntObject & IntObject::operator=(const Object& object) {
    const IntObject* intObject = dynamic_cast<const IntObject*> (&object);
    if (intObject == 0) {
        throw std::logic_error("IntObject: operator=() Can't assign to IntObject  non IntObject!");
    }
    myInt = intObject->myInt;
}

IntObject::~IntObject() {

}

std::ostream& IntObject::printTo(std::ostream& stream) const {
    return operator<<(stream, *this);
}

std::ostream & operator<<(std::ostream& stream, const IntObject& object) {
    stream << object.myInt;
    return stream;
}
