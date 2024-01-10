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

	
	Menu menu = Menu("menu.csv");  //create a menu object from a CSV file

	Order order = Order();  //create an order object

	Item* choice{};  //create and initialise a pointer of type Item

	bool done = false;  //create a boolean that is used to exit out of program gracefully when an checkout is complete

	cout << "\nType help to see directions on how to use this program\n\n";

	while (userCommand != "exit" and !done)  //while the user input isn't exit and done = false carry on the loop
	{
		getline(cin, userCommand);  //gets user input
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

		if (command.compare("menu") == 0) {  //if user input is menu
			cout << "\n";

			cout << menu.toString(false);  //run menu to string with the argument false which indicates that the formatting is for console and not txt output

			cout << "\n";
		}
		else if (command.compare("add") == 0)  //if user menu is add
		{
			cout << "\n";

			cout << "How many items would you like to add: ";
			getline(cin, userCommand);  //gets user input
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string multi = parameters[1];

			int j = 2;  //uses j to make sure parameters are correct if the for loop below is ran multiple times

			for (int i = 0; i < stoi(multi); i++)  //runs however many times the user specifies so they can add multiple items
			{
				if (stoi(multi) > 1)  //if they want to add more than one item tells them which item they are on and changed grammar
				{
					cout << "What would you like to add for Item " << to_string(i + 1) << " (input the number next to the item in menu) ";  //what would you like to add for the current item
				}
				else
				{
					cout << "What would you like to add (input the number next to the item in menu) ";
				}
				
				getline(cin, userCommand);  //gets user input
				char* cstr = new char[userCommand.length() + 1];
				strcpy(cstr, userCommand.c_str());

				char* token;
				token = strtok(cstr, " ");

				
				parameters.push_back(token);
				token = strtok(NULL, " ");

				string num = parameters[j];

				j++;

				choice = menu.getItem(stoi(num));  //sets choice equal to the specified item
				cout << order.add(choice);  //adds the item to the order, returns string telling them if it has been sucessful or not, prints it
			}

			cout << "\n";
		}
		else if (command.compare("remove") == 0)  //if user input is remove
		{
			cout << "\n";

			cout << order.toString(false);  //outputs the current order with the argument false which indicates that the formatting is for console and not txt output

			cout << "Which Item would you like to remove: ";
			getline(cin, userCommand);  //user input
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string rem = parameters[1];

			cout << order.removeItem(stoi(rem));  //removes specified item, returns string telling them if it has been sucessful or not, prints it

			cout << "\n";
		}
		else if (command.compare("checkout") == 0)  //if user input is checkout
		{
			cout << "\n";

			cout << order.toString(false) << "\n";  //outputs the current order with the argument false which indicates that the formatting is for console and not txt output
			cout << "Savings: \x9C" << order.calculateSavings() << "\n";  //outputs the savings for the order
			cout << "Total: \x9C" << order.calculateTotal() << "\n";  //outputs the total for the order

			cout << "Would you like to purchase and finalise order (y/n): ";
			getline(cin, userCommand);  //user input
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");


			parameters.push_back(token);
			token = strtok(NULL, " ");

			string checkingOut = parameters[1];

			if (checkingOut.compare("y") == 0)  //if the user input is y
			{
				order.printReceipt();  //saves recipt as txt
				cout << "\nThank you for your order\n\n";
				done = true;  //sets done to true so while loop doesn't continue and exits program
			}
			else if (checkingOut.compare("n") == 0)  //if user input is n
			{
				cout << "\nOrder not placed, you may edit your order\n\n";
			}
			else  //if user input isn't recognised
			{
				cout << "\Input not recognized, defaulted to N, Order not placed, you may edit your order\n\n";
			}
		}
		else if (command.compare("help") == 0)  //if user input is help
		{
			cout << "\nTo see the menu type 'menu'\nTo add items to your order type 'add'\nTo remove items from your order type 'remove'\nTo checkout type 'checkout'\nFor help type 'help'\nTo exit type 'exit'\n\n";
		}
		else if (!command.compare("exit") == 0) //if user input isn't recognised, !command.compare("exit") == 0 is there as otherwise it would output  "Input not recognized, please try again" when the input is exit
		{
			cout << "\nInput not recognized, please try again\n\n";
		}

		parameters.clear();  //resets parameters
	
	}

	cout << "Press any key to quit...";
	std::getchar();

	delete choice;  //deletes choice
	menu.~Menu();  //calls the menu deconstructor
	order.~Order();  //calls the order deconstructor

}
