#include "Appetiser.h"

Appetiser::Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne)  //constructor
    : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

std::string Appetiser::toString(bool txt)  //runs Item toString then adds things specific for appetiser
{
    return Item::toString(txt) + (shareable ? " (shareable)" : "") + (twoForOne ? " (2-4-1)" : ""); //returns Item values and adds sharable and two for one if they are true
}

bool Appetiser::getTwoForOne()  //gets two for one
{
    return twoForOne;
}

char Appetiser::getType()  //gets type
{
    return 'a';
}

Appetiser::~Appetiser()  //deconstructor
{

}
