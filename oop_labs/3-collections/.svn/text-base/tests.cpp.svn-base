#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include <stdexcept>

#include "common.h"
#include "tests.h"

TEST(LinkedList, IteratorCheck1) {

    LinkedList* ll = new LinkedList;

    ll->popBack();
    ll->popFront();

    ll->pushBack(new IntObject(8));
    ll->pushBack(new IntObject(12));
    ll->pushBack(new IntObject(13));

    CHECK(*ll->back() == IntObject(13));
    CHECK(*ll->front() == IntObject(8));

    ll->popBack();
    ll->pushFront(new IntObject(100));

    CHECK(ll->size() == 3);

    CHECK(*ll->back() == IntObject(12));
    CHECK(*ll->front() == IntObject(100));


    Iterator* i = ll->getIterator();
    for (; i->is(); i->next()) {
        IntObject* intObj = (IntObject*) i->get();
        //std::cout << *intObj << std::endl;
    }
    delete i;


    ll->popFront();
    ll->popFront();

    CHECK(ll->size() == 1);

    CHECK (*ll->back() == IntObject(12));
    CHECK (*ll->front() == IntObject(12));

    ll->popFront();
    CHECK(ll->empty() == true);

    delete ll;

}

TEST(QueueLinkedList, WorkCheck2) {


    Queue* q = new QueueIntf(new LinkedList);

    q->push(new IntObject(25));
    q->push(new IntObject(26));
    q->push(new IntObject(27));
    q->push(new IntObject(28));

    Iterator* i = q->getIterator();
    for (; i->is(); i->next()) {
        IntObject* intObj = (IntObject*) i->get();
       // std::cout << *intObj << std::endl;
    }

    CHECK(*q->front() == IntObject(25));
    CHECK(*q->back() == IntObject(28));

    q->pop();
    q->pop();
    q->pop();

    CHECK(q->empty() == false);
    CHECK(q->size() == 1);
    q->pop();
    CHECK(q->empty() == true);
    CHECK(q->size() == 0);


    i = q->getIterator();
    for (i->first(); i->is(); i->next()) {
        IntObject* intObj = (IntObject*) i->get();
        // std::cout << *intObj << std::endl;
    }
    delete i;

    delete q;

}

TEST(RnBTree, ManyInserts3) {
    RnBTree* t = new RnBTree;
    CHECK(t->size() == 0);
    IntObject* a = new IntObject(10);
    t->insert(a);
    CHECK(t->size() == 1);
    for (int i = 0; i < 999; ++i) {
        t->insert(new IntObject(i));
    }
    CHECK(t->size() == 1000)
    t->erase(a);
    CHECK(t->size() == 999)
    CHECK(t->empty() == false);
    t->clear();
    CHECK(t->size() == 0);
    delete t;
}

TEST(RnBTree, Iterator4) {
    RnBTree* t = new RnBTree;

    for (int i = 0; i < 1000; ++i) {
        IntObject* a = new IntObject(i);
        t->insert(a);
    }

    Iterator* i = t->getIterator();
    for (i->first(); i->is(); i->next()) {
        //  std::cout << *i->get() << " ";
    }
    delete i;

    CHECK(t->size() == 1000);

    delete t;
}

TEST(RnBTree, IteratorCrashTest5) {
    RnBTree* t = new RnBTree;

    Iterator* i = t->getIterator();
    for (i->first(); i->is(); i->next()) {

    }
    delete i;

    i = t->getIterator();
    CHECK_THROWS_EX(for (int j = 0; j < 100; ++j) {
        i->next(); }, std::logic_error);

    delete i;



    delete t;
}

TEST(Set, WorkWith6) {
    Set* set = new SetToBinaryTree(new RnBTree);
    Object *k = new StringObject("Some str");
    set->set(k);
    CHECK(set->contains_key(k) == true);
    set->erase(k);
    CHECK(set->empty() == true);

    delete set;
}

TEST(Map, SomeWorkWith7) {
    Map* map = new MapToBinaryTree(new RnBTree);
    map->clear();
    Object* k = new StringObject("Alabama");
    Object* v = new StringObject("Socks");
    CHECK(map->contains_key(k) == false);
    CHECK(map->empty() == true);
    map->erase(k);
    CHECK(map->empty() == true);
    CHECK_THROWS_EX(map->value(k), std::logic_error);
    map->set(k, v);
    CHECK(map->size() == 1);
    Object* getV = map->value(k);
    CHECK(*getV == *v);
    map->erase(k);
    CHECK(map->size() == 0);
    delete map;
}

TEST(Map, Inserts8) {

    Map* map = new MapToBinaryTree(new RnBTree);

    Object* k1 = new StringObject("Alabama");
    Object* v1 = new StringObject("Socks");
    map->set(k1, v1);
    CHECK(map->contains_key(k1) == true);
    Object *getV1 = map->value(k1);
    CHECK(*v1 == *getV1);


    Object* k2 = new StringObject("RangerDanger");
    Object* v2 = new IntObject(35);
    map->set(k2, v2);
    CHECK(map->contains_key(k2) == true);
    Object *getV2 = map->value(k2);
    CHECK(*v2 == *getV2);

    CHECK(map->size() == 2);
    map->clear();

    k1 = new IntObject(20);
    v1 = new IntObject(35);
    map->set(k1, v1);
    CHECK(map->contains_key(k1) == true);
    getV1 = map->value(k1);
    CHECK(*v1 == *getV1);

    k2 = new IntObject(13);
    v2 = new StringObject("Forever");
    map->set(k2, v2);
    CHECK(map->contains_key(k2) == true);
    getV2 = map->value(k2);
    CHECK(*v2 == *getV2);

    delete map;
}

TEST(Map, Iterator9) {
    Map* map = new MapToBinaryTree(new RnBTree);
    char str[11];
    Object* k;
    Object* v;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < sizeof (str); ++j) {
            str[j] = rand() % 26 + 65;
        }
        str[10] = '\0';
        k = new StringObject(str);
        v = new IntObject(rand() % 20);
        map->set(k, v);
    }

    CHECK(map->size() == 100);

    Iterator* i = map->getIterator();

    for (i->first(); i->is(); i->next()) {
        PairObject* pairObj = static_cast<PairObject*> (i->get());
        //std::cout << *pairObj->first() << " = " << *pairObj->second() << std::endl;
        //std::cout << *pairObj << std::endl;
    }
    delete i;
    delete map;
}

TEST(MapIntf, SomeWorkWith10) {
    Map* map = new MapIntf(new LinkedList);
    map->clear();
    Object* k = new StringObject("Alabama");
    Object* v = new StringObject("Socks");
    CHECK(map->contains_key(k) == false);
    CHECK(map->empty() == true);
    map->erase(k);
    CHECK(map->empty() == true);
    CHECK_THROWS_EX(map->value(k), std::logic_error);
    map->set(k, v);
    CHECK(map->size() == 1);
    Object* getV = map->value(k);
    CHECK(*getV == *v)
    map->erase(k);
    CHECK(map->size() == 0);
    delete map;
}

TEST(MapIntf, Inserts11) {

    Map* map = new MapIntf(new LinkedList);

    Object* k1 = new StringObject("Alabama");
    Object* v1 = new StringObject("Socks");
    map->set(k1, v1);
    CHECK(map->contains_key(k1) == true);
    Object *getV1 = map->value(k1);
    CHECK(*v1 == *getV1);


    Object* k2 = new StringObject("RangerDanger");
    Object* v2 = new IntObject(35);
    map->set(k2, v2);
    CHECK(map->contains_key(k2) == true);
    Object *getV2 = map->value(k2);
    CHECK(*v2 == *getV2);

    CHECK(map->size() == 2);
    map->clear();

    k1 = new IntObject(20);
    v1 = new IntObject(35);
    map->set(k1, v1);
    CHECK(map->contains_key(k1) == true);
    getV1 = map->value(k1);
    CHECK(*v1 == *getV1);

    k2 = new IntObject(13);
    v2 = new StringObject("Forever");
    map->set(k2, v2);
    CHECK(map->contains_key(k2) == true);
    getV2 = map->value(k2);
    CHECK(*v2 == *getV2);

    delete map;

}

TEST(MapIntf, Iterator12) {
    Map* map = new MapIntf(new LinkedList);
    char str[11];
    Object* k;
    Object* v;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < sizeof (str); ++j) {
            str[j] = rand() % 26 + 65;
        }
        str[10] = '\0';
        k = new StringObject(str);
        v = new IntObject(rand() % 20);
        map->set(k, v);
    }

    CHECK(map->size() == 100);

    Iterator* i = map->getIterator();

    for (i->first(); i->is(); i->next()) {
        PairObject* pairObj = static_cast<PairObject*> (i->get());
        //std::cout << *pairObj->first() << " = " << *pairObj->second() << std::endl;
        //std::cout << *pairObj << std::endl;
    }
    delete i;
    delete map;
}

TEST(Map, DoubleInsertCheck13) {
    Map* map = new MapToBinaryTree(new RnBTree);
    Object *k = new StringObject("Some str");
    Object *v = new IntObject(6);

    map->set(k, v);
    Object *o = new IntObject(5);
    map->set(k, o);
    CHECK(map->contains_key(k) == true);
    v = map->value(k);
    CHECK(*v == IntObject(5));
    CHECK(map->size() == 1);

}

TEST(MapIntf, DoubleInsertCheck14) {
    Map* map = new MapIntf(new LinkedList);
    Object *k = new StringObject("Some str");
    Object *v = new IntObject(6);
    map->set(k, v);
    Object *o = new IntObject(5);
    map->set(k, o);
    CHECK(map->contains_key(k) == true);
    v = map->value(k);
    CHECK(*v == IntObject(5));
    CHECK(map->size() == 1);

}

void tests() {

    MyTestResult results;
    TestRegistry::runAllTests(results);
    std::cout << "Errors count: " << results.getFailureCount() << std::endl;

}
