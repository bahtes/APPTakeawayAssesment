#pragma once

#include "Item.h"

class Appetiser : public Item {
public:
    Appetiser(std::string name, double price, int calories, bool shareable, bool twoForOne);
    std::string toString() override;
    ~Appetiser() override;

private:
    bool shareable;
    bool twoForOne;
};
