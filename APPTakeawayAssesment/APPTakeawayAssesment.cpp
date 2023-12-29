/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	Item* choice{};

	bool done = false;

	cout << "\nType help to see directions on how to use this program\n\n";

	while (userCommand != "exit" and !done)
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << "\n";

			cout << menu.toString(false);

			cout << "\n";
		}
		else if (command.compare("add") == 0)
		{
			cout << "\n";

			cout << "How many items would you like to add: ";
			getline(cin, userCommand);
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string multi = parameters[1];

			int j = 2;

			for (int i = 0; i < stoi(multi); i++)
			{
				cout << "What would you like to add for Item " << to_string(i + 1) << " (input the number next to the item in menu) ";
				getline(cin, userCommand);
				char* cstr = new char[userCommand.length() + 1];
				strcpy(cstr, userCommand.c_str());

				char* token;
				token = strtok(cstr, " ");

				
				parameters.push_back(token);
				token = strtok(NULL, " ");

				string command = parameters[j];

				j++;

				string num = command;
				choice = menu.getItem(stoi(num));
				cout << order.add(choice);
			}

			cout << "\n";
		}
		else if (command.compare("remove") == 0)
		{
			cout << "\n";

			cout << order.toString(false);

			cout << "Which Item would you like to remove: ";
			getline(cin, userCommand);
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string rem = parameters[1];

			cout << order.removeItem(stoi(rem));

			cout << "\n";
		}
		else if (command.compare("checkout") == 0)
		{
			cout << "\n";

			cout << order.toString(false) << "\n";
			cout << "Savings: \x9C" << order.calculateSavings() << "\n";
			cout << "Total: \x9C" << order.calculateTotal() << "\n";

			cout << "Would you like to purchase and finalise order (y/n): ";
			getline(cin, userCommand);
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string checkingOut = parameters[1];

			if (checkingOut.compare("y") == 0)
			{
				order.printReceipt();
				cout << "\nThank you for your order\n\n";
				done = true;
			}
			else if (checkingOut.compare("n") == 0)
			{
				cout << "\nOrder not placed, you may edit your order\n\n";
			}
			else
			{
				cout << "\Input not recognized, defaulted to N, Order not placed, you may edit your order\n\n";
			}
		}
		else if (command.compare("help") == 0)
		{
			cout << "\nTo see the menu type 'menu'\nTo add items to your order type 'add'\nTo remove items from your order type 'remove'\nTo checkout type 'checkout'\nFor help type 'help'\nTo exit type 'exit'\n\n";
		}
		else
		{
			cout << "\nInput not recognized, please try again\n\n";
		}

		parameters.clear();
	
	}

	cout << "Press any key to quit...";
	std::getchar();

	delete choice;
	menu.~Menu();
	order.~Order();

}
