/*
 * bigint.cpp
 *
 *  Created on: 27.02.2010
 *      Author: snowwlex
 */

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include "bigint.h"

BigInt::BigInt(const char* chars) {
	init(chars);
}
BigInt::BigInt(long long l, size_t degree) {
	char chars[1024];
	sprintf (chars, "%lld", l);
	init(chars,degree);
}
BigInt::~BigInt() {
	delete myNumber;
}

BigInt::BigInt(const BigInt& bInt) {
	mySize = bInt.mySize;
	myIsPositive = bInt.myIsPositive;
	myAllocSize = bInt.myAllocSize;
	myNumber = new numtype[myAllocSize];
	for (size_t i = 0; i < mySize; ++i) {
		myNumber[i] = bInt.myNumber[i];
	}
}
BigInt& BigInt::operator= (const BigInt& bInt) {
	mySize = bInt.mySize;
	myIsPositive = bInt.myIsPositive;
	if (myAllocSize <= bInt.myAllocSize) {
		myAllocSize = bInt.myAllocSize;
		delete myNumber;
		myNumber = new numtype[myAllocSize];
	}
	for (size_t i = 0; i < mySize; ++i) {
		myNumber[i] = bInt.myNumber[i];
	}
	return *this;
}
void BigInt::init(const char* chars, size_t degree) {
	size_t i;
	if (*chars == '-') {
		myIsPositive = false;
		++chars;
	}
	else {
		myIsPositive = true;
	}
	mySize = strlen(chars);
	myAllocSize = mySize + degree;
	myNumber = new numtype[myAllocSize];
	for (i = 0; i < degree; ++i ) {
		myNumber[i] = 0;
	}
	for (i = 0; i < mySize; ++i) {
		myNumber[myAllocSize - i - 1] = chars[i] - '0';
	}
	mySize = myAllocSize;
	size_t newsize=mySize;
	bool stop;
	for (i = 0,  stop=false; !stop && i < mySize; ++i) {
		if (myNumber[mySize - i - 1] == 0) {
			--newsize;
		} else {
			stop = true;
		}
	}
	mySize = newsize == 0 ? 1 : newsize;
}
void BigInt::resize(size_t size) {
	if (myAllocSize >= size) {
		return;
	}
	myAllocSize = size;
	numtype *myNumberCopy = new numtype[myAllocSize];
	for (size_t i=0; i<mySize; ++i) {
		myNumberCopy[i] = myNumber[i];
	}
	delete myNumber;
	myNumber = myNumberCopy;
}

int BigInt::compare(const BigInt& bInt) const {
	int comparing;
	size_t i;
	if (mySize == 1 && bInt.mySize == 1 && myNumber[0]==0 && bInt.myNumber[0]==0) {
		comparing = 0;
	} else if (myIsPositive != bInt.myIsPositive ) {
		comparing = (myIsPositive == true ? 1 : -1);
	} else if (mySize != bInt.mySize) {
		if (myIsPositive == true) {
			comparing = (mySize > bInt.mySize ? 1 : -1);
		}
		else {
			comparing = (mySize < bInt.mySize ? 1 : -1);
		}
	} else {
		for (i = 0, comparing = 0 ; comparing == 0 && i < mySize; ++i) {
			if (myNumber[mySize-i-1] != bInt.myNumber[mySize-i-1]) {
				if (myIsPositive == true) {
					comparing = (myNumber[mySize-i-1] > bInt.myNumber[mySize-i-1] ? 1 : -1);
				}
				else {
					comparing = (myNumber[mySize-i-1] < bInt.myNumber[mySize-i-1] ? 1 : -1);
				}
			}
		}
	}
	return comparing;
}
void BigInt::minus(const BigInt& bInt) {
	numtype a,b, result,debet;
	size_t i, newsize, maxsize = mySize > bInt.mySize ? mySize : bInt.mySize;
	bool firstIsMoreByMod = operator>(bInt) ? true : false;
	if (myIsPositive == false) {
		myIsPositive = firstIsMoreByMod;
		firstIsMoreByMod = !firstIsMoreByMod;
	}else {
		myIsPositive = firstIsMoreByMod;
	}
	resize(maxsize*2);
	for (i=0, newsize=1, debet=0; i < maxsize; ++i) {
		if (firstIsMoreByMod == true) {
			a = mySize<=i ? 0 : myNumber[i];
			b = bInt.mySize<=i ? 0 : bInt.myNumber[i];
		}
		else {
			b = mySize<=i ? 0 : myNumber[i];
			a = bInt.mySize<=i ? 0 : bInt.myNumber[i];
		}
		result = a-b-debet;
		debet = 0;
		if (result < 0) {
			debet = 1;
			result += 10;
		}
		myNumber[i] = result;
		if (result > 0) {
			newsize = i+1;
		}
	}
	mySize = newsize;
}
void BigInt::plus(const BigInt& bInt) {
	numtype a,b, result,excess;
	size_t i,maxsize = mySize > bInt.mySize ? mySize : bInt.mySize;
	resize(maxsize*2);
	for (i=0, excess=0; i < maxsize; ++i) {
		a = mySize<=i ? 0 : myNumber[i];
		b = bInt.mySize<=i ? 0 : bInt.myNumber[i];
		result = a+b+excess;
		myNumber[i] = result%10;
		excess = (result - result%10)%9;
	}
	if (excess != 0) {
		myNumber[i] = excess;
		maxsize += 1;
	}
	mySize = maxsize;
}
BigInt BigInt::multiply(numtype _numtype, size_t degree) const {
	BigInt tmpInt;
	tmpInt.resize(mySize*2);
	for (size_t i = 0; i < mySize; ++i) {
		tmpInt.plus( BigInt(myNumber[i] * _numtype, i+degree) );
	}
	return tmpInt;
}

BigInt BigInt::kMultiply(const BigInt& bInt) const {

	if (mySize == 1 && bInt.mySize==1) {
		return BigInt(myNumber[0]*bInt.myNumber[0]);
	}


	size_t maxsize = mySize > bInt.mySize ? mySize : bInt.mySize;
	size_t sepsize = (size_t)(maxsize/2);
	size_t x = maxsize - sepsize;

	BigInt tmpInt;
	BigInt a,b,c,d; //(a+b*x)(c+d*x) = a*c + ( (a+b)(c+d) - (a*c+b*d) )*x + b*d*x^2
	a = split(maxsize, x,false);
	b = split(maxsize, sepsize, true);
	c = bInt.split(maxsize, x,false);
	d = bInt.split(maxsize, sepsize, true);

	BigInt one, two, three;

	// one = a*c
	// two = b*d

	one = a.kMultiply(c);
	two = b.kMultiply(d);

	// three = (a+b)(c+d) - (a*c+b*d)
	three = (a+b).kMultiply(c+d) - (one + two);


	// answer is 'one + two*x^2 + three*x
	tmpInt.plus(one);
	tmpInt.plus(two.addDegree(x*2));
	tmpInt.plus(three.addDegree(x));

	return tmpInt;

}

BigInt& BigInt::addDegree(size_t degree) {
	if (mySize == 1 && myNumber[0] == 0) {
		return *this;
	}
	size_t i;
	resize(mySize+degree);
	for (i = 0; i < mySize; ++i) {
		myNumber[mySize-i-1+degree] = myNumber[mySize - i - 1];
	}
	for (i = 0; i < degree; ++i ) {
		myNumber[i] = 0;
	}
	mySize += degree;
	return *this;
}

BigInt BigInt::split(size_t maxsize, size_t count, bool fromStart) const {
	BigInt tmpInt;
	size_t i;
	if (fromStart == true) {
		size_t diff;
		diff = maxsize - mySize;
		if (diff > count) count = 0;
		else count = count - diff;
	} else {
		if (count > mySize) count = mySize;
	}
	tmpInt.resize(count);
	for (i = 0; i < count; ++i) {
		if (fromStart == true) {
			tmpInt.myNumber[i] =  myNumber[i+(mySize-count)];
		} else {
			tmpInt.myNumber[i] =  myNumber[i];
		}
	}
	if (count > 0) {
		tmpInt.mySize = count;
	} else {
		tmpInt.mySize = 1;
		tmpInt.myNumber[0] = 0;
	}
	return tmpInt;
}


std::ostream& operator<< (std::ostream& stream, const BigInt& bInt) {
	if (bInt.myIsPositive == false && !(bInt.mySize==1 && bInt.myNumber[0] == 0) ) {
		stream << '-';
	}
	for (size_t i = 0; i < bInt.mySize; ++i) {
		stream << bInt.myNumber[bInt.mySize-i-1];
	}
	return stream;
}
bool BigInt::operator== (const BigInt& bInt) const {
	if (compare(bInt) != 0) {
		return false;
	}
	return true;
}
bool BigInt::operator!= (const BigInt& bInt) const {
	if (compare(bInt) == 0) {
			return false;
	}
	return true;
}
bool BigInt::operator< (const BigInt& bInt) const {
	if (compare(bInt) != -1) {
		return false;
	}
	return true;
}
bool BigInt::operator> (const BigInt& bInt) const {
	if (compare(bInt) != 1) {
		return false;
	}
	return true;
}
bool BigInt::operator>= (const BigInt& bInt) const {
	if (compare(bInt) == -1) {
		return false;
	}
	return true;
}
bool BigInt::operator<= (const BigInt& bInt) const {
	if (compare(bInt) == 1) {
		return false;
	}
	return true;
}
BigInt operator-(const BigInt& bInt1, const BigInt& bInt2) {
	BigInt newInt = bInt1;
	return newInt-=bInt2;
}
BigInt operator+(const BigInt& bInt1, const BigInt& bInt2) {
	BigInt newInt = bInt1;
	return newInt+=bInt2;
}
BigInt& BigInt::operator-=(const BigInt& bInt) {
	if (myIsPositive == bInt.myIsPositive) {
		minus(bInt);
	} else {
		if (myIsPositive==true) {
			plus(-bInt);
		}
		else {
			myIsPositive = true;
			plus(-bInt);
			myIsPositive = false;
		}
	}
	return *this;
}
BigInt& BigInt::operator+=(const BigInt& bInt) {
	if (myIsPositive == bInt.myIsPositive) {
		plus(bInt);
	}
	else {
		if (myIsPositive==true) {
			minus(-bInt);
		}
		else {
			myIsPositive = true;
			minus(bInt);
			myIsPositive = !myIsPositive;
		}
	}
	return *this;
}

BigInt operator- (const BigInt& bInt) {
	BigInt newInt = bInt;
	newInt.myIsPositive = !newInt.myIsPositive;
	return newInt;
}
BigInt& BigInt::operator++ () {
	return operator+=(1);
}
BigInt& BigInt::operator-- () {
	return operator-=(1);
}
BigInt BigInt::operator++ (int i) {
	BigInt newInt = *this;
	operator+=(1);
	return newInt;
}
BigInt BigInt::operator-- (int i) {
	BigInt newInt = *this;
	operator-=(1);
	return newInt;
}
BigInt operator*(const BigInt& bInt1, const BigInt& bInt2) {
	BigInt newInt = bInt1;
	return newInt*=bInt2;
}
BigInt& BigInt::operator*= (const BigInt& bInt) {
	BigInt oldInt = *this;
	size_t i,maxsize = mySize > bInt.mySize ? mySize : bInt.mySize;
	oldInt.myIsPositive = true;
	resize(maxsize*2);
	mySize = 1;
	myNumber[0] = 0;
	myIsPositive = (myIsPositive == bInt.myIsPositive ? true : false);
	for (i = 0; i<bInt.mySize; ++i) {
		plus( oldInt.multiply(bInt.myNumber[i], i) );
	}
	return *this;
}
BigInt operator/(const BigInt& bInt1, const BigInt& bInt2) {
	BigInt newInt = bInt1;
	return newInt/=bInt2;
}
BigInt& BigInt::operator/= (const BigInt& bInt) {
	bool isPositive = (myIsPositive == bInt.myIsPositive ? true : false);
	*this = kMultiply(bInt);
	myIsPositive = isPositive;
	return *this;
}

