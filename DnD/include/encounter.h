#ifndef ENCOUNTER_H_INCLUDED
#define ENCOUNTER_H_INCLUDED
#include "utility.h"

class Encounter {
private:
    Type type_;
public:
    Encounter() : type_(Type::emptyField) {}
    explicit Encounter(Type type);
    Encounter(const Encounter& other);
    Encounter& operator=(const Encounter& other);
    ~Encounter() {}
    Type getType() {return type_; }
    void changeType(Type type);
};

#endif
