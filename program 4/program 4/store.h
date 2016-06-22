#ifndef _STORE_H
#define _STORE_H
#include "book.h"
class Store
{
public:
	Store();
	~Store();
	void SetBalance(double b);
	void Insert(const char* t, const char* a, Genre g, double p);				// Insert an entry into the directory.
	void Lookup() const;		// Look up a name in the directory.
	void Sell();				
	void GenreSummary(Genre g);				
	void Inventory();



private:
	double balance;
	int maxSize,								//max entries
		currentSize;							//current entries
	Book * bookList;							//pointer to book array
	void Grow();								// Increase max size











};























#endif