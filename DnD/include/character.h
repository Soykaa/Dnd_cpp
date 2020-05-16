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
    char getSymbOnField() const;

<<<<<<< HEAD
	size_t getHealth() const;
	CharacterSkills getCharacterSkills() const;
	CharRace getRace() const;
	CharClass getClass() const;

	void setHealth(size_t health);
=======
    size_t getActionPoints() const;
    CharacterSkills getHeroSkills() const;
    CharRace getRace() const;
    CharClass getClass() const;

    void setActionPoints(size_t ap);

    void heroInfo();
    CharacterSkills cs_;
    Backpack bp_;
>>>>>>> 05761682c0771e37e6abc971aa4794c67b51ee69

private:
    char* name_;
    size_t character_level_;
    size_t action_points_;
    char symb_on_field_;
    CharRace race_;
    CharClass class_;
<<<<<<< HEAD
    size_t health_;
	char* name_;
	char symb_on_field_;
=======
>>>>>>> 05761682c0771e37e6abc971aa4794c67b51ee69
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
    char symb_on_field_;
    CharClass class_;
};

#endif //CHARACTER.H
