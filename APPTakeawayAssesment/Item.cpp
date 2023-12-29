#include "Item.h"

Item::Item(std::string name, float price, int calories)
    : name(name), price(price), calories(calories) {}


std::string Item::toString(bool txt) 
{
    std::string priceStr = std::to_string(price);
    priceStr.erase(priceStr.find_last_not_of('0') + 1, std::string::npos);
    priceStr.erase(priceStr.find_last_not_of('.') + 1, std::string::npos);

    if (!txt)
    {
        return name + ": \x9C" + priceStr + ", " + std::to_string(calories) + " cal";  //returns string with Item values
    }
    else
    {
        return name + ": £" + priceStr + ", " + std::to_string(calories) + " cal";  //returns string with Item values
    }
}

float Item::getPrice()
{
    return price;
}

std::string Item::getName()
{
    return name;
}

char Item::getType()
{
    return 'i';
}

bool Item::getTwoForOne()
{
    return false;
}

