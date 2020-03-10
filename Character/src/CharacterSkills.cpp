/* Author: Itsenko Ekaterina */

#include <iostream>
#include "CharacterSkills.h"

//!@class CharacterSkills: realization
//! default constructor
CharacterSkills::CharacterSkills()
        : intelligence_(rand() % 18 + 1), wisdom_(rand() % 18 + 1),
          strength_(rand() % 18 + 1), dexterity_(rand() % 18 + 1),
          constitution_(rand() % 18 + 1), charisma_(rand() % 18 + 1)
{}

//! non-default constructor
CharacterSkills::CharacterSkills(size_t intelligence, size_t wisdom, size_t strength, size_t dexterity, size_t constitution, size_t charisma)
        : intelligence_(intelligence), wisdom_(wisdom),
          strength_(strength), dexterity_(dexterity),
          constitution_(constitution), charisma_(charisma)
{}

//! setters
void CharacterSkills::setIntelligence(size_t intelligence) {
    CharacterSkills::intelligence_ = intelligence;
}

void CharacterSkills::setWisdom(size_t wisdom) {
    CharacterSkills::wisdom_ = wisdom;
}

void CharacterSkills::setStrength(size_t strength) {
    CharacterSkills::strength_ = strength;
}


void CharacterSkills::setDexterity(size_t dexterity) {
    CharacterSkills::dexterity_ = dexterity;
}

void CharacterSkills::setConstitution(size_t constitution) {
    CharacterSkills::constitution_ = constitution;
}

void CharacterSkills::setCharisma(size_t charisma) {
    CharacterSkills::charisma_ = charisma;
}

//! getters
size_t CharacterSkills::getIntelligence() const {
    return intelligence_;
}

size_t CharacterSkills::getWisdom() const {
    return wisdom_;
}

size_t CharacterSkills::getStrength() const {
    return strength_;
}

size_t CharacterSkills::getDexterity() const {
    return dexterity_;
}

size_t CharacterSkills::getConstitution() const {
    return constitution_;
}

size_t CharacterSkills::getCharisma() const {
    return charisma_;
}
