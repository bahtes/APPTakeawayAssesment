#include "Appetiser.h"

Appetiser::Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne)
    : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

std::string Appetiser::toString(bool txt) 
{
    return Item::toString(txt) + (shareable ? " (shareable)" : "") + (twoForOne ? " (2-4-1)" : ""); //returns the values from Item then if it is shareable it adds (shareable) and if it is 2 for 1 it adds (2-4-1)
}

bool Appetiser::getTwoForOne()
{
    return twoForOne;
}

char Appetiser::getType()
{
    return 'a';
}

Appetiser::~Appetiser()
{

}
