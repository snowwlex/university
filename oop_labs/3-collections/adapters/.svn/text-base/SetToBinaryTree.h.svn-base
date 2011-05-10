/* 
 * File:   SetBinaryTreeAdapter.h
 * Author: snowwlex
 *
 * Created on 4 Май 2010 г., 17:14
 */

#ifndef _SETASSOCADAPTER_H
#define	_SETASSOCADAPTER_H

#include "../interfaces/Set.h"
#include "../data/BinaryTree.h"

class SetToBinaryTree : public Set {
public:
    SetToBinaryTree(BinaryTree* data);
    virtual ~SetToBinaryTree();

public:
    virtual void set(Object* key);
    virtual bool contains_key(Object* object) const;
    virtual void erase(Object* key);
    virtual bool empty();
    virtual size_t size();
    virtual void clear();
    virtual Iterator* getIterator() const;
private:
    SetToBinaryTree(const SetToBinaryTree&);
private:
    BinaryTree* myData;

};

#endif	/* _SETASSOCADAPTER_H */

