#pragma once

#include "ItemList.h"

class Menu : public ItemList {
public:
    Menu(std::string filename);
    ~Menu();
    void ReadCSV(std::string filename);
    void loadMenu(std::string& filename);
    void add(Item* item) override;
    void removeItem(int index) override;
    double calculateTotal() override;
    std::string toString() override;
    bool toBool(std::string s);
    std::vector<Item*>& getItems() override;
    Item* choice;
    void get();

private:
    std::vector<Item*> items;
    std::vector<std::vector<std::string>> CSVData;
};
