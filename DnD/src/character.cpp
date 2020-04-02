/* Author: Itsenko Ekaterina */

#include <cstring>
#include "include/character.h"

//! default constructor
Character::Character(CharacterSkills& cs)
		: character_level_(1), race_(CharRace::dragonborn),
		  class_(CharClass::fighter), cs_(cs),
		  health_(10), action_points_(20) {
	name_ = new char[strlen("Sergey") + 1];
	strcpy(name_, "Sergey");
	symb_on_field_ = 'C';
}

//! non-default constructor
Character::Character(const char *name, CharacterSkills& cs)
		: cs_(cs), character_level_(1),
		  race_(CharRace::dragonborn), class_(CharClass::fighter),
		  health_(10), action_points_(20) {
	symb_on_field_ = 'C';
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
}

//! getters
const char* Character::getName() const {
	return name_;
}

char Character::getSymbOnField() const {
	return symb_on_field_;
}

size_t Character::getHealth() const {
	return health_;
}

size_t Character::getActionPoints() const {
	return action_points_;
}

CharRace Character::getRace() const {
	return race_;
}

CharClass Character::getClass() const {
	return class_;
}

CharacterSkills Character::getCharacterSkills() const {
	return cs_;
}

//! setters
void Character::setHealth(size_t health) {
	Character::health_ = health;
}

void Character::setActionPoints(size_t ap) {
	Character::action_points_ = ap;
}

void Character::characterInfo() {
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
