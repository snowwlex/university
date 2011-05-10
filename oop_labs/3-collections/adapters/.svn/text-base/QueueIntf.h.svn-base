#ifndef _QUEUEADAPTER_H
#define	_QUEUEADAPTER_H

#include "../interfaces/Queue.h"
#include "../interfaces/ConseqData.h"

class QueueIntf : public Queue {
public:
    QueueIntf(ConseqData* data);
    virtual ~QueueIntf();
public:
    virtual Object* front() const;
    virtual Object* back() const;
    virtual void push(Object* object);
    virtual void pop();
    virtual bool empty();
    virtual size_t size();
    virtual void clear();
    virtual Iterator* getIterator() const;
private:
    QueueIntf(const QueueIntf&);
private:
    ConseqData* myData;

};

#endif	/* _QUEUEADAPTER_H */

