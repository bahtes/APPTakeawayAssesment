#include "Item.h"

Item::Item(std::string name, float price, int calories)
    : name(name), price(price), calories(calories) {}


std::string Item::toString() 
{
    std::string priceStr = std::to_string(price);
    priceStr.erase(priceStr.find_last_not_of('0') + 1, std::string::npos);
    priceStr.erase(priceStr.find_last_not_of('.') + 1, std::string::npos);
    return name + ": \x9C" + priceStr + ", " + std::to_string(calories) + " cal";  //returns string with Item values
}

float Item::getPrice()
{
    return price;
}

std::string Item::getName()
{
    return name;
}

int Item::getCalories()
{
    return calories;
}

