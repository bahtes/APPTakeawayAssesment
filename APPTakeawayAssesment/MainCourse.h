#pragma once

#include "Item.h"

class MainCourse : public Item {
public:
    MainCourse(std::string name, double price, int calories);
    bool getTwoForOne() override;
    char getType() override;
    ~MainCourse() override;
};
