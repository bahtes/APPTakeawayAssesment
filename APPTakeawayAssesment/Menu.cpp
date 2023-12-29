#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Menu.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"


Menu::Menu(std::string filename)
{
	ReadCSV(filename);
}

void Menu::ReadCSV(std::string filename)
{
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
	}

	// Read the file line by line
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;
		std::istringstream iss(line);
		std::string value;

		// Parse the line into comma-separated values
		while (std::getline(iss, value, ',')) {
			row.push_back(value);
		}

		// Add the row to the CSV data
		CSVData.push_back(row);
	}

	// Close the file
	file.close();

	loadMenu(filename);

}

void Menu::loadMenu(std::string& filename) 
{

	char type;
	std::string name;
	float price;
	int calories;
	bool shareable;
	bool twoForOne;
	float abv;
	int volume;

	for (int i = 0; i < CSVData.size(); i++)
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

std::string Menu::add(Item* item) 
{
	items.push_back(item);
	return item->getName() + " has been added to menu\n\n";
}

Item* Menu::getItem(int i)
{
	choice = items[i - 1];
	return choice;
}

std::string Menu::removeItem(int index) 
{
	if (index > 0 && index <= items.size()) {
		std::string eraseMsg = items[index]->getName() + " has been removed from menu\n\n";
		items.erase(items.begin() + index - 1);
		return eraseMsg;
	}
	return "No item has been removed incorrect input\n\n";
}

std::string Menu::toString(bool txt) 
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

bool Menu::toBool(std::string s)
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

 std::vector<Item*>& Menu::getItems()  
{
	return items;
}

Menu::~Menu()
{
	for (Item* item : items)
	{
		delete item;
	}
}

