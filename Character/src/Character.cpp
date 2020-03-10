/* Author: Itsenko Ekaterina */

#include <utility>
#include <cstring>
#include "Character.h"

//! default constructor
Character::Character(CharacterSkills& cs)
    : character_level_(1), race_(CharRace::dragonborn),
    class_(CharClass::fighter), cs_(cs) {
    name_ = new char[strlen("Sergey") + 1];
    strcpy(name_, "Sergey");
    symb_on_field_ = 'C';
}

//! non-default constructor
Character::Character(const char *name, CharacterSkills& cs)
    : cs_(cs), character_level_(1),
    race_(CharRace::dragonborn), class_(CharClass::fighter) {
        symb_on_field_ = 'C';
        name_ = new char[strlen(name) + 1];
        strcpy(name_, name);
}

//! getters
const char* Character::getName() const {
    return name_;
}

char Character::getSymbOnField() const {
    return symb_on_field_;
}