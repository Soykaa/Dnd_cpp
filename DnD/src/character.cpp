/* Author: Itsenko Ekaterina */

#include "include/character.h"

#include <utility>
#include "include/backpack.h"

//!@class Character: realization
Character::Character()
    : health_(100)
    {}

Character::~Character() = default;

size_t Character::getHealth() const {
    return health_;
}

void Character::setHealth(size_t health) {
    Character::health_ = health;
}

//!@class Hero: realization
//! default constructor
Enemy::Enemy()
    : Character(), hit_points_(rand() % 18 + 1),
    class_(CharClass::enemy) {}

//! destructor
Enemy::~Enemy() = default;

//! getters
CharClass Enemy::getClass() const {
    return class_;
}

size_t Enemy::getHitPoints() const {
    return hit_points_;
}

//! setters
void Enemy::setHitPoints(size_t hit_points) {
    Enemy::hit_points_ = hit_points;
}

//!@class Hero: realization
//! default constructor
Hero::Hero(const CharacterSkills& cs, Backpack  bp)
        : Character()
        , cs_(cs)
        , bp_(std::move(bp))
        , character_level_(1)
        , name_("Sergey") {
    int num_for_race = rand() % 3 + 1, num_for_class = rand() % 3 + 1,
    num_for_sp = rand() % 3 + 1;

    switch (num_for_race) {
        case 1:
            race_ = CharRace::dragonborn;
            break;
        case 2:
            race_ = CharRace::elf;
            break;
        default:
            race_ = CharRace::human;
            break;
    }

    switch (num_for_class) {
        case 1:
            class_ = CharClass::wizard;
            break;
        case 2:
            class_ = CharClass::druid;
            break;
        default:
            class_ = CharClass::fighter;
            break;
    }
    switch (num_for_sp) {
        case 1:
            sp_ = SuperPowers::athletics;
            break;
        case 2:
            sp_ = SuperPowers::persuasion;
            break;
        default:
            sp_ = SuperPowers::acrobatics;
            break;
    }
}

//! non-default constructor
Hero::Hero(std::string name, const CharacterSkills& cs, Backpack  bp)
        : Character()
        , cs_(cs)
        , bp_(std::move(bp))
        , character_level_(1)
        , name_(std::move(name))
        , race_(CharRace::dragonborn)
        , class_(CharClass::fighter)
        , sp_(SuperPowers::persuasion) {}

//! Destructor
Hero::~Hero() = default;

void Hero::setName(std::string name){
    name_ = std::move(name);
}

//! getters
std::string Hero::getName() const {
    return name_;
}

CharRace Hero::getRace() const {
    return race_;
}

CharClass Hero::getClass() const {
    return class_;
}

SuperPowers Hero::getSP() const {
    return sp_;
}

void Hero::setClass(CharClass cc) {
    Hero::class_ = cc;
}

void Hero::setRace(CharRace cr) {
    Hero::race_ = cr;
}

void Hero::setSP(SuperPowers sp) {
    Hero::sp_ = sp;
}
