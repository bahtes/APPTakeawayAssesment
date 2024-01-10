#include "Beverage.h"

Beverage::Beverage(std::string name, float price, int calories, float abv, int volume)  //constructor
    : Item(name, price, calories), abv(abv), volume(volume) {}

std::string Beverage::toString(bool txt)  //runs Item toString and adds things specific to beverage
{
    std::string abvStr = std::to_string(abv);  //modifies the abv for nicer format
    abvStr.erase(abvStr.find_last_not_of('0') + 1, std::string::npos);
    abvStr.erase(abvStr.find_last_not_of('.') + 1, std::string::npos);

    return Item::toString(txt) + " (" + std::to_string(volume) + "ml, " + abvStr + "% abv)";  //returns the Item values then adds volume and abv
}

bool Beverage::getTwoForOne()  //gets two for one (always false)
{
    return false;
}

char Beverage::getType()  //gets type
{
    return 'b';
}

Beverage::~Beverage()  //deconstructor
{

}
