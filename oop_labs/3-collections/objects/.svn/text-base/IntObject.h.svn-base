
#ifndef _INTOBJECT_H
#define	_INTOBJECT_H

#include <iostream>
#include "../interfaces/Object.h"

class IntObject : public Object {
public:

    IntObject(int i = 0);
    IntObject(const IntObject& intObject);
    virtual IntObject & operator=(const Object& object);
    IntObject & operator=(const IntObject& object);
    virtual ~IntObject();

public:
    virtual bool operator<(const Object& object) const;
    virtual bool operator==(const Object& object) const;
    virtual std::ostream& printTo(std::ostream& stream) const;
    
    //friends:
    friend std::ostream & operator<<(std::ostream& stream, const IntObject& object);
private:
    int myInt;

};
#endif	/* _INTOBJECT_H */

