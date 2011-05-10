
#ifndef _RNBTREE_H
#define	_RNBTREE_H

#include "BinaryTree.h"

enum Color {
    Red,
    Black
};

struct RnBNode : public Node {
    Color color_;
    
    RnBNode(Object * key) : Node(key), color_(Red) {
    }

    Color GetColor() {
        return this ? color_ : Black;
    }
};

class RnBTree : public BinaryTree {
public:

    bool insert(Object* key);
    
private:
    virtual void deleteNode(Node *node);

private: //helpers

    void fixupInsertion(RnBNode *ins);
    void rotate(RnBNode* i, Direction direction);
    void fixupDeletion(RnBNode *gRBNode);

  
    
private: // data members
   

};




#endif	/* _RNBTREE_H */

