#include <iostream>
using namespace std;
#include "book.h"
#include <cstring>


int main(void)
{
	char title[31];
	char author[21];
	strcpy(title, "A Song of Ice and Fire");
	strcpy(author, "George R.R. Martin");
	
	Book b1;
	b1.Set(title,author,FICTION,19.99);
	b1.Display();
	return 0;
}