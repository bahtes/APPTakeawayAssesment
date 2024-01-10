#include "MainCourse.h"

MainCourse::MainCourse(std::string name, double price, int calories)  //constructor
    : Item(name, price, calories) {}

MainCourse::~MainCourse()  //destructor
{

}

bool MainCourse::getTwoForOne()  //gets two for one
{
    return false;
}

char MainCourse::getType()  //gets type
{
    return 'm';
}
