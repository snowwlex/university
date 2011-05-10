
#ifndef _MAP_H
#define	_MAP_H


#include <cstdlib>
#include "Object.h"
#include "Iterator.h"

class Map {
public:

    virtual ~Map() { }
public:
    virtual void set(Object* key, Object* value) = 0;
    virtual bool contains_key(Object* object) const = 0;
    virtual void erase(Object* key) = 0;
    virtual Object* value(Object* key) = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    virtual void clear() = 0;
    virtual Iterator* getIterator() const = 0;

protected:
    Map() { }
    Map(const Map& map);

private:



};

#endif	/* _MAP_H */

