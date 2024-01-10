#pragma once

#include "ItemList.h"

class Menu : public ItemList {
public:
    Menu(std::string filename);
    ~Menu();
    void ReadCSV(std::string filename);
    void loadMenu();
    std::string add(Item* item) override;
    std::string removeItem(int index) override;
    std::string toString(bool txt) override;
    bool toBool(std::string s);
    std::vector<Item*>& getItems() override;
    Item* getItem(int i);
    Item* choice;

private:
    std::vector<Item*> items;
    std::vector<std::vector<std::string>> CSVData;
};
