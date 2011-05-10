/* 
 * File:   MapLinkedListAdapter.h
 * Author: snowwlex
 *
 * Created on 15 Май 2010 г., 18:11
 */

#ifndef _MAPLINKEDLISTADAPTER_H
#define	_MAPLINKEDLISTADAPTER_H


#include "../interfaces/Map.h"
#include "../interfaces/NotConseqData.h"

class MapIntf : public Map {
public:

    MapIntf(NotConseqData* myData);

    virtual ~MapIntf();
public:
    virtual void set(Object* key, Object* value);
    virtual bool contains_key(Object* key) const;
    virtual Object* value(Object* key);
    virtual void erase(Object* key);
    virtual bool empty();
    virtual size_t size();
    virtual void clear();
    virtual Iterator* getIterator() const;

private:
    MapIntf(const MapIntf& MapLinkedListAdapter);

private:
    NotConseqData* myData;

};


#endif	/* _MAPLINKEDLISTADAPTER_H */

