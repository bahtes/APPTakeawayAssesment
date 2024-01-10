#include "Order.h"
#include <fstream>
#include <iostream>
#include "Item.h"
#include <algorithm>

Order::Order()  //order constructor
{

}

Order::~Order()  //order deconstructor
{
    for (Item* item : items)
    {
        delete item;
    }
}

std::string Order::add(Item* item)  //adds an item to the order
{
    items.push_back(item);
    return item->getName() + " has been added to order\n\n";
}

std::string Order::removeItem(int index) //removes an item from the order
{
    if (index > 0 && index <= items.size()) {
        std::string eraseMsg = items[index - 1]->getName() + " has been removed from order\n\n";
        items.erase(items.begin() + index - 1);
        return eraseMsg;
    }
    return "No item has been removed incorrect input\n\n";
}

double Order::calculateTotal() //calulates the total of all items in the order
{
    double total = 0.0;
    for (auto& item : items) {
        total += item->getPrice();
    }

    total = total - calculateSavings();

    return total;
}

double Order::calculateSavings()  //calcultes the savings for any 2 for 1 items in the order
{
    double savings = 0;
    std::vector<Item*> tfos;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i]->getTwoForOne())
        {
            tfos.push_back(items[i]);
        }
    }

    while (tfos.size() > 1)
    {
        savings += tfos[0]->getPrice();
        tfos.erase(tfos.begin() + 0);
        tfos.erase(tfos.begin() + 0);
    }

    return savings;

}

std::string Order::toString(bool txt)  //returns the order as a string
{
    std::string result;
    for (size_t i = 0; i < items.size(); ++i) {
        result += "(" + std::to_string(i + 1) + ") " + items[i]->toString(txt) + "\n";
    }
    return result;
}

void Order::printReceipt()  //saves the recipt as a txt file
{
    std::ofstream receipt("receipt.txt");
    receipt << toString(true) << "\nSavings: £" << calculateSavings() << "\nTotal: £" << calculateTotal() << "\n";
    receipt.close();
}

std::vector<Item*>& Order::getItems() //gets all the items in the order
{
    return items;
}
