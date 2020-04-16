#include "include/board.h"
#include "include/door.h"
#include "include/game_board.h"

extern GameBoard *game;

Board::Board() { 
    h1 = new Character(cs);
    h2 = new Character(cs);
};

Encounter Board::getField(size_t i, size_t j) {
    return board_[i][j];
}

Type Board::getFieldType(size_t i, size_t j) {
    return board_[i][j].getType();
}

size_t Board::getAmountOfEncounters() {
    return amountOfEncounters_;
}

size_t Board::getCharacterPosition_X_1() {
    return characterPosition_X_1;
}

size_t Board::getCharacterPosition_Y_1() {
    return characterPosition_Y_1;
}

size_t Board::getCharacterPosition_X_2() {
    return characterPosition_X_2;
}

size_t Board::getCharacterPosition_Y_2() {
    return characterPosition_Y_2;
}

bool Board::canWin_1() {
    int cur_dexterity = h1->cs_.getDexterity();
    return cur_dexterity >= 19;
}

bool Board::canWin_2() {
    int cur_dexterity = h2->cs_.getDexterity();
    return cur_dexterity >= 19;
}

void Board::takeGift_1(size_t deltaDexterity) {
    board_[characterPosition_X_1][characterPosition_Y_1].changeType(Type::emptyField);
    h1->cs_.setDexterity(h1->cs_.getDexterity() + deltaDexterity);
}

void Board::takeGift_2(size_t deltaDexterity) {
    board_[characterPosition_X_2][characterPosition_Y_2].changeType(Type::emptyField);
    h2->cs_.setDexterity(h2->cs_.getDexterity() + deltaDexterity);
}

void Board::changeOneFieldType(size_t i, size_t j, Type type) {
    board_[i][j].changeType(type);
}

void Board::makeTurn_1(Direction direction) {
	size_t X = characterPosition_X_1;
	size_t Y = characterPosition_Y_1;
	if (direction == Direction::down) {
			if (board_[X][Y + 1].getType() != Type::emptyField) {
				if (board_[X][Y + 1].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_Y_1++;
		if (characterPosition_Y_1 >= amountOfEncounters_)
			characterPosition_Y_1--;
		board_[characterPosition_X_1][characterPosition_Y_1].getType() == Type::door ? game->door_->player1 = true : game ->door_->player1 = false;
		if (game->door_->player1 and game->door_->player2) {
		    game->changeLocation();
		}
	}
	if (direction == Direction::up) {
		if (characterPosition_Y_1 <= 0)
			return;
		if (board_[X][Y - 1].getType() != Type::emptyField) {
			if (board_[X][Y - 1].getType() == Type::obstacle) {
				return;
			}
		}
		characterPosition_Y_1--;
		if (characterPosition_Y_1 < 0)
		    characterPosition_Y_1++;
		board_[characterPosition_X_1][characterPosition_Y_1].getType() == Type::door ? game->door_->player1 = true : game ->door_->player1 = false;
	    if (game->door_->player1 and game->door_->player2) {
	        game->changeLocation();
	    }
	}
	if (direction == Direction::right) {
			if (board_[X + 1][Y].getType() != Type::emptyField) {
				if (board_[X + 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X_1++;
		if (characterPosition_X_1 >= amountOfEncounters_)
			characterPosition_X_1--;
		board_[characterPosition_X_1][characterPosition_Y_1].getType() == Type::door ? game->door_->player1 = true : game ->door_->player1 = false;
        if (game->door_->player1 and game->door_->player2) {
            game->changeLocation();
        }
	}
	if (direction == Direction::left) {
		if (characterPosition_X_1 <= 0)
			return;
			if (board_[X - 1][Y].getType() != Type::emptyField) {
				if (board_[X - 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X_1--;
		if (characterPosition_X_1 < 0)
			characterPosition_X_1++;
	}
    board_[characterPosition_X_1][characterPosition_Y_1].getType() == Type::door ? game->door_->player1 = true : game ->door_->player1 = false;
	if (game->door_->player1 and game->door_->player2) {
        game->changeLocation();
    }
}

void Board::makeTurn_2(Direction direction) {
	size_t X = characterPosition_X_2;
	size_t Y = characterPosition_Y_2;
	if (direction == Direction::down) {
			if (board_[X][Y + 1].getType() != Type::emptyField) {
				if (board_[X][Y + 1].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_Y_2++;
		if (characterPosition_Y_2 >= amountOfEncounters_)
			characterPosition_Y_2--;
        board_[characterPosition_X_2][characterPosition_Y_2].getType() == Type::door ? game->door_->player2 = true : game ->door_->player2 = false;
        if (game->door_->player1 and game->door_->player2) {
            game->changeLocation();
        }
	}
	if (direction == Direction::up) {
		if (characterPosition_Y_2 <= 0)
			return;
		if (board_[X][Y - 1].getType() != Type::emptyField) {
			if (board_[X][Y - 1].getType() == Type::obstacle) {
				return;
			}
		}
	characterPosition_Y_2--;
	if (characterPosition_Y_2 < 0)
		characterPosition_Y_2++;
        board_[characterPosition_X_2][characterPosition_Y_2].getType() == Type::door ? game->door_->player2 = true : game ->door_->player2 = false;
        if (game->door_->player1 and game->door_->player2) {
            game->changeLocation();
        }
	}
	if (direction == Direction::right) {
			if (board_[X + 1][Y].getType() != Type::emptyField) {
				if (board_[X + 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X_2++;
		if (characterPosition_X_2 >= amountOfEncounters_)
			characterPosition_X_2--;
        board_[characterPosition_X_2][characterPosition_Y_2].getType() == Type::door ? game->door_->player2 = true : game ->door_->player2 = false;
        if (game->door_->player1 and game->door_->player2) {
            game->changeLocation();
        }
	}
	if (direction == Direction::left) {
		if (characterPosition_X_2 <= 0)
			return;
			if (board_[X - 1][Y].getType() != Type::emptyField) {
				if (board_[X - 1][Y].getType() == Type::obstacle) {
					return;
				}
			}
		characterPosition_X_2--;
		if (characterPosition_X_2 < 0)
			characterPosition_X_2++;
        board_[characterPosition_X_2][characterPosition_Y_2].getType() == Type::door ? game->door_->player2 = true : game ->door_->player2 = false;
        if (game->door_->player1 and game->door_->player2) {
            game->changeLocation();
        }
	}
}
