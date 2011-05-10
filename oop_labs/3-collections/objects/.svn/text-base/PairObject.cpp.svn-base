
#include <stdexcept>

#include "PairObject.h"

PairObject::PairObject(Object* one, Object* two) : myOne(one), myTwo(two) {
}

PairObject::PairObject(const PairObject& pairObject) {
    myOne = pairObject.myOne;
    myTwo = pairObject.myTwo;
}

PairObject& PairObject::operator=(const Object& object) {
    const PairObject* pairObject = dynamic_cast<const PairObject*> (&object);
    if (pairObject == 0) {
        throw std::logic_error("PairObject: operator=() Can't assign PairObject with non PairObject!");
    }
    myOne = pairObject->myOne;
    myTwo = pairObject->myTwo;
}

PairObject::~PairObject() {
    delete myOne;
    delete myTwo;
}

Object* PairObject::getFirst() const {
    return myOne;

}

Object* PairObject::getSecond() const {
    return myTwo;
}

void PairObject::setFirst(Object* object) {
    myOne = object;
}

void PairObject::setSecond(Object* object) {
    myTwo = object;
}

bool PairObject::operator<(const Object& object) const {
    const PairObject* pairObject = dynamic_cast<const PairObject*> (&object);
    if (pairObject == 0) {
        return *myOne < object;
    }
    return *myOne < *pairObject->myOne;
}

bool PairObject::operator==(const Object& object) const {
    const PairObject* pairObject = dynamic_cast<const PairObject*> (&object);
    if (pairObject == 0) {
        return *myOne == object;
    }
    return *myOne == *pairObject->myOne;
}

std::ostream& PairObject::printTo(std::ostream& stream) const {
    stream << *this;
}

std::ostream & operator<<(std::ostream& stream, const PairObject& pairObject) {
    stream << "(" << *pairObject.myOne << ", " << *pairObject.myTwo << ")";
}
