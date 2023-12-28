#include "Beverage.h"

Beverage::Beverage(std::string name, float price, int calories, float abv, int volume)
    : Item(name, price, calories), abv(abv), volume(volume) {}

std::string Beverage::toString() 
{
    std::string abvStr = std::to_string(abv);
    abvStr.erase(abvStr.find_last_not_of('0') + 1, std::string::npos);
    abvStr.erase(abvStr.find_last_not_of('.') + 1, std::string::npos);

    return Item::toString() + " (" + std::to_string(volume) + "ml, " + abvStr + "% abv)";  //returns the Item values then adds the volume and abv
}

Beverage::~Beverage()
{
}