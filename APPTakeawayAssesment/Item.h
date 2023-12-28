#pragma once

#include <string>

class Item {
public:
    Item(std::string name, float price, int calories);
    virtual std::string toString();
    virtual ~Item() = default;
    float getPrice();
    std::string getName();
    int getCalories();

protected:
    std::string name;
    float price;
    int calories;
};