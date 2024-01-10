#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Menu.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"


Menu::Menu(std::string filename)  //constructor, takes the filename and calls ReadCSV with the filename as the argument
{
	ReadCSV(filename);
}

void Menu::ReadCSV(std::string filename)  //reads the CSV
{
	std::ifstream file(filename);  //opens file

	if (!file.is_open()) {  //checks if file is open if not it outputs an error
		std::cerr << "Error opening file: " << filename << "\n";
	}

	std::string line;
	while (std::getline(file, line)) //reads the file line by line
	{
		std::vector<std::string> row;
		std::istringstream iss(line);
		std::string value;

		while (std::getline(iss, value, ',')) //puts each comma seperated variable into a vector for the row
		{
			row.push_back(value);
		}

		CSVData.push_back(row);  //pushes the row vector into the CSVData 2D vector
	}

	file.close();  //closes file

	loadMenu();  //runs loadMenu

}

void Menu::loadMenu() //loads the menu
{

	char type;
	std::string name;
	float price;
	int calories;
	bool shareable;
	bool twoForOne;
	float abv;
	int volume;

	for (int i = 0; i < CSVData.size(); i++)  //gets all of the data from a row of the menu and puts in into variables, it uses these variables to create a new object of its respective type
	{

		type = CSVData[i][0][0];
		name = CSVData[i][1];
		price = std::stof(CSVData[i][2]);
		calories = std::stoi(CSVData[i][3]);

		if (!CSVData[i][4].empty())
		{
			shareable = toBool(CSVData[i][4]);
		}

		if (!CSVData[i][5].empty())
		{
			twoForOne = toBool(CSVData[i][5]);
		}

		if (type == 'b')
		{
			abv = std::stof(CSVData[i][7]);
		}

		if (type == 'b')
		{
			volume = std::stoi(CSVData[i][6]);
		}
		


		switch (type)
		{
		case 'a':
			add(new Appetiser (name, price, calories, shareable, twoForOne));
			break;
		case 'm':
			add(new MainCourse(name, price, calories));
			break;
		case 'b':
			add(new Beverage(name, price, calories, abv, volume));
			break;
		default:
			std::cerr << "Unknown item type: " << type << std::endl;
			break;
		}
	}
}

std::string Menu::add(Item* item) //a function that can be used to add an item to the menu 
{
	items.push_back(item);
	return item->getName() + " has been added to menu\n\n";
}

Item* Menu::getItem(int i)  //gets an item from the menu
{
	choice = items[i - 1];
	return choice;
}

std::string Menu::removeItem(int index) //removes an item from the menu
{
	if (index > 0 && index <= items.size()) {
		std::string eraseMsg = items[index]->getName() + " has been removed from menu\n\n";
		items.erase(items.begin() + index - 1);
		return eraseMsg;
	}
	return "No item has been removed incorrect input\n\n";
}

std::string Menu::toString(bool txt) //gets the titles for the item type in the menu
{
	bool ap = false;
	bool main = false;
	bool bev = false;

	std::string result;
	for (size_t i = 0; i < items.size(); ++i) 
	{
		if (items[i]->getType() == 'a' and !ap)
		{
			result += "\n\t(Appitisers)\n\n";
			ap = true;
		}
		else if (items[i]->getType() == 'm' and !main)
		{
			result += "\n\t(Mains)\n\n";
			main = true;
		}
		else if (items[i]->getType() == 'b' and !bev)
		{
			result += "\n\t(Beverages)\n\n";
			bev = true;
		}
		result += "(" + std::to_string(i + 1) + ") " + items[i]->toString(txt) + "\n";
	}
	return result;
}

bool Menu::toBool(std::string s)  //transforms a string to a bool
{
	if (s == "y")
	{
		return true;
	}
	else if (s == "n")
	{
		return false;
	}
	else
	{
		std::cout << "input not recognized returning false";
		return false;
	}
}

 std::vector<Item*>& Menu::getItems()  //returns all items in the menu
{
	return items;
}

Menu::~Menu()  //menu deconstructor
{
	for (Item* item : items)
	{
		delete item;
	}
}

