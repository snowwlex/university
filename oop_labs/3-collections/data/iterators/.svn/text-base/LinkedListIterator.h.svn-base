
#ifndef _LINKEDLISTITERATOR_H
#define	_LINKEDLISTITERATOR_H

#include "../../interfaces/Iterator.h"
#include "../LinkedList.h"

class LinkedListIterator : public Iterator {
public:
    LinkedListIterator(const LinkedListElement* head);
    virtual ~LinkedListIterator();
public:
    virtual void first();
    virtual bool is() const;
    virtual void next();
    virtual Object* get() const;
private:
    const LinkedListElement* myHead;
    const LinkedListElement* curElement;
};

#endif	/* _LINKEDLISTITERATOR_H */

