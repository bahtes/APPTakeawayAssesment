#pragma once

#include "Item.h"

class MainCourse : public Item {
public:
    MainCourse(std::string name, double price, int calories);
    std::string toString() override;
    ~MainCourse() override;
};
