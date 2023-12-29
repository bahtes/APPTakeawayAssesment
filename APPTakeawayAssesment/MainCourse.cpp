#include "MainCourse.h"

MainCourse::MainCourse(std::string name, double price, int calories)
    : Item(name, price, calories) {}

MainCourse::~MainCourse()
{

}

bool MainCourse::getTwoForOne()
{
    return false;
}

char MainCourse::getType()
{
    return 'm';
}
