/*
 * main.cpp
 *
 *  Created on: 27.02.2010
 *      Author: snowwlex
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "bigint.h"

void crashtest() {
	int select,select2;
	bool bool_res1,bool_res2;
	long long value1, value2, result;

	BigInt a;
	BigInt b;
	BigInt c;
	for (long i = 0; i < 100 ; ++i) {
		value1 = rand()%100000*(rand()%10000); if (rand()%2) value1 = -value1;
		a = value1;
		cout << "a = " << a << " ";
		select = rand() % 9;

		if (select == 0 || select >= 2) {
			if (select == 0 && rand()%3 == 0) { value2 = value1; } else { value2 = rand()%100000*(rand()%100000); } if (rand()%2) value2 = -value2;
			b = value2;
			cout << " b = " << b << " ";
		} else {
			cout << "     ";
		}


		switch (select) {
			case 0: //comparing
				select2 = rand() % 7;
				switch (select2) {
					case 0: // bool operator< (const BigInt& bInt) const;
						bool_res1 = a < b;
						bool_res2 = (bool_res1 == (value1 < value2));
						cout << "a<b ? ";
						break;
					case 1: // bool operator> (const BigInt& bInt) const;
						bool_res1 = a > b;
						bool_res2 = (bool_res1 == (value1 > value2));
						cout << "a>b ? ";
						break;
					case 2: // bool operator!= (const BigInt& bInt) const;
						bool_res1 = a != b;
						bool_res2 = (bool_res1 == (value1 != value2));
						cout << "a!=b ? ";
						break;
					case 3: // friend bool operator== (const BigInt& bInt1, const BigInt& bInt2);
						bool_res1 = (a == b);
						bool_res2 = (bool_res1 == (value1 == value2));
						cout << "a==b ? ";
						break;
					case 4: // bool operator<= (const BigInt& bInt) const;
						bool_res1 = a <= b;
						bool_res2 = (bool_res1 == (value1 <= value2));
						cout << "a<=b ? ";
						break;
					case 5: // bool operator>= (const BigInt& bInt) const;
						bool_res1 = a >= b;
						bool_res2 = (bool_res1 == (value1 >= value2));
						cout << "a>=b ? ";
						break;
					case 6:  // BigInt& operator= (const BigInt& bInt);
						b = a;
						bool_res2 = (b == value1);
						bool_res1 = (a==b);
						cout << "b=a=" << b << " a =?= b ?";
						break;
				}
				break;
			case 1: // post- and pre- fixes
				select2 = rand() % 4;
				switch (select2) {
					case 0: // BigInt& operator++ ();
						c = ++a;
						result = ++value1;
						bool_res2 = (c == result);
						cout << "++a =  " << c;
						break;
					case 1: // BigInt& operator-- ();
						c = --a;
						result = --value1;
						bool_res2 = (c == result);
						cout << "--a =  " << c;
						break;
					case 2:  // BigInt operator++ (int i);
						c = a++;
						result = value1++;
						bool_res2 = (c == result);
						cout << "a++ =  " << c;
						break;
					case 3: // BigInt operator-- (int i);
						c = a--;
						result = value1--;
						bool_res2 = (c == result);
						cout << "a-- =  " << c;
						break;
					case 4: // friend BigInt operator- (const BigInt& bInt);
						c = -a;
						result = -value1;
						bool_res2 = (c == result);
						cout << "-a =  " << c;
						break;
				}
				break;
			case 2: //arithmetic
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				select2 = rand() % 4;
				switch (select2) {
					case 0: // friend BigInt operator-(const BigInt& bInt1, const BigInt& bInt2);
						c = a - b;
						result = value1 - value2;
						bool_res2 = (c == result);
						cout << "a - b =  " << c;
						break;
					case 1: // friend BigInt operator+(const BigInt& bInt1, const BigInt& bInt2);
						c = a + b;
						result = value1 + value2;
						bool_res2 = (c == result);
						cout << "a + b =  " << c;
						break;
					case 2: //friend BigInt operator*(const BigInt& bInt1, const BigInt& bInt2);
						c = a * b;
						result = value1 * value2;
						bool_res2 = (c == result);
						cout << "a * b =  " << c;
						break;
					case 3: //friend BigInt operator/(const BigInt& bInt1, const BigInt& bInt2);
						c = a / b;
						result = value1 * value2;
						bool_res2 = (c == result);
						cout << "a / b =  " << c;
						break;
				}
				break;
		}

		if (select == 0) {
			cout << " ";
			bool_res1 == true ? cout << "true": cout << "false";
			cout << " ";
		}
		cout << " ";
		if (bool_res2 == true) {
			cout << "allright";
		} else {
			cout << "MISTAKE: ";
			cout << "a = " << value1;
			if (select == 0 || select >= 2) {
				cout << " b = " << value2;
			}
			if (select != 0) {
				cout << " comp_result : " << result;
			}
		}
		cout << endl;

	}

}


void karazubaTest() {

	bool bool_res;
	long long value1, value2, result;

	BigInt a;
	BigInt b;
	BigInt c;

	for (long i = 0; i < 100 ; ++i) {
		//if (i % 10000 == 0) cerr << i << endl;
		value1 = rand()%10000000*(rand()%1000000); if (rand()%2) value1 = -value1;
		a = value1;
		cout << "a = " << a << " ";
		value2 = rand()%10000000*(rand()%1000000); if (rand()%2) value2 = -value2;
		b = value2;
		cout << " b = " << b << " ";

		c = a / b;
		result = value1 * value2;
		bool_res = (c == result);
		cout << "a * b =  " << c;

		if (bool_res == true) {
			cout << " allright";
		} else {
			cout << " MISTAKE: ";
			cout << "a = " << value1;
			cout << " b = " << value2;
			cout << " comp_result : " << result;
		}
		cout << endl;
	}

}

void speedTest() {

	size_t i;
	time_t start, end;
	int q = 100;
	char value1[200];
	char value2[100];
	for (i = 0; i < sizeof(value1)/sizeof(char); ++i) {
		value1[i] = rand()%10 + '0';
		if (i==0 && rand()%2) value1[i]='-';
		if (i== sizeof(value1)/sizeof(char)-1) value1[i]='\0';
	}
	for (i = 0; i < sizeof(value2)/sizeof(char); ++i) {
		value2[i] = rand()%10 + '0';
		if (i==0 && rand()%2) value2[i]='-';
		if (i == sizeof(value2)/sizeof(char)-1) value2[i]='\0';
	}


	BigInt a = value1;
	BigInt b = value2;
	//BigInt a = rand()%100000000;
	//BigInt b = rand()%100000000;
	BigInt c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	time(&start);
	for (long i = 0; i < q ; ++i) {
			c = a / b;
			if (i == 0) cout << "c = " << c << endl;
	}
	time(&end);
	cout << "Time for karatsuba multiply = " << (difftime(end,start)/q) << " sec." << endl;

	time(&start);
	for (long i = 0; i < q ; ++i) {
		c = a * b;
		if (i == 0) cout << "c = " << c << endl;
	}
	time(&end);
	cout << "Time for in-a-column multiply = " << (difftime(end,start)/q) << " sec." << endl;



}


int main () {

	srand ( time(0) );

	//crashtest(); cout << endl;
	//karazubaTest(); cout << endl;
	//speedTest();

	BigInt a = 6, b = 7, c = 8, d = 12;
	BigInt answer;
	answer = a + b * c + d ;
	cout << answer << endl;

}
