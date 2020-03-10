/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <iosfwd>
#include "CharacterSkills.h"

//! enums
enum class CharRace {
    dragonborn
};

enum class CharClass {
    fighter
};

//! @class Character
class Character {
public:
    explicit Character(CharacterSkills& cs);
    Character(const char* name, CharacterSkills& cs);

    [[nodiscard]] const char * getName() const;
    [[nodiscard]] char getSymbOnField() const;
private:
    char* name_;
    char symb_on_field_;
    size_t character_level_;
    CharRace race_;
    CharClass class_;
    CharacterSkills& cs_;
};

#endif //CHARACTER.H
