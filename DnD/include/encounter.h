#ifndef ENCOUNTER_H_INCLUDED
#define ENCOUNTER_H_INCLUDED
#include "enums.h"

class Encounter {
private:
    Type type_;
    ItemType item_;

public:
    Encounter() : type_(Type::emptyField), item_(ItemType::none) {}
    explicit Encounter(Type type, ItemType item = ItemType::none);
    Encounter(const Encounter& other);
    Encounter& operator=(const Encounter& other);
    ~Encounter() {}
    Type getType() {return type_; }
    ItemType getItem() { return item_; }
    void changeType(Type type, ItemType item = ItemType::none);
};

#endif
