
#ifndef _ITERATOR_H
#define	_ITERATOR_H

#include "Object.h"

class Iterator {
public:
    virtual ~Iterator() { }
public:
    virtual void first() = 0;
    virtual bool is() const = 0;
    virtual void next() = 0;
    virtual Object* get() const = 0;

protected:
     Iterator() { }
     
private:
    Iterator(const Iterator&) { }
    Iterator& operator=(const Iterator&);
};

#endif	/* _ITERATOR_H */

