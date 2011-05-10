#ifndef _VARARRAY_H
#define	_VARARRAY_H

#include <stdexcept>
#include <iostream>
#include <cstring>



#include <map>

template <typename T>
struct traits {
    int compare(const T& a, const T & b) { // -1 means a < b ; 1 means a > b; 0 means a==b
        if (a < b) {
            return -1;
        }
        if (b < a) {
            return 1;
        }
        return 0;
    }
};





// template specializations:

template <>
struct traits<const char*> {

    int compare(const char* a, const char* b) {
        int cmp = strcmp(a, b);
        if (cmp < 0) {
            return -1;
        }
        if (cmp > 0) {
            return 1;
        }
        return 0;
    }
};

template <>
struct traits<char> {

    int compare(char a, char b) {
        if (a < b) {
            return -1;
        }
        if (b < a) {
            return 1;
        }
        return 0;
    }
};

template <>
struct traits<int> {

    int compare(int a, int b) {
        if (a < b) {
            return -1;
        }
        if (b < a) {
            return 1;
        }
        return 0;
    }
};

template < typename T, class TR = traits<T> >
class VarArray {
public: //constructors & destructor

    VarArray() {
        myData = 0;
        mySize = 0;
        myCapacity = 0;
    }

    ~VarArray() {
        delete[] myData;
    }

    VarArray(const VarArray<T>& varArray) {
        mySize = varArray.mySize;
        myCapacity = varArray.myCapacity;
        myData = new T[myCapacity];
        for (size_t i = 0; i < mySize; ++i) {
            myData[i] = varArray.myData[i];
        }
    }

    VarArray & operator=(const VarArray<T>& varArray) {
        if (myCapacity < varArray.myCapacity) {
            delete[] myData;
            myData = new T[varArray.myCapacity];
        }
        myCapacity = varArray.myCapacity;
        mySize = varArray.mySize;
        for (size_t i = 0; i < mySize; ++i) {
            myData[i] = varArray.myData[i];
        }
        return *this;
    }

public: // getters

    size_t length() const {
        return mySize;
    }

    bool empty() const {
        return mySize == 0;
    }

    const T & operator[](size_t number) const {
        if (number >= mySize) {
            throw std::out_of_range("out of range!");
        }
        return myData[number];
    }

public: // using

    void add(const T & t) {
        if (mySize == myCapacity) {
            reallocCapacity(myCapacity * 2 + 1);
        }
        myData[mySize++] = t;
    }

public: // algorithms:
    void sort();
    bool binarySearch(const T & t) const;

private: //helpers

    void reallocCapacity(size_t size) {

        if (myCapacity >= size) {
            return;
        }

        myCapacity = size;
        T* myDataCopy = new T[myCapacity];
        for (size_t i = 0; i < mySize; ++i) {
            myDataCopy[i] = myData[i];
        }
        delete[] myData;
        myData = myDataCopy;

    }


private:
    T* myData;
    size_t mySize;
    size_t myCapacity;

};

template <typename T, class TR>
void VarArray<T, TR>::sort() {
    size_t i, j;
    TR trait;
    for (i = 0; i < mySize; ++i) {
        for (j = 0; j < mySize - 1; ++j) {
            if (trait.compare(myData[j + 1], myData[j]) < 0) {
                T tmp = myData[j];
                myData[j] = myData[j + 1];
                myData[j + 1] = tmp;
            }
        }
    }
}

template <typename T, class TR>
bool VarArray<T,TR>::binarySearch(const T& t) const {

    if (mySize == 0) {
        return false;
    }
    TR trait;
    size_t leftBound = 0; // индекс перед первым элементом массива }
    size_t rightBound = mySize; // индекс после последнего элемента массива }
    size_t median;

    while (leftBound < (rightBound - 1)) { //       ищем элемент на интервале индексов от i до j, не включая i и j
        median = (leftBound + rightBound) / 2; //   k = элемент посередине интервала
        if (trait.compare(t, myData[median]) < 0) {
            rightBound = median;
        } else {
            leftBound = median;
        }
    }
    if (trait.compare(myData[leftBound], t) == 0) { //      элемент найден
        return true;
    }
    return false;
}





#endif	/* _VARARRAY_H */

