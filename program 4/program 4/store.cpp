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
