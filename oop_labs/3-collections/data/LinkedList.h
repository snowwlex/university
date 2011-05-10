#ifndef _LINKEDLIST_H
#define	_LINKEDLIST_H

#include "../interfaces/ConseqData.h"
#include "../interfaces/NotConseqData.h"

struct LinkedListElement {
    Object* object;
    LinkedListElement* next;
};

class LinkedList : public ConseqData, public NotConseqData {
public:
    LinkedList();
    virtual ~LinkedList();
public: // common interface methods
    virtual void clear();
    virtual bool empty() const;
    virtual size_t size() const;
    virtual Iterator* getIterator() const;

public: // data methods
    virtual bool erase(Object* object);
    virtual bool insert(Object* object);

public: //consequent methods
    virtual void pushBack(Object* object);
    virtual bool popBack();
    virtual void pushFront(Object* object);
    virtual bool popFront();
    virtual Object* front() const;
    virtual Object* back() const;


private:
    LinkedListElement* myHead;
    size_t mySize;

    //friend LinkedListIterator;

};






#endif	/* _LINKEDLIST_H */

