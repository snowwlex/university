#ifndef _OBJECT_H
#define	_OBJECT_H

#include <iostream>

class Object {
public:

    Object() {   }

    virtual Object & operator=(const Object& object) = 0;
    virtual bool operator<(const Object& object) const = 0;
    virtual bool operator==(const Object& object)const = 0;

    virtual ~Object() {
    }

public:

    virtual std::ostream& printTo(std::ostream& stream) const = 0;


private:
    Object(const Object& object);

    //friends:

    friend std::ostream & operator<<(std::ostream& stream, const Object& object) { //dispatching
        return object.printTo(stream);
    }

};

#endif	/* _OBJECT_H */

