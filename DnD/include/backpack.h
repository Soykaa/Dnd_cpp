/* Author: Itsenko Ekaterina */

#ifndef BACKPACK_H_
#define BACKPACK_H_

#include <vector>
#include <iostream>
#include <iosfwd>
#include "item.h"

class Backpack {
public:
    Backpack() = default;

    void addItem(Item);
    void deleteItem(ItemType type);
    Item getItem(ItemType it);
    bool isFull();
    bool findItem(ItemType it);
    int countItems(ItemType it);
private:
    std::vector<Item> items_;
    std::ostream& output(std::ostream& out);

    friend std::ostream& operator <<(std::ostream& out, Backpack& bp);
};


#endif
