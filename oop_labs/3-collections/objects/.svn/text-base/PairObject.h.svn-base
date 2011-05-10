/* 
 * File:   PairObject.h
 * Author: snowwlex
 *
 * Created on 4 Май 2010 г., 17:10
 */

#ifndef _PAIROBJECT_H
#define	_PAIROBJECT_H

#include "../interfaces/Object.h"
class PairObject : public Object {
public:

    PairObject( Object* one = 0, Object* two = 0 );
    PairObject(const PairObject& object);
    virtual PairObject & operator=(const Object& object);
    virtual ~PairObject();

public:
    Object* getFirst() const;
    Object* getSecond() const;
    void setFirst(Object* object);
    void setSecond(Object* object);
    
public:
    virtual bool operator<(const Object& object) const;
    virtual bool operator==(const Object& object) const;

    virtual std::ostream& printTo(std::ostream& stream) const;

    //friends:
    friend std::ostream & operator<<(std::ostream& stream, const PairObject& object);
private:
    Object* myOne;
    Object* myTwo;

};

#endif	/* _PAIROBJECT_H */

