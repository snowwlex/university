#include <stdexcept>
#include "../objects/PairObject.h"
#include "MapToBinaryTree.h"

MapToBinaryTree::MapToBinaryTree(BinaryTree* data) {
    myData = data;
}

MapToBinaryTree::~MapToBinaryTree() {
    delete myData;
}

void MapToBinaryTree::set(Object* key, Object* value) {
    Node* node = myData->findNode(key);
    if (node != 0) {
        PairObject* pairObj = static_cast<PairObject*>(node->key_);
        pairObj->setSecond(value);
    } else {
        PairObject* pairObj = new PairObject(key, value);
        myData->insert(pairObj);
    }
}

bool MapToBinaryTree::contains_key(Object* key) const {
    Node* node = myData->findNode(key);
    return node != 0;
}

Object* MapToBinaryTree::value(Object* key) {
    Node* node = myData->findNode(key);
    if (node == 0) {
        throw std::logic_error("MapBinaryTreeAdapter: value() There's not that key!");
    }
    return static_cast<PairObject*> (node->key_)->getSecond();
}


void MapToBinaryTree::erase(Object* key) {
    myData->erase(key);
}

bool MapToBinaryTree::empty() {
    return myData->empty();
}

size_t MapToBinaryTree::size() {
    return myData->size();
}

void MapToBinaryTree::clear() {
    myData->clear();
}

Iterator* MapToBinaryTree::getIterator() const {
    return myData->getIterator();
}


