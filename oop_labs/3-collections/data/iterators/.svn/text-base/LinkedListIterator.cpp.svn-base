#include <stdexcept>

#include "LinkedListIterator.h"

LinkedListIterator::LinkedListIterator(const LinkedListElement* linkedListHead) :
    myHead(linkedListHead), curElement(myHead) {
}

LinkedListIterator::~LinkedListIterator() {
    
}

void LinkedListIterator::first() {
    curElement = myHead;
}

void LinkedListIterator::next() {
    if (is() != true) {
        throw std::logic_error("LinkedListIterator: get() : Out of bounds!");
    }
    curElement = curElement->next;
}

bool LinkedListIterator::is() const {
    return curElement != 0;
}

Object* LinkedListIterator::get() const {
    if (is() != true) {
        throw std::logic_error("LinkedListIterator: get() : Out of bounds!");
    }
    return curElement->object;
}