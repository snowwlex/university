#ifndef _QUEUE_H
#define	_QUEUE_H

#include <cstdlib>
#include "Object.h"
#include "Iterator.h"
class Queue {
public:

    virtual ~Queue() { }
public:
    virtual Object* front() const = 0;
    virtual Object* back() const = 0;
    virtual void push(Object* object) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    virtual void clear() = 0;
    virtual Iterator* getIterator() const = 0;

protected:
    Queue() { };
    Queue(const Queue& queue);

private:



};

#endif	/* _QUEUE_H */

