#pragma once

#include "Item.h"

class Beverage : public Item {
public:
    Beverage(std::string name, float price, int calories, float abv, int volume);
    std::string toString(bool txt) override;
    bool getTwoForOne() override;
    char getType() override;
    ~Beverage() override;

private:
    double abv;
    int volume;
};
