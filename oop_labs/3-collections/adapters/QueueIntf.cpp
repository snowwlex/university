#include <stdexcept>
#include "../interfaces/Iterator.h"
#include "QueueIntf.h"

QueueIntf::QueueIntf(ConseqData* data) : myData(data) {

}

QueueIntf::~QueueIntf() {
    delete myData;
}

Object* QueueIntf::front() const {
    return myData->front();
}

Object* QueueIntf::back() const {
    return myData->back();
}

void QueueIntf::push(Object* object) {
    myData->pushBack(object);
}

void QueueIntf::clear() {
    myData->clear();
}

void QueueIntf::pop() {
    myData->popFront();
}

bool QueueIntf::empty() {
    return myData->empty();

}

size_t QueueIntf::size() {
    return myData->size();
}

Iterator* QueueIntf::getIterator() const {
    return myData->getIterator();
}