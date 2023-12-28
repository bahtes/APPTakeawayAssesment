#pragma once

#include "Item.h"

#include <memory>
#include <vector>

class ItemList {
public:
    virtual void add(Item* item) = 0;
    virtual void removeItem(int index) = 0;
    virtual double calculateTotal() = 0;
    virtual std::string toString() = 0;
    virtual std::vector<Item*>& getItems() = 0;
    virtual ~ItemList() = default;
};
