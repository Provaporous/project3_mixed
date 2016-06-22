#include <iostream>
#include "store.h"
#include <cstring>
#include <iomanip>
#include <cstring>
using namespace std;


Store::Store()
{
	maxSize = 5;
	currentSize = 0;
	bookList = new Book[maxSize];
}

Store::~Store()
{
	delete[] bookList;
}
void Store::SetBalance(double b)
{
	balance = b;
}
void Store::Grow()

{
	maxSize = currentSize + 5;			// Determine a new size.
	Book* newList = new Book[maxSize];		// Allocate a new array.

	for (int i = 0; i < currentSize; i++)	// Copy each entry into
		newList[i] = bookList[i];		// the new array.

	delete[] bookList;			// Remove the old array
	bookList = newList;			// Point old name to new array.
}

void Store::Insert(const char* t, const char* a, Genre g, double p)
{
	if (currentSize == maxSize)
	{
		Grow();
	}
	bookList[currentSize++].Set(t,a,g,p);
}
// Insert an entry into the directory.
void Store::Lookup() const
{

}// Look up a name in the directory.
void Store::Sell()
{

}
void Store::GenreSummary(Genre g)
{
	
	double genreCost = 0;
	int numbooks = 0;
	if (currentSize == 0)
	{
		cout << "\nNo Books in inventory!\n";
		return;
	}
	cout << left << setw(31) << "Title" << setw(21) << "Author" << setw(11) << "Genre" << setw(7) << "price" << endl;
	for (int i = 0; i < currentSize; i++)
	{
		
		if (bookList[i].GetGenre() == g)
		{
			bookList[i].Display();
			genreCost += bookList[i].GetPrice();
			numbooks++;
			
		}
	}
	cout << "Cost of Genre: $" << genreCost << endl;
	cout << "Number of Books in Genre: " << numbooks << endl;

}

void Store::Inventory()
{
	if (currentSize == 0)
	{
		cout << "\nNo Books in inventory!\n";
		return;
	}
	cout << left << setw(31) << "Title" << setw(21) << "Author" << setw(11) << "Genre" << setw(7) << "Price"<<endl;
	for (int i = 0; i < currentSize; i++)
	{
		bookList[i].Display();
	}
	cout << "Store Balance: $" << balance << endl;
	cout << "Number of Books: " << currentSize << endl;
}
