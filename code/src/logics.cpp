#include "logics.h"


void Encounter::changeType(Type type) {
	type_ = type;
}

Encounter::Encounter(Type type) : type_(type) {};

Encounter& Encounter::operator=(const Encounter& other) {
	type_ = other.type_;
}


Encounter::Encounter(Encounter& other) : type_(other.type_) {}


Encounter Board::getField(size_t i, size_t j) {
	return board_[i][j];
}
void Board::Print()  {
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < size_; j++) {
			if (board_[i][j].getType() == Type::start) {
				if (characterPosition_X == j && characterPosition_Y == i)
					std::cout << "SH ";
				else
					std::cout << "S ";
			}
			else if (board_[i][j].getType() == Type::finnish) {
				if (characterPosition_X == j && characterPosition_Y == i)
					std::cout << "FH ";
				else
					std::cout << "F ";
			}
			else if (board_[i][j].getType() == Type::gift) {
				if (characterPosition_X == j && characterPosition_Y == i)
					std::cout << "GH ";
				else
					std::cout << "G ";
			}
			else if (board_[i][j].getType() == Type::obstacle) {
				std::cout << "X ";
			}
			else if (i == characterPosition_X && j == characterPosition_Y)
				std::cout << "H ";
			else
				std::cout << ". ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
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

bool Board::getCanWin() {
	return canWin;
}

void Board::changeOneFieldType(size_t i, size_t j, Type type) {
	board_[i][j].changeType(type);
}


EndOfTheMove Board::isSomethingOnTheWay(Direction direction, int amountOfFields) {
	EndOfTheMove tmp;
	size_t X = characterPosition_X;
	size_t Y = characterPosition_Y;
	//size_t size = location_.getSize();
	if (direction == Direction::forward) {
		while(amountOfFields > 0 && Y < size_ - 1) {
			if (board_[X][Y + 1].getType() != Type::emptyField) {
				if (board_[X][Y+ 1].getType() == Type::gift) {
					canWin = true;
					board_[X][Y + 1].changeType(Type::emptyField);
					//Y++;
					continue;
				}
				if (board_[X][Y + 1].getType() == Type::obstacle) {
					// std::cout << " obst: " << "X: " << X << "Y: " << Y << "\n";
						tmp.type = board_[X][Y + 1].getType();
						//Y--;
						tmp.x = X;
						tmp.y = Y;
						return tmp;
				}
			}
			amountOfFields--;
			Y++;
		}
	}
	if (direction == Direction::back) {
		while(amountOfFields > 0 && Y > 0) {
			if (board_[X][Y - 1].getType() != Type::emptyField) {
				if (board_[X][Y - 1].getType() == Type::gift) {
					canWin = true;
					board_[X][Y - 1].changeType(Type::emptyField);
					continue;
				}
				tmp.type = board_[X][Y - 1].getType();
				tmp.x = X;
				tmp.y = Y;
				return tmp;
			}
			amountOfFields--;
			Y--;
		}
	}
	if (direction == Direction::right) {
		while(amountOfFields > 0 && X < size_ - 1) {
			if (board_[X + 1][Y].getType() != Type::emptyField && board_[X + 1][Y].getType() != Type::finnish) {
				if (board_[X + 1][Y].getType() == Type::gift) {
					canWin = true;
					board_[X + 1][Y].changeType(Type::emptyField);
					continue;
				}
				tmp.type = board_[X + 1][Y].getType();
				tmp.x = X;
				tmp.y = Y;
				return tmp;
			}
			amountOfFields--;
			X++;
		}
	}
	if (direction == Direction::left) {
		while(amountOfFields > 0 && X > 0) {
			if (board_[X - 1][Y].getType() != Type::emptyField) {
				if (board_[X - 1][Y].getType() == Type::gift) {
					canWin = true;
					board_[X - 1][Y].changeType(Type::emptyField);
					continue;
				}
				tmp.type = board_[X - 1][Y].getType();
				tmp.x = X;
				tmp.y = Y;
				return tmp;
			}
			amountOfFields--;
			X--;
		}
	}
	tmp.type = Type::emptyField;
	tmp.x = X;
	tmp.y = Y;
	return tmp;
}


Type Board::makeTurn(Direction direction, int amountOfFields) {
	EndOfTheMove tmp = isSomethingOnTheWay(direction, amountOfFields);
	characterPosition_X = tmp.x;
	characterPosition_Y = tmp.y;
	return tmp.type;
}


void Game::runGame() {
	size_t size = location_.getSize();
	location_.changeOneFieldType(0, 0, Type::start);
	location_.changeOneFieldType(size - 1, size - 1, Type::finnish);
	location_.changeOneFieldType(0, 3, Type::gift);
	location_.changeOneFieldType(0, 2, Type::obstacle);
	std::string str;
	location_.Print();
	int amountOfFields;
	while (location_.getCharacterPosition_X() != 4 || location_.getCharacterPosition_Y() != 4 || !location_.getCanWin()) {
		std::cin >> str;
		if (str == "exit")
			return;		
		std::cin >> amountOfFields;
		Direction direction;
		if (str == "forward")
			direction = Direction::forward;
		if (str == "back")
			direction = Direction::back;
		if (str == "left")
			direction = Direction::left;
		if (str == "right")
			direction = Direction::right;
		location_.makeTurn(direction, amountOfFields);
		location_.Print();
		std::cout << location_.getCharacterPosition_X() << " " << location_.getCharacterPosition_Y() << "\n";

	}
	std::cout << "YOU WON!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";




}
