/* 
 * File:   ConsequentData.h
 * Author: snowwlex
 *
 * Created on 4 Май 2010 г., 6:47
 */

#ifndef _CONSEQUENTDATA_H
#define	_CONSEQUENTDATA_H

#include "Object.h"
#include "BaseData.h"
#include "Iterator.h"

class ConseqData : public BaseData {
public:
    virtual ~ConseqData() { }
public: // consequent access
    virtual void pushBack(Object* object) = 0;
    virtual bool popBack() = 0;
    virtual void pushFront(Object* object) = 0;
    virtual bool popFront() = 0;
    virtual Object* front() const = 0;
    virtual Object* back() const = 0;
protected:
    ConseqData() { }
    ConseqData(const ConseqData& orig);
private:

};

#endif	/* _CONSEQUENTDATA_H */

