#include "Order.h"
#include <fstream>
#include <iostream>
#include "Item.h"

Order::Order()
{

}

Order::~Order()
{
    for (Item* item : items)
    {
        delete item;
    }
}

void Order::add(Item* item) {
    items.push_back(item);
}

void Order::removeItem(int index) {
    if (index > 0 && index <= items.size()) {
        items.erase(items.begin() + index - 1);
    }
}

double Order::calculateTotal() {
    double total = 0.0;
    for (auto& item : items) {
        total += item->getPrice();
    }
    return total;
}

std::string Order::toString()
{
    std::string result;
    for (size_t i = 0; i < items.size(); ++i) {
        result += "(" + std::to_string(i + 1) + ") " + items[i]->toString() + "\n";
    }
    return result;
}

void Order::printReceipt()
{
    std::ofstream receipt("receipt.txt");
    receipt << toString() << "\nSavings: £0.00\nTotal: £" << calculateTotal() << "\n";
    receipt.close();
}

std::vector<Item*>& Order::getItems() {
    return items;
}
