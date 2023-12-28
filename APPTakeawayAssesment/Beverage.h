#pragma once

#include "Item.h"

class Beverage : public Item {
public:
    Beverage(std::string name, float price, int calories, float abv, int volume);
    std::string toString() override;
    ~Beverage() override;

private:
    double abv;
    int volume;
};
