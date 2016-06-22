#include <iostream>
#include "book.h"
#include <cstring>
#include <iomanip>
#include <cstring>
using namespace std;



Book::Book()
{
	strcpy(title, "Default title");
	strcpy(author, "Default author");
	type = COMPUTER;
	price = 13.37;
}
// default constructor, sets up blank book object

void Book::Set(const char* t, const char* a, Genre g, double p)
{
	strcpy(title, t);
	strcpy(author, a);
	type = g;
	price = p;
}

const char* Book::GetTitle() const	// returns the title stored in the object
{
	return title;
}
const char* Book::GetAuthor() const	// returns the author
{
	return author;
}
double Book::GetPrice() const		// returns the price
{
	return price;
}
Genre Book::GetGenre() const		// returns the genre
{
	return type;
}
void Book::Display() const			// described below
{
	/* Display() function
	The member function Display() should print out a Book object on one line
	as follows, in an organized manner. (Monetary output should be in dollars
	and cents notation, to two decimal places):
	Title		              Author		  Genre		Price
	Examples:
	Programming for Dummies       Marvin Dipwart      Computer   $  24.95
	Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95
	*/

	cout << left << setw(31) << title
		<< setw(21) << author;
	switch (type)
	{
		case 0:
			cout << setw(11) << "Fiction";
			break;
		case 1:
			cout << setw(11) << "Mystery";
			break;
		case 2:
			cout << setw(11) << "Sci-Fi";
			break;
		case 3:
			cout << setw(11) << "Computer";
			break;
	}
		cout<<setprecision(2) << fixed <<'$'<<right<< setw(7)<< price<<endl;
}