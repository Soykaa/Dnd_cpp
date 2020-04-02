#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <array>
#include "utility.h"
#include "encounter.h"
#include "character.h"
#include "character_skills.h"

class Board {
private:
	static const int size_ = 5;
	std::array<std::array<Encounter, size_>, size_> board_;
	size_t characterPosition_X = 0;
	size_t characterPosition_Y = 0;
	CharacterSkills cs;
	Character *h;
public:
	Board();
	Encounter getField(size_t i, size_t j);
	Type getFieldType(size_t i, size_t j);
	size_t getSize();
	size_t getCharacterPosition_X();
	size_t getCharacterPosition_Y();
	bool canWin();
	void makeTurn(Direction direction);
	void takeGift(size_t deltaDexterity);
	void changeOneFieldType(size_t i, size_t j, Type type);
	~Board() {};
};

#endif