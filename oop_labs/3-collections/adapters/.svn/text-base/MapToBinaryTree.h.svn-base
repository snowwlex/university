#ifndef _MapBinaryTreeAdapterBINARYTREEADAPTER_H
#define	_MapBinaryTreeAdapterBINARYTREEADAPTER_H

#include "../interfaces/Map.h"
#include "../data/BinaryTree.h"

class MapToBinaryTree : public Map {
public:

    MapToBinaryTree(BinaryTree* myData);

    virtual ~MapToBinaryTree();
public:
    virtual void set(Object* key, Object* value);
    virtual bool contains_key(Object* key) const;
    virtual Object* value(Object* key);
    virtual void erase(Object* key);
    virtual bool empty();
    virtual size_t size();
    virtual void clear();
    virtual Iterator* getIterator() const;

private:
    MapToBinaryTree(const MapToBinaryTree& MapBinaryTreeAdapter);

private:
    BinaryTree* myData;

};

#endif	/* _MapBinaryTreeAdapterBINARYTREEADAPTER_H */

