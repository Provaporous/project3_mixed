#include "mixed.h"
#include <iostream>
using namespace std;

// Autsin Gottselig
// COP 3330
// Mixed.cpp
//
//	This class creates and modifies mixed fraction objects for use in other main functions.
//	This class will also handle int type conversion and simplifying fractions and turning mixed fractions into improper fractions
//



// << operator
// allows the user to print to the output stream.
// formats the object based on the member data.
ostream& operator<< (ostream& s,const Mixed& f)
{

	if (f.integer == 0 && f.numerator == 0)
	{
		s << 0;
		return s;
	}
	if (f.integer == 0 && f.denominator == 1)
	{
		s << f.numerator;
		return s;
	}
	if (f.numerator == 0)
	{
		s << f.integer;
		return s;
	}
	if (f.integer == 0)
	{
		s << f.numerator << '/' << f.denominator;
		return s;
	}

	s << f.integer << ' ' << f.numerator << '/' << f.denominator;
	return s;
}

// Input operator
// allows the user to create a mixed opject with data from a stream.
// error checks, sets to zero if user messes up.

istream& operator >> (istream& s, Mixed& f)
{
	char junk;
	int tempi, tempn, tempd;
	cin >> tempi >> tempn >> junk >> tempd;
	if (tempi < 0 && tempn < 0)
	{
		f.integer = 0;
		f.numerator = 0;
		f.denominator = 1;
		return s;
	}
	if (tempi < 0 && tempd < 0)
	{
		f.integer = 0;
		f.numerator = 0;
		f.denominator = 1;
		return s;
	}
	if (tempn<0 && tempd<0)
	{
		f.integer = 0;
		f.numerator = 0;
		f.denominator = 1;
		return s;
	}
	if (tempd == 0)
	{
		f.integer = 0;
		f.numerator = 0;
		f.denominator = 1;
		return s;
	}
	else f.denominator = tempd;
	f.integer = tempi;
	f.numerator = tempn;
	return s;
}

// Equality operators
// returns a boolean value based on the relationship between two objects.
// less than
bool operator<(Mixed a, Mixed  b) //passed as copies on purpose
{
	a.ToFraction();
	b.ToFraction();
	int newdenominator = a.denominator*b.denominator;

	a.numerator = a.numerator*(newdenominator / b.denominator);
	b.numerator = (newdenominator / a.denominator)*b.numerator;

	if (a.numerator < b.numerator) return true;
	else return false;
}
//greater than
bool operator>(Mixed a, Mixed b)
{
	return !(a < b);
}
// equal to
bool operator==(Mixed a, Mixed b)
{
	a.ToFraction();
	b.ToFraction();
	int newdenominator = a.denominator*b.denominator;

	a.numerator = a.numerator*(newdenominator / b.denominator);
	b.numerator = (newdenominator / a.denominator)*b.numerator;

	if (a.numerator == b.numerator)return true;
	else return false;
}
//less than or equal to
bool operator<=(Mixed a, Mixed b)
{
	if (a < b || a == b)return true;
	else return false;
}
//greater than or equal to
bool operator>=(Mixed a, Mixed b)
{
	if (a > b || a == b)return true;
	else return false;
}
// not equal to
bool operator!=(Mixed a, Mixed b)
{
	return !(a == b);
}

//CONSTRUCTORS
//
//	The caller can either call with no parameters, 1, or all 3.
//	If an improper numer is passed in, the mixed number is set to zero.

Mixed::Mixed(int i)
{
	integer = i;
	numerator = 0;
	denominator = 1;
}

Mixed::Mixed(int i, int n, int d)
{
	if (i < 0 && n < 0)
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		return;
	}
	if (i < 0 && d < 0)
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		return;
	}
	if (n<0 && d<0)
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		return;
	}
	if (d == 0)
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		return;
	}
	else denominator = d;
	integer = i;
	numerator = n;

}
//Evaluates the object and returns the decimal value.
double Mixed::Evaluate()
{
	double result;
	if (integer>0) result = (double)integer + ((double)numerator / (double)denominator);
	if (integer<0)  result = (double)integer - ((double)numerator / (double)denominator);
	return result;
}
//Simplifies the fraction
void Mixed::Simplify()
{
	int commondemon = gcd(numerator, denominator);
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}
	if (commondemon > 0)
	{
		numerator = numerator / commondemon;
		denominator = denominator / commondemon;
	}
	if (commondemon < 0)
	{
		numerator = numerator / (commondemon*-1);
		denominator = denominator / (commondemon*-1);
	}
	if (integer >= 0 && numerator >= 0)
	{
		while (numerator >= denominator)
		{
			numerator = numerator - denominator;
			integer++;
		}
	}
	else
	{

		if (numerator<0)numerator *= -1;

		while (numerator >= denominator)
		{
			numerator = numerator - denominator;
			integer--;
		}
	}


}

// Returns the greatest common denominator
// Reference: Wikipeadia
//			  http://codereview.stackexchange.com/questions/66711/greatest-common-divisor
int Mixed::gcd(int a, int b)
{
	
	return b == 0 ? a : gcd(b, a % b);
}
// Turns the mixed number object into an improper fraction
void Mixed::ToFraction()
{
	int newnumerator;
	if (integer<0 || numerator<0)newnumerator = (integer*denominator) - numerator;
	else newnumerator = (integer*denominator) + numerator;
	integer = 0;
	numerator = newnumerator;
	int gcdemon = gcd(numerator, denominator);
	if (gcdemon > 1)
	{
		numerator /= gcdemon;
		denominator /= gcdemon;
	}
	if (gcdemon < 1)
	{
		gcdemon *= -1;
		numerator /= gcdemon;
		denominator /= gcdemon;
	}

}
//addition operator
//returns a simplified mixed number
Mixed Mixed::operator+(Mixed m)
{
	Mixed tempL, tempR, result;
	tempL.integer = integer;
	tempL.numerator = numerator;
	tempL.denominator = denominator;
	tempL.ToFraction();
	tempR.integer = m.integer;
	tempR.numerator = m.numerator;
	tempR.denominator = m.denominator;
	tempR.ToFraction();
	tempL.numerator = tempL.numerator*tempR.denominator;
	tempR.numerator = tempR.numerator*tempL.denominator;
	result.denominator = tempL.denominator*tempR.denominator;
	result.numerator = tempL.numerator + tempR.numerator;
	result.Simplify();
	return result;
}
//subtraction operator
//returns a simplified mixed number
Mixed Mixed::operator-(Mixed m)
{
	Mixed tempL, tempR, result;
	tempL.integer = integer;
	tempL.numerator = numerator;
	tempL.denominator = denominator;
	tempL.ToFraction();
	tempR.integer = m.integer;
	tempR.numerator = m.numerator;
	tempR.denominator = m.denominator;
	tempR.ToFraction();
	tempL.numerator = tempL.numerator*tempR.denominator;
	tempR.numerator = tempR.numerator*tempL.denominator;
	result.denominator = tempL.denominator*tempR.denominator;
	result.numerator = tempL.numerator - tempR.numerator;
	result.Simplify();
	return result;
}
//multiplication operator
//returns a simplified mixed number
Mixed Mixed::operator*(Mixed m)
{
	Mixed tempL, tempR, result;
	tempL.integer = integer;
	tempL.numerator = numerator;
	tempL.denominator = denominator;
	tempL.ToFraction();
	tempR.integer = m.integer;
	tempR.numerator = m.numerator;
	tempR.denominator = m.denominator;
	tempR.ToFraction();
	result.numerator = tempL.numerator*tempR.numerator;
	result.denominator = tempL.denominator*tempR.denominator;
	result.integer = 0;
	result.Simplify();
	return result;
}
//division operator
//returns a simplified mixed number
Mixed Mixed::operator/(Mixed m)
{
	Mixed tempL, tempR, result;
	tempL.integer = integer;
	tempL.numerator = numerator;
	tempL.denominator = denominator;
	tempL.ToFraction();
	tempR.integer = m.integer;
	tempR.numerator = m.numerator;
	tempR.denominator = m.denominator;
	tempR.ToFraction();
	result.numerator = tempL.numerator*tempR.denominator;
	result.denominator = tempL.denominator*tempR.numerator;
	result.integer = 0;
	result.Simplify();
	return result;
}
// pre-fix increment
// reference: Fraction class, Bob Myers
Mixed& Mixed::operator++()	
{
	integer = integer + 1;
	return *this;
}
// post-fix increment
// reference: Fraction class, Bob Myers
Mixed Mixed::operator++(int)	
{
	Mixed temp = *this;
	integer = integer + 1;
	return temp;
}
// pre-fix decrement
// reference: Fraction class, Bob Myers
Mixed& Mixed::operator--()	
{
	integer = integer - 1;
	return *this;
}
// post-fix decrement
// reference: Fraction class, Bob Myers
Mixed Mixed::operator--(int) 
{
	Mixed temp = *this;
	integer = integer - 1;
	return temp;
}