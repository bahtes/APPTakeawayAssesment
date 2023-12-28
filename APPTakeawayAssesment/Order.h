#pragma once

#include "ItemList.h"

class Order : public ItemList {
public:
    Order();
    void add(Item* item) override;
    void removeItem(int index) override;
    double calculateTotal()  override;
    std::string toString()  override;
    void printReceipt();
    std::vector<Item*>& getItems() override;
    ~Order() override;

private:
    std::vector<Item*> items;
};
