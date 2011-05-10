#include <stdexcept>
#include "BinaryTreeIterator.h"

BinaryTreeIterator::BinaryTreeIterator(const Node* root, size_t size) :
myRoot(root) {
    myDequeSize = 2 * size + 1;
    myNodes = new const Node*[ myDequeSize ];
    first();
}

BinaryTreeIterator::~BinaryTreeIterator() {
     delete[] myNodes;
}

void BinaryTreeIterator::first() {
    myDequePop = 0;
    myDequePush = 0;
    
    if (myRoot != 0) {
        myNodes[ myDequePush++ ] = myRoot;
    }
}

void BinaryTreeIterator::next() {

    if (is() == false) {
        throw std::logic_error("BinaryTreeIterator: next() Out of bounds!");
    }
    if (myDequePush >= myDequeSize ) {
        throw std::runtime_error("BunaryTreeIterator: next() not enough place in deque ");
    }

    const Node* node = myNodes[ myDequePop++ ];
    if (node->children_[Left] != 0) {
        myNodes[myDequePush++] = node->children_[Left];
    }
    if (node->children_[Right] != 0) {
        myNodes[myDequePush++] = node->children_[Right];
    }

}

bool BinaryTreeIterator::is() const {
    return myDequePop < myDequePush;
}

Object* BinaryTreeIterator::get() const {
    if (is() == false) {
        throw std::logic_error("BinaryTreeIterator: get() Out of bounds!");
    }
    return myNodes[myDequePop]->key_;
}