
#ifndef _IBASEDATA_H
#define	_IBASEDATA_H

#include "Iterator.h"

class BaseData {
public:
    virtual ~BaseData() { }
    virtual void clear() = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual Iterator* getIterator() const = 0;
protected:
    BaseData() { }
    BaseData(const BaseData&);
private:

};


#endif	/* _IBASEDATA_H */

