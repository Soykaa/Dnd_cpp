/* Author: Itsenko Ekaterina */

#include <string>
#include "include/character.h"
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
    class_(CharClass::enemy) 
    {}

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
Hero::Hero(const CharacterSkills& cs, const Backpack& bp)
        : Character(), character_level_(1),
        cs_(cs), bp_(bp) {
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
            sp_ = SuperPowers::athletics;
            break;
    }


    name_ = "Sergey";
}

//! non-default constructor
Hero::Hero(const char* name, const CharacterSkills& cs, const Backpack& bp)
        : Character(), cs_(cs), bp_(bp),
        character_level_(1), race_(CharRace::dragonborn),
        class_(CharClass::fighter) {
    name_ = name;
}

//! Destructor
Hero::~Hero() = default;

void Hero::setName(std::string name) {
    name_ = name;
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

CharacterSkills Hero::getHeroSkills() const {
    return cs_;
}

void Hero::heroInfo() {
    size_t cur_intelligence = cs_.getIntelligence();
    size_t cur_wisdom = cs_.getWisdom();
    size_t cur_strength = cs_.getStrength();
    size_t cur_dexterity = cs_.getDexterity();
    size_t cur_constitution = cs_.getConstitution();
    size_t cur_charisma = cs_.getCharisma();

    std::string cur_race, cur_class;
    if (race_ == CharRace::dragonborn)
        cur_race = "Dragonborn";
    if (class_ == CharClass::fighter)
        cur_class = "Fighter";

    std::cout << "*********************************************************" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "          " << name_ << "           "
              << "Level " << character_level_ << "            "<< std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << "Race: " << cur_race << std::endl;
    std::cout << "Class: " << cur_class << std::endl;
    std::cout << "Health: " << health_ << std::endl;
    std::cout << "Intelligence: " << cur_intelligence << std::endl;
    std::cout << "Wisdom: " << cur_wisdom << std::endl;
    std::cout << "Strength: " << cur_strength << std::endl;
    std::cout << "Dexterity: " << cur_dexterity << std::endl;
    std::cout << "Constitution: " << cur_constitution << std::endl;
    std::cout << "Charisma: " << cur_charisma << std::endl;
    std::cout << "*********************************************************" << std::endl;
}
