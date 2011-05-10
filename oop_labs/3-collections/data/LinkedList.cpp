#include <stdexcept>

#include "LinkedList.h"
#include "iterators/LinkedListIterator.h"

LinkedList::LinkedList() : myHead(0), mySize(0) {
}

LinkedList::~LinkedList() {
    clear();
}

Iterator* LinkedList::getIterator() const {
    return new LinkedListIterator(myHead);
}

Object* LinkedList::front() const {
    if (myHead == 0) {
        throw std::logic_error("LinkedList: front() empty list");
    }
    return myHead->object;
};

Object* LinkedList::back() const {
    if (myHead == 0) {
        throw std::logic_error("LinkedList: back() empty list");
    }
    LinkedListElement* el = myHead;
    while (el->next != 0) {
        el = el->next;
    }
    return el->object;

};

void LinkedList::pushBack(Object* object) {

    if (myHead == 0) {
        LinkedListElement* newEl = new LinkedListElement();
        newEl->object = object;
        newEl->next = 0;
        myHead = newEl;
    } else {
        LinkedListElement* el = myHead;
        while (el->next != 0) { //search for pointer on last element
            el = el->next;
        }
        LinkedListElement* newEl = new LinkedListElement();
        newEl->object = object;
        newEl->next = 0;
        el->next = newEl;
    }
    ++mySize;
}

bool LinkedList::popBack() {

    if (myHead == 0) {
        return false;
    }

    LinkedListElement* el = myHead;
    LinkedListElement* prevEl = 0;

    while (el->next != 0) { //search for last element
        prevEl = el;
        el = el->next;
    }

    if (prevEl == 0) { //it could be if only 1 element
        myHead = 0;
    } else {
        prevEl->next = 0;
    }

    delete el->object;
    delete el;

    --mySize;
    return true;
}

void LinkedList::pushFront(Object* object) {
    LinkedListElement* newEl = new LinkedListElement();
    newEl->object = object;
    newEl->next = myHead;
    myHead = newEl;
    ++mySize;
}

bool LinkedList::popFront() {
    if (myHead == 0) {
        return false;
    }
    LinkedListElement* tmp = myHead->next;
    delete myHead->object;
    delete myHead;
    myHead = tmp;
    --mySize;
    return true;
}

bool LinkedList::insert(Object* object) {
    pushBack(object);
}

bool LinkedList::erase(Object* object) {

    LinkedListElement* el = myHead;
    LinkedListElement* prevEl = 0;

    while (el != 0 && !(*el->object == *object)) {
        prevEl = el;
        el = el->next;
    }


    if (el == 0) { //if not found
        return false;
    }

    if (prevEl == 0) {
        myHead = el->next;
    } else {
        prevEl->next = el->next;
    }
    delete el->object;
    delete el;
    --mySize;
    return true;

}

void LinkedList::clear() {
    while (myHead != 0) {
        LinkedListElement* tmp = myHead->next;
        delete myHead->object;
        delete myHead;
        myHead = tmp;

    }
    mySize = 0;
}

bool LinkedList::empty() const {
    return mySize == 0;
}

size_t LinkedList::size() const {
    return mySize;
}





