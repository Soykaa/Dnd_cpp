/* Author: Itsenko Ekaterina */

#include "include/item.h"

//!@class Item: realization
//! default constructor
Item::Item() {
    item_type_ = ItemType::none;
}

//! getters
ItemType Item::getItemType() const {
    return item_type_;
}

//! setters
void Item::setItemType(ItemType item_type) {
    Item::item_type_ = item_type;
}
