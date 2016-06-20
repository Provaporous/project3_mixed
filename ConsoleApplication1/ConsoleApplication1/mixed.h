#ifndef MIXED_H_
#define MIXED_H_
#include <iostream>

using namespace std;

// Austin Tyler Gottselig
// Program 3
// Mixed Class.h




class Mixed
{
	friend ostream& operator<< (ostream& s,const Mixed& f);			// output operator
	friend istream& operator >> (istream& s, Mixed& f);			// extraction operator
	friend bool operator<(Mixed a, Mixed b);					// less than operator
	friend bool operator>(Mixed a, Mixed b);					// greater than operator
	friend bool operator==(Mixed a, Mixed b);					// equals to operator
	friend bool operator<=(Mixed a, Mixed b);					// less than or equals to operator
	friend bool operator>=(Mixed a, Mixed b);					// greater than or equals to operator
	friend bool operator!=(Mixed a, Mixed b);					// not equal to operator
public:
	Mixed(int i = 0);											// default constructer with conversion.
	Mixed(int i, int n, int d);									// constuctor
	double Evaluate();					// returns decimal value
	void Simplify();					//Fixes improper fractions into mixed numbers
	void ToFraction();					// converts an object to an improper fraction
	int gcd(int a, int b);				//returns greatest common denominator
	Mixed operator+(Mixed m);			// addition operator
	Mixed operator-(Mixed m);			// subtraction operator
	Mixed operator*(Mixed m);			// multiplication operator
	Mixed operator/(Mixed m);			// division operator
	Mixed& operator++();	// prefix increment
	Mixed operator++(int);	// postfix increment
	Mixed& operator--();	// prefix decrement
	Mixed operator--(int);	// postfix decrement


private:
	int integer;			// member data
	int numerator;
	int denominator;
};

#endif
