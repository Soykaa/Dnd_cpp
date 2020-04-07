/* Author: Itsenko Ekaterina */

#include <cstring>
#include "Character.h"
#include "Backpack.h"

//!@class Character: realization
Character::Character()
    : health_(100)
    {};

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
    class_(CharClass::enemy) {
    symb_on_field_ = 'E';
}

//! destructor
Enemy::~Enemy() = default;

//! getters
char Enemy::getSymbOnField() const {
    return symb_on_field_;
}

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
Hero::Hero(CharacterSkills& cs, Backpack& bp)
        : Character(), character_level_(1),
        race_(CharRace::dragonborn), class_(CharClass::fighter),
        cs_(cs), action_points_(20), bp_(bp) {
    name_ = new char[strlen("Sergey") + 1];
    strcpy(name_, "Sergey");
    symb_on_field_ = 'H';
}

//! non-default constructor
Hero::Hero(const char *name, CharacterSkills& cs, Backpack& bp)
        : Character(), cs_(cs), bp_(bp),
        character_level_(1), race_(CharRace::dragonborn),
        class_(CharClass::fighter), action_points_(20) {
    symb_on_field_ = 'H';
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
}

//! Destructor
Hero::~Hero() {
    delete [] name_;
}

//! getters
const char* Hero::getName() const {
    return name_;
}

char Hero::getSymbOnField() const {
    return symb_on_field_;
}

size_t Hero::getActionPoints() const {
    return action_points_;
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

//! setters
void Hero::setActionPoints(size_t ap) {
    Hero::action_points_ = ap;
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
    std::cout << "Action points: " << action_points_ << std::endl;
    std::cout << "Intelligence: " << cur_intelligence << std::endl;
    std::cout << "Wisdom: " << cur_wisdom << std::endl;
    std::cout << "Strength: " << cur_strength << std::endl;
    std::cout << "Dexterity: " << cur_dexterity << std::endl;
    std::cout << "Constitution: " << cur_constitution << std::endl;
    std::cout << "Charisma: " << cur_charisma << std::endl;
    std::cout << "*********************************************************" << std::endl;
}