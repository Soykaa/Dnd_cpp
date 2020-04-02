#include "include/board.h"

Board::Board() { 
	h = new Character(cs);
};

Encounter Board::getField(size_t i, size_t j) {
	return board_[i][j];
}

Type Board::getFieldType(size_t i, size_t j) {
	return board_[i][j].getType();
}

size_t Board::getSize() {
	return size_;
}

size_t Board::getCharacterPosition_X() {
	return characterPosition_X;
}

size_t Board::getCharacterPosition_Y() {
	return characterPosition_Y;
}

bool Board::canWin() {
	int cur_dexterity = h->cs_.getDexterity();
	return cur_dexterity >= 19;
}

void Board::takeGift(size_t deltaDexterity) {
	board_[characterPosition_X][characterPosition_Y].changeType(Type::emptyField);
	h->cs_.setDexterity(h->cs_.getDexterity() + deltaDexterity);
}

void Board::changeOneFieldType(size_t i, size_t j, Type type) {
	board_[i][j].changeType(type);
}

void Board::makeTurn(Direction direction) {
	size_t X = characterPosition_X;
	size_t Y = characterPosition_Y;
	if (direction == Direction::down) {
			if (board_[X][Y + 1].getType() != Type::emptyField) {
				if (board_[X][Y + 1].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_Y++;
		if (characterPosition_Y >= size_)
			characterPosition_Y--;
	}
	if (direction == Direction::up) {
		if (characterPosition_Y <= 0)
			return;
		if (board_[X][Y - 1].getType() != Type::emptyField) {
			if (board_[X][Y - 1].getType() == Type::obstacle) {
				return;
			}
		}
	characterPosition_Y--;
	if (characterPosition_Y < 0)
		characterPosition_Y++;
	}
	if (direction == Direction::right) {
			if (board_[X + 1][Y].getType() != Type::emptyField) {
				if (board_[X + 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X++;
		if (characterPosition_X >= size_)
			characterPosition_X--;
	}
	if (direction == Direction::left) {
		if (characterPosition_X <= 0)
			return;
			if (board_[X - 1][Y].getType() != Type::emptyField) {
				if (board_[X - 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X--;
		if (characterPosition_X < 0)
			characterPosition_X++;
	}
}