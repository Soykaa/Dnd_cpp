/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <iosfwd>
#include "character_skills.h"
#include "backpack.h"

//! enums
enum class CharRace {
    dragonborn,
    dwarf,
    elf,
    gnome,
    human,
    orc
};

enum class CharClass {
    fighter,
    druid,
    paladin,
    ranger,
    rogue,
    warlock,
    wizard,
    enemy //special one!
};

enum class SuperPowers {
    athletics,
    arcrobatics,
    stealth,
    arcana,
    investigation,
    medicine,
    survival,
    deception,
    persuasion
};

//!@class Character
class Character {
public:
    Character();
    virtual ~Character();
    Character(const Character&) = delete;
    Character& operator =(const Character&) = delete;

    size_t getHealth() const;
    void setHealth(size_t health);
protected:
    size_t health_;
};

//! @class Hero
class Hero: public Character {
public:
    Hero(const CharacterSkills& cs, const Backpack& bp);
    Hero(const char* name, const CharacterSkills& cs, const Backpack& bp);
    ~Hero() override;

    const char* getName() const;
    CharacterSkills getHeroSkills() const;
    CharRace getRace() const;
    CharClass getClass() const;
    void heroInfo();
    CharacterSkills cs_;
    Backpack bp_;

private:
    char* name_;
    size_t character_level_;
    size_t action_points_;
    CharRace race_;
    CharClass class_;
};

//! @class Enemy
class Enemy: public Character {
public:
    Enemy();
    ~Enemy() override;

    CharClass getClass() const;
    char getSymbOnField() const;
    size_t getHitPoints() const;

    void setHitPoints(size_t hit_points);
private:
    size_t hit_points_; // just to make an attack
    CharClass class_;
};

#endif //CHARACTER.H
