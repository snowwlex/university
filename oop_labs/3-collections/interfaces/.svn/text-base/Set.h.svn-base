#ifndef _SET_H
#define	_SET_H

#include <cstdlib>
#include "Object.h"
#include "Iterator.h"

class Set {
public:
    virtual ~Set() { }
public:
    virtual void set(Object* key) = 0;
    virtual bool contains_key(Object* object) const = 0;
    virtual void erase(Object* key) = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    virtual void clear() = 0;
    virtual Iterator* getIterator() const = 0;

protected:
    Set() { }
    Set(const Set& set);
};
#endif	/* _SET_H */

