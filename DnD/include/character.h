/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <iosfwd>
#include "character_skills.h"

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

    const char * getName() const;
    char getSymbOnField() const;

    size_t getHealth() const;
    size_t getActionPoints() const;
    CharacterSkills getCharacterSkills() const;
    CharRace getRace() const;
    CharClass getClass() const;

    void setHealth(size_t health);
    void setActionPoints(size_t ap);

    void characterInfo();
    CharacterSkills& cs_;
private:
    size_t character_level_;
    CharRace race_;
    CharClass class_;
    size_t health_;
    size_t action_points_;
    char* name_;
    char symb_on_field_;
};

#endif //CHARACTER.H

