#include "Item.h"

Item::Item(std::string name, float price, int calories) //constructor
    : name(name), price(price), calories(calories) {}


std::string Item::toString(bool txt) //runs Item toString
{
    std::string priceStr = std::to_string(price);  //changes the price for a nicer format
    priceStr.erase(priceStr.find_last_not_of('0') + 1, std::string::npos);
    priceStr.erase(priceStr.find_last_not_of('.') + 1, std::string::npos);

    if (!txt)  //if txt is true then it outputs for txt format if it is false it outputs in console format, I did this as the pound sign doesn't show correctly in the console I assume it is not in the character set, I use /x9C and it output a pound sign in console
    {
        return name + ": \x9C" + priceStr + ", " + std::to_string(calories) + " cal";  //returns string with Item values for console output
    }
    else
    {
        return name + ": £" + priceStr + ", " + std::to_string(calories) + " cal";  //returns string with Item values for txt file output
    }
}

float Item::getPrice()  //gets price
{
    return price;
}

std::string Item::getName()  //gets name
{
    return name;
}

char Item::getType()  //gets type
{
    return 'i';
}

bool Item::getTwoForOne() //runs Item toString and adds things specific to beverage
{
    return false;
}

