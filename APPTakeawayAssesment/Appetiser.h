#pragma once

#include "Item.h"

class Appetiser : public Item {
public:
    Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne);
    std::string toString(bool txt) override;
    bool getTwoForOne() override;
    char getType() override;
    ~Appetiser() override;

private:
    bool shareable;
    bool twoForOne;
};
