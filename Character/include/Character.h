/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <iosfwd>
#include "CharacterSkills.h"
#include "Backpack.h"

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
    Hero(CharacterSkills& cs, Backpack& bp);
    Hero(const char* name, CharacterSkills& cs, Backpack& bp);
    ~Hero() override;

    const char* getName() const;
    char getSymbOnField() const;

    size_t getActionPoints() const;
    CharacterSkills getHeroSkills() const;
    CharRace getRace() const;
    CharClass getClass() const;

    void setActionPoints(size_t ap);

    void heroInfo();

private:
    char* name_;
    size_t character_level_;
    size_t action_points_;
    char symb_on_field_;
    CharRace race_;
    CharClass class_;
    CharacterSkills& cs_;
    Backpack& bp_;
};

//! @class Enemy
class Enemy: public Character {
public:
    explicit Enemy();
    ~Enemy() override;

    CharClass getClass() const;
    char getSymbOnField() const;
    size_t getHitPoints() const;

    void setHitPoints(size_t hit_points);
private:
    size_t hit_points_; // just to make an attack
    char symb_on_field_;
    CharClass class_;
};

#endif //CHARACTER.H
