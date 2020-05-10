/* Author: Itsenko Ekaterina */

#ifndef ITEM_H_
#define ITEM_H_

#include <cstddef>

enum class ItemType {
    none,
    weapon,     //bonus for strength
    present,    //must-have to win the game
    health_el,   //bonus for health
    triangle_key,
    square_key
};

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
