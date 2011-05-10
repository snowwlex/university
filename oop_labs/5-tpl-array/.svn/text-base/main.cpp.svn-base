
#include <iostream>

#include "VarArray.h"
#include "tests.h"

class MyClass {
public:

    MyClass(int value) : myValue(value) {
    }
public:

    int getValue() const {
        return myValue;
    }
private:
    int myValue;
};

template <>
struct traits<MyClass *> {
    int compare(MyClass *a, MyClass* b) {
        if (a == 0) return -1;
        if (b == 0) return +1;
        return a->getValue() - b->getValue();
    }
};


struct cmp {
    int compare(MyClass *a,MyClass*b) {
        if (a->getValue() > b->getValue()) {
            return -1;
        }
        if (a->getValue() == b->getValue()) {
            return 0;
        }
        return 1;
    }
};

typedef VarArray<int> Array1;
//typedef VarArray<MyClass*, traits<MyClass*> > Array2;
typedef VarArray<MyClass*, cmp > Array2;

int main() {


    tests();
    
    Array1 a1;
    Array2 a2;

    a1.add(4);
    a1.add(3);
    a1.sort();

    a2.add(new MyClass(8));
    a2.add(new MyClass(7));
    a2.sort();

    std::cout << "a1:" << std::endl;
    for (int i = 0; i < a1.length(); i++) {
        std::cout << i << ": " << a1[i] << std::endl;
    }
    std::cout << "a2:" << std::endl;
    for (int i = 0; i < a2.length(); i++) {
        std::cout << i << ": " << a2[i]->getValue() << std::endl;
        
    }

    return 0;
}
