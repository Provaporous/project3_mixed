#ifndef _STORE_H
#define _STORE_H
#include "book.h"
class Store
{
public:
	Store();
	~Store();
	void SetBalance(double b);




private:
	double balance;
	int maxSize,								//max entries
		currentSize;							//current entries
	Book * bookList;							//pointer to book array
	void Grow();								// Increase max size











};























#endif