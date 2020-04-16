#include "include/encounter.h"

void Encounter::changeType(Type type) {
    type_ = type;
}

Encounter::Encounter(Type type) : type_(type) {}

Encounter& Encounter::operator=(const Encounter& other) {
    type_ = other.type_;
    return *this;
}

Encounter::Encounter(const Encounter& other) : type_(other.type_) {}
