
#ifndef _STRINGOBJECT_H
#define	_STRINGOBJECT_H

#include <cstdlib>
#include <iostream>

#include "../interfaces/Object.h"

class StringObject : public Object {
public:
    StringObject(const char* chars);
    StringObject(const StringObject& string);
    virtual StringObject & operator=(const Object& object);
    virtual ~StringObject();
public:
    virtual bool operator<(const Object& object) const;
    virtual bool operator==(const Object& object) const;
   virtual std::ostream& printTo(std::ostream& stream) const;
    
private: //help methods
    void copyString(const char* chars);

private:
    char* myString;

    //friends:
    friend std::ostream & operator<<(std::ostream& stream, const StringObject& object);
};

#endif	/* _STRINGOBJECT_H */

