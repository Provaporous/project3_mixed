#include <iostream>
using namespace std;
#include "book.h"
#include "store.h"
#include <cstring>
#include <cctype>


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
		cout << "\nA : Add a book to inventory" << endl <<
			"F : Find a book from inventory" << endl <<
			"S : Sell a book" << endl <<
			"D : Display the inventory list" << endl <<
			"G : Genre summary" << endl <<
			"M : Show this Menu" << endl <<
			"X : eXit the program" << endl;
		cin >> command;
		
		switch (toupper(command))
		{
		case ('A'):
		{
			char title[31];
			char author[21];
			char genre;
			Genre g;
			double price;
			bool isvalid = true;
			cout << "\nType name: ";
			
			cin.ignore();
			cin.getline(title, 20);		
			cout << "\nType author: ";
			cin.getline(author, 20);

			do
			{
				isvalid = 1;
				cout << "\nEnter Genre (F,M,S, or C): ";
				cin >> genre;

				if (genre == 'F' || genre == 'f')
				{
					g = FICTION;
					isvalid = 0;
				}
				else if (genre == 'M' || genre == 'm')
				{
					g = MYSTERY;
					isvalid = 0;
				}
				else if (genre == 'S' || genre == 's')
				{
					g = SCIFI;
					isvalid = 0;
				}
				else if (genre == 'C' || genre == 'c')
				{
					g = COMPUTER;
					isvalid = 0;
				}
				else cout << "try again!" << endl;
			} while (isvalid==1);
			cout << "enter price of book: ";
			cin >> price;
			bs.Insert(title, author, g, price);

		}
			break;
		case ('F'):cout << "f chosen";
			break;
		case ('S'):cout << "s chosen";
			break;
		case ('D'):
		{
			bs.Inventory();
		}
			break;
		case ('G'):
		{
			//genre summary
			char genre;
			Genre g;
			bool isvalid = true;
			do
			{
				isvalid = 1;
				cout << "\nEnter Genre (F,M,S, or C): ";
				cin >> genre;

				if (genre == 'F' || genre == 'f')
				{
					g = FICTION;
					isvalid = 0;
				}
				else if (genre == 'M' || genre == 'm')
				{
					g = MYSTERY;
					isvalid = 0;
				}
				else if (genre == 'S' || genre == 's')
				{
					g = SCIFI;
					isvalid = 0;
				}
				else if (genre == 'C' || genre == 'c')
				{
					g = COMPUTER;
					isvalid = 0;
				}
				else cout << "try again!" << endl;
			} while (isvalid == 1);
			bs.GenreSummary(g);
		}
			break;
		case ('M'):
			break;
		case ('X'):cout << "Closing Store\n";
			break;
		default:cout << "Invalid menu entry, try again.";
			break;

		}
	} while (toupper(command) != 'X');
	
	return 0;
}