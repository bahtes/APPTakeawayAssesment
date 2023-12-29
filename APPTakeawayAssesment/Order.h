#pragma once

#include "ItemList.h"

class Order : public ItemList {
public:
    Order();
    std::string add(Item* item) override;
    std::string removeItem(int index) override;
    double calculateTotal();
    double calculateSavings();
    std::string toString(bool txt)  override;
    void printReceipt();
    std::vector<Item*>& getItems() override;
    ~Order() override;

private:
    std::vector<Item*> items;
};
