#ifndef _BINARYTREEITERATOR_H
#define	_BINARYTREEITERATOR_H


#include "../../interfaces/Iterator.h"
#include "../BinaryTree.h"

class BinaryTreeIterator : public Iterator {
public:
    BinaryTreeIterator(const Node* root, size_t size);
    virtual ~BinaryTreeIterator();
public:
    virtual void first();
    virtual bool is() const;
    virtual void next();
    virtual Object* get() const;
private:
    const Node* myRoot;
    const Node** myNodes;
    size_t myDequeSize;
    size_t myDequePop;
    size_t myDequePush;

};


#endif	/* _BINARYTREEITERATOR_H */

