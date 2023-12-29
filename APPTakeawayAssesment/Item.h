#pragma once

#include <string>

class Item {
public:
    Item(std::string name, float price, int calories);
    virtual std::string toString(bool txt);
    virtual ~Item() = default;
    float getPrice();
    std::string getName();
    virtual char getType();
    virtual bool getTwoForOne();

protected:
    std::string name;
    float price;
    int calories;
};