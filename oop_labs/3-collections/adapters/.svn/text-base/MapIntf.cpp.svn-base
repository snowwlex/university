#include <stdexcept>
#include "../objects/PairObject.h"
#include "MapIntf.h"

MapIntf::MapIntf(NotConseqData* data) {
    myData = data;
}

MapIntf::~MapIntf() {
    delete myData;
}

void MapIntf::set(Object* key, Object* value) {

    PairObject* pairObj = 0;
    bool found;

    Iterator* i = myData->getIterator();
    for (i->first(), found = false; found == false && i->is(); i->next()) {

        pairObj = static_cast<PairObject*> (i->get());
        if (*pairObj == *key) {
            found = true;
        }
    }
    delete i;

    if (found == true) {
        pairObj->setSecond(value);
    } else {
        pairObj = new PairObject(key, value);
        myData->insert(pairObj);
    }

}

bool MapIntf::contains_key(Object* key) const {
    Iterator* i = myData->getIterator();
    for (i->first(); i->is(); i->next()) {
        if (*i->get() == *key) {
            return true;
        }
    }
    delete i;
    return false;
}

Object* MapIntf::value(Object* key) {

    Object* valuePtr = 0;

    Iterator* i = myData->getIterator();
    for (i->first(); i->is(); i->next()) {
        Object* pairObj = i->get();
        if (*i->get() == *key) {
            valuePtr = static_cast<PairObject*> (pairObj)->getSecond();
        }
    }
    delete i;

    if (valuePtr == 0) {
        throw std::logic_error("MapLinkedListAdapter: value() There's not that key!");
    }
    return valuePtr;
}

void MapIntf::erase(Object* key) {
    myData->erase(key);
}

bool MapIntf::empty() {
    return myData->empty();
}

size_t MapIntf::size() {
    return myData->size();
}

void MapIntf::clear() {
    myData->clear();
}

Iterator* MapIntf::getIterator() const {
    return myData->getIterator();
}


