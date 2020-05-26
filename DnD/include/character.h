/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <string>
#include <iosfwd>
#include "character_skills.h"
#include "backpack.h"
#include "enums.h"

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
    Hero(std::string name, const CharacterSkills& cs, const Backpack& bp);
    ~Hero() override;

    CharacterSkills cs_;
    Backpack bp_;

    void setName(std::string name);
    std::string getName() const;
    CharacterSkills getHeroSkills() const;
    CharRace getRace() const;
    CharClass getClass() const;
    void heroInfo();

private:
    size_t character_level_;
    std::string name_;
    CharRace race_;
    CharClass class_;
    SuperPowers sp_;
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
