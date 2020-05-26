   #include "include/encounter.h"

void Encounter::changeType(Type type, ItemType item) {
    type_ = type;
    item_ = item;
}

Encounter::Encounter(Type type, ItemType item) : type_(type), item_(item) {}

Encounter& Encounter::operator=(const Encounter& other) {
    type_ = other.type_;
    item_ = other.item_;
    return *this;
}

Encounter::Encounter(const Encounter& other) : type_(other.type_), item_(other.item_) {}
