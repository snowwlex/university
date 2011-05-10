#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cassert>


#include "RnBTree.h"

bool RnBTree::insert(Object* key) {

    RnBNode *res = static_cast<RnBNode*> (getNearestNode(key));
    bool inserted = false;
    if (!res) {
        root_ = res = new RnBNode(key);
        ++size_;
        static_cast<RnBNode*> (root_)->color_ = Black;
        inserted = true;
    } else {
        Object* resKey = res->key_;
        if (resKey != key) {
            RnBNode* ins = new RnBNode(key);
            ++size_;
            ins->parent_ = res;
            res->children_[resKey > key ? Left : Right] = ins;
            fixupInsertion(ins);
            res = ins;
            inserted = true;
        }
    }

    return inserted;
}

void RnBTree::deleteNode(Node *node) {

    RnBNode *y = NULL;
    if (node->children_[Left] == NULL || node->children_[Right] == NULL) {
        y = static_cast<RnBNode*> (node);
    } else {
        y = static_cast<RnBNode*> (node->children_[Right]);
        while (y->children_[Left]) y = static_cast<RnBNode*> (y->children_[Left]);
    }

    RnBNode *x = static_cast<RnBNode*> (y->children_[(y->children_[Left]) ? Left : Right]);
    if (x) {
        x->parent_ = y->parent_;
    }

    if (y->parent_) {
        y->parent_->children_[(y == y->parent_->children_[Left]) ? Left : Right] = x;
    } else {
        root_ = x;
    }

    if (y != node) {
        node->key_ = y->key_;
    }

    if (y->color_ == Black && x) {
        fixupDeletion(x);
    }
    --size_;
    delete y;
}

void RnBTree::fixupInsertion(RnBNode *ins) {
    for (RnBNode *cur = ins; cur != root_ && static_cast<RnBNode*> (cur->parent_)->GetColor() == Red;) {
        RnBNode *parent = static_cast<RnBNode*> (cur->parent_);
        RnBNode *grand = static_cast<RnBNode*> (parent->parent_);

        Direction direction = (parent == grand->children_[Left]) ? Right : Left;
        Direction opposite = getOppositeDirection(direction);

        RnBNode *uncle = static_cast<RnBNode*> (grand->children_[direction]);
        if (uncle->GetColor() == Red) {
            parent->color_ = Black;
            uncle->color_ = Black;
            grand->color_ = Red;
            cur = grand;
        } else {
            if (cur == parent->children_[direction]) {
                cur = parent;
                rotate(cur, opposite);
            }

            static_cast<RnBNode*> (cur->parent_)->color_ = Black;
            static_cast<RnBNode*> (cur->parent_->parent_)->color_ = Red;
            rotate(static_cast<RnBNode*> (cur->parent_->parent_), direction);
        }
    }

    static_cast<RnBNode*> (root_)->color_ = Black;
}

void RnBTree::rotate(RnBNode* i, Direction direction) {
    Direction opposite = getOppositeDirection(direction);
    RnBNode *op = static_cast<RnBNode*> (i->children_[opposite]);

    i->children_[opposite] = op->children_[direction];
    if (op->children_[direction]) {
        op->children_[direction]->parent_ = i;
    }

    if (op) {
        op->parent_ = i->parent_;
    }

    if (i->parent_) {
        if (i == i->parent_->children_[direction]) {
            i->parent_->children_[direction] = op;
        } else {
            i->parent_->children_[opposite] = op;
        }
    } else {
        root_ = op;
    }

    op->children_[direction] = i;
    if (i) {
        i->parent_ = op;
    }
}

void RnBTree::fixupDeletion(RnBNode *node) {
    while (node != root_ && node->color_ == Black) {
        Direction dir = (node == node->parent_->children_[Left]) ? Left : Right;
        Direction opp = getOppositeDirection(dir);

        RnBNode *brother = static_cast<RnBNode*> (node->parent_->children_[opp]);
        if (brother->GetColor() == Red) {
            brother->color_ = Black;
            static_cast<RnBNode*> (node->parent_)->color_ = Red;
            rotate(static_cast<RnBNode*> (node->parent_), dir);
            brother = static_cast<RnBNode*> (node->parent_->children_[opp]);
        }

        if ((static_cast<RnBNode*> (brother->children_[Left]))->GetColor() == Black &&
                static_cast<RnBNode*> (brother->children_[Right])->GetColor() == Black) {
            brother->color_ = Red;
            node = static_cast<RnBNode*> (node->parent_);
        } else {
            if (static_cast<RnBNode*> (brother->children_[opp])->GetColor() == Black) {
                static_cast<RnBNode*> (brother->children_[dir])->color_ = Black;
                brother->color_ = Red;
                rotate(brother, opp);
                brother = static_cast<RnBNode*> (node->parent_->children_[opp]);
            }

            brother->color_ = static_cast<RnBNode*> (node->parent_)->color_;
            static_cast<RnBNode*> (node->parent_)->color_ = Black;
            static_cast<RnBNode*> (brother->children_[opp])->color_ = Black;
            rotate(static_cast<RnBNode*> (node->parent_), dir);
            node = static_cast<RnBNode*> (root_);
        }
    }

    node->color_ = Black;
}