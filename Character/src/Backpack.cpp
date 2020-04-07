/* Author: Itsenko Ekaterina */

#include <iostream>
#include "Backpack.h"


//!@class Backpack: realization
//! destructor
Backpack::~Backpack() {
    for (auto & item : items_)
        delete [] item;
}

//! Methods
void Backpack::addItem(Item* it) {
    items_.push_back(it);
}

Item Backpack::getItem(ItemType it) {
    for (auto & item : items_) {
        if (item->getItemType() == it)
            return *item;
    }
    Item nf;
    return nf;
}

bool Backpack::isFull() {
    return items_.size() == 5;
}

void Backpack::deleteItem(ItemType type) {
    for (size_t i = 0; i < items_.size(); i++)
        if (items_[i]->getItemType() == type)
            items_.erase(items_.begin()+i);
}

std::ostream& operator <<(std::ostream& out, Backpack& bp) {
    bp.output(out);
    return out;
}

std::ostream& Backpack::output(std::ostream& out) { // tmp output
    for (int32_t i = 0; i < items_.size(); i++) {
        out << i + 1;
        switch(items_[i]->getItemType()) {
            case ItemType::health_el:
                std::cout << "Health elixir\n";
                break;
            case ItemType::weapon:
                std::cout << "Weapon\n";
                break;
            case ItemType::present:
                std::cout << "Present\n";
                break;
            case ItemType::triangle_key:
                std::cout << "Triangle key\n";
                break;
            case ItemType::square_key:
                std::cout << "Square key\n";
                break;
            default:
                std::cout << "";
        }
    }
    return out;
}







