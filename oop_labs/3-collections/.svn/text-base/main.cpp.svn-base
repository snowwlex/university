#include <cstdlib>
#include <iostream>

#include "common.h"
#include "tests.h"

int main() {

    tests();


    std::cout << std::endl << "MAIN EXAMPLE: " << std::endl;
    Map *m = new MapIntf(new LinkedList());

     Object *k = new StringObject("Some str");
       Object *v = new IntObject(6);


    m->set(k, v);

    Object *o = new IntObject(5);

    m->set(k, o);
    if (m->contains_key(k)) std::cout << "As expected\n";
    else std::cout << "Something wrong\n";
    v = m->value(k);
    std::cout << *v << "\n";

    Iterator* i = m->getIterator();
    for (i->first(); i->is(); i->next()) {
        PairObject *mp = (PairObject*) i->get();
        std::cout << *mp->getFirst()
                << " - " << *mp->getSecond()
                << "\n";
    }
    delete i;

    delete m;

    return 0;
}

