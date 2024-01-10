#pragma once

#include "Item.h"

#include <memory>
#include <vector>

class ItemList {  //abstract class, everything is to be overriden
public:
    virtual std::string add(Item* item) = 0;
    virtual std::string removeItem(int index) = 0;
    virtual std::string toString(bool txt) = 0;
    virtual std::vector<Item*>& getItems() = 0;
    virtual ~ItemList() = default;
};
