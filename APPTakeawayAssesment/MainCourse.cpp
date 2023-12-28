#include "MainCourse.h"

MainCourse::MainCourse(std::string name, double price, int calories)
    : Item(name, price, calories) {}

MainCourse::~MainCourse()
{
}

std::string MainCourse::toString()  {
    return Item::toString();
}
