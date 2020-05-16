/* Author: Itsenko Ekaterina */

#include "include/item.h"

//!@class Item: realization
//! default constructor
Item::Item() {
    item_type_ = ItemType::none;
}

Item::Item(ItemType t) {
    item_type_ = t;
}

//! getters
ItemType Item::getItemType() const {
    return item_type_;
}

//! setters
void Item::setItemType(ItemType item_type) {
    Item::item_type_ = item_type;
}


bool Item::operator==(const Item r) {
    return item_type_ == r.item_type_;
}
