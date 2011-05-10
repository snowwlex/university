/* 
 * File:   BinaryTree.cpp
 * Author: snowwlex
 * 
 * Created on 5 Май 2010 г., 1:05
 */
#include <cassert>
#include <iostream>

#include "BinaryTree.h"
#include "iterators/BinaryTreeIterator.h"

BinaryTree::BinaryTree() : root_(0), size_(0) {

}

BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::clear() {
    deleteSubTree(root_);
    root_ = 0;
}

bool BinaryTree::erase(Object* key) {
    bool result = false;
    Node *res = findNode(key);
    if (res) {
        deleteNode(res);
        result = true;
    }
    return result;
}

Node* BinaryTree::findNode(Object* key) const {
    Node *res = 0;

    for (Node *cur = root_; cur;) {
        Object* curKey = cur->key_;
        if (*curKey == *key) {
            res = cur;
            break;
        }

        cur = cur->children_[(curKey > key) ? Left : Right];
    }

    return res;
}

Node* BinaryTree::getNearestNode(Object* key) const {
    Node *res = 0;

    for (Node *cur = root_; cur;) {
        res = cur;

        Object* curKey = cur->key_;
        if (curKey == key) {
            break;
        }

        cur = cur->children_[(curKey > key) ? Left : Right];
    }

    return res;
}

void BinaryTree::deleteSubTree(Node *node) {
    if (node == 0) {
        return;
    }
    deleteSubTree(node->children_[Left]);
    deleteSubTree(node->children_[Right]);
    --size_;
    delete node;
}

Direction BinaryTree::getOppositeDirection(const Direction dir) {
    return Direction(1 - dir);
}

bool BinaryTree::empty() const {
    if (size_ == 0) {
        return true;
    }
    return false;
}

size_t BinaryTree::size() const {
    return size_;
}

Iterator* BinaryTree::getIterator() const {
    Iterator*  it = new BinaryTreeIterator(root_, size_);
    return it;
}