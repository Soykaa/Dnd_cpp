/* Author: Itsenko Ekaterina */

#ifndef BACKPACK_H_
#define BACKPACK_H_

#include <vector>
#include <iostream>
#include <iosfwd>
#include "Item.h"

class Backpack {
public:
    Backpack() = default;
    ~Backpack();
    Backpack(const Backpack&) = delete;
    Backpack& operator=(const Backpack&) = delete;

    void addItem(Item*);
    void deleteItem(ItemType type);
    Item getItem(ItemType it);
    bool isFull();
private:
    std::vector<Item*> items_;
    std::ostream& output(std::ostream& out);

    friend std::ostream& operator <<(std::ostream& out, Backpack& bp);
};


#endif