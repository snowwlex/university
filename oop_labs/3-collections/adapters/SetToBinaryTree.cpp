#include "SetToBinaryTree.h"

SetToBinaryTree::SetToBinaryTree(BinaryTree* data) {
    myData = data;
}

SetToBinaryTree::~SetToBinaryTree() {
    delete myData;
}

void SetToBinaryTree::set(Object* key) {
    myData->insert(key);
}

bool SetToBinaryTree::contains_key(Object* key) const {
    Node* node = myData->findNode(key);
    return node != 0;
}

void SetToBinaryTree::erase(Object* key) {
    myData->erase(key);
}

bool SetToBinaryTree::empty() {
    return myData->empty();
}

size_t SetToBinaryTree::size() {
    return myData->size();
}

void SetToBinaryTree::clear() {
    myData->clear();
}

Iterator* SetToBinaryTree::getIterator() const {
    return myData->getIterator();
}
