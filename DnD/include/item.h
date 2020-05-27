/* Author: Itsenko Ekaterina */

#ifndef ITEM_H_
#define ITEM_H_

#include <cstddef>
#include "enums.h"

//! @class Item
class Item {
public:
    Item();
    explicit Item(ItemType t);
    ItemType getItemType() const;
    void setItemType(ItemType t);
    bool operator==(const Item other);
private:
    ItemType item_type_;
};

#endif
