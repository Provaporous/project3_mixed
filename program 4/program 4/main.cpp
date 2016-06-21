#include <iostream>
using namespace std;
#include "book.h"
#include "store.h"
#include <cstring>


int main(void)
{
	Store bs;									//create store object
	double balance;
	cout << "Welcome employee! Please enter the registers starting balance: ";
	cin >> balance;
	bs.SetBalance(balance);					//enter starting balance
	
	char command='Q';
	do
	{
		cout << "\nA:   Add a book to inventory" << endl <<
			"F : Find a book from inventory" << endl <<
			"S : Sell a book" << endl <<
			"D : Display the inventory list" << endl <<
			"G : Genre summary" << endl <<
			"M : Show this Menu" << endl <<
			"X : eXit the program" << endl;
		cin >> command;
		switch (toupper(command))
		{
		case ('A'):cout << "a chosen";
			break;
		case ('F'):cout << "f chosen";
			break;
		case ('S'):cout << "s chosen";
			break;
		case ('D'):cout << "d chosen";
			break;
		case ('G'):cout << "g chosen";
			break;
		case ('M'):cout << "m chosen";
			break;
		case ('X'):cout << "Closing Store\n";
			break;
		default:cout << "Invalid menu entry, try again.";
			break;

		}
	} while (toupper(command) != 'X');
	
	return 0;
}