/*
 * bigint.h
 *
 *  Created on: 27.02.2010
 *      Author: snowwlex
 */

#ifndef BIGINT_H_
#define BIGINT_H_

using namespace std;


typedef short int numtype;
class BigInt {
private:
	numtype *myNumber;
	size_t mySize;
	size_t myAllocSize;
	bool myIsPositive;
	void init(const char* chars, size_t degree=0);
	void resize(size_t size);
	int compare(const BigInt& bInt) const;
	void minus(const BigInt& bInt);
	void plus(const BigInt& bInt);
	BigInt multiply(numtype _numtype, size_t degr) const;
	// for Karazuba's multiply
	BigInt split(size_t maxsize, size_t count, bool fromStart) const;
	BigInt kMultiply(const BigInt& bInt) const;
	BigInt& addDegree(size_t degree);

public:
	BigInt(long long l=0, size_t degree=0);
	BigInt(const char* chars);
	~BigInt();
	BigInt(const BigInt& bInt);
	BigInt& operator= (const BigInt& bInt);

	//compare operators
	bool operator< (const BigInt& bInt) const;
	bool operator> (const BigInt& bInt) const;
	bool operator!= (const BigInt& bInt) const;
	bool operator== (const BigInt& bInt) const;
	bool operator<= (const BigInt& bInt) const;
	bool operator>= (const BigInt& bInt) const;

	//arithmetic operators
	BigInt& operator++ ();
	BigInt& operator-- ();
	BigInt operator++ (int i);
	BigInt operator-- (int i);
	BigInt& operator+= (const BigInt& bInt);
	BigInt& operator-= (const BigInt& bInt);
	BigInt& operator*= (const BigInt& bInt);
	BigInt& operator/= (const BigInt& bInt);
	friend BigInt operator-(const BigInt& bInt1, const BigInt& bInt2);
	friend BigInt operator+(const BigInt& bInt1, const BigInt& bInt2);
	friend BigInt operator- (const BigInt& bInt); // using: c = -a
	friend BigInt operator*(const BigInt& bInt1, const BigInt& bInt2);
	friend BigInt operator/(const BigInt& bInt1, const BigInt& bInt2);
	friend ostream& operator<< (ostream& stream, const BigInt& bInt);


};

#endif /* BIGINT_H_ */
