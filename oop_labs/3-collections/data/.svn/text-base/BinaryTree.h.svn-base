/* 
 * File:   BinaryTree.h
 * Author: snowwlex
 *
 * Created on 5 Май 2010 г., 1:05
 */

#ifndef _BINARYTREE_H
#define	_BINARYTREE_H


#include "../interfaces/NotConseqData.h"


enum Direction {
    None = -1,
    Left = 0,
    Right = 1
};

struct Node {
    Object* key_;
    Node * children_[2];
    Node* parent_;

    Node(Object * key) : key_(key), parent_(0) {
        children_[Left] = 0;
        children_[Right] = 0;
    }
};

class BinaryTree : public NotConseqData {
public:
     virtual ~BinaryTree();
public: //common interface methods:
    virtual void clear();
    virtual bool empty() const;
    virtual size_t size() const;
    virtual Iterator* getIterator() const;
public:  //interface methods:
    virtual bool insert(Object* key) = 0;
    virtual bool erase(Object* key);
public: //own methods
    Node* findNode(Object* key) const;
   
protected: // construction/destruction
    BinaryTree();
   

protected: //helpers
   
    Node* getNearestNode(Object* key) const;
    void deleteSubTree(Node *node);
    static Direction getOppositeDirection(const Direction dir);
    virtual void deleteNode(Node *node) = 0;

protected: // data members
    Node *root_;
    size_t size_;


};


#endif	/* _BINARYTREE_H */

