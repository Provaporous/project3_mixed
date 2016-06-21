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