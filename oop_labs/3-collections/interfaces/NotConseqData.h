
#ifndef _DATA_H
#define	_DATA_H

#include "Object.h"
#include "BaseData.h"
#include "Iterator.h"

class NotConseqData : public BaseData {
public:
    virtual ~NotConseqData() { }
    virtual bool insert(Object* key) = 0;
    virtual bool erase(Object* key) = 0;
protected:
    NotConseqData() { }
    NotConseqData(const NotConseqData& orig);
private:

};

#endif	/* _DATA_H */

