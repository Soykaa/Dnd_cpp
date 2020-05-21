#include "include/board.h"
#include <QDebug>
#include "include/door.h"
#include "include/game_board.h"

extern GameBoard *game;

Board::Board() {
    heroes.resize(2);
}

Encounter Board::getField(size_t i, size_t j) {
    return board_[i][j];
}

Type Board::getFieldType(size_t i, size_t j) {
    return board_[i][j].getType();
}

size_t Board::getAmountOfEncounters() {
    return amountOfEncounters_;
}

int Board::getCharacterPosition_X(int heroNum) {
    return heroes[heroNum].x;
}

int Board::getCharacterPosition_Y(int heroNum) {
    return heroes[heroNum].y;
}


bool Board::canWin(int heroNum) {
    return heroes[heroNum].h->cs_.getDexterity() >= 19;
}


bool Board::canDestroyWall(int heroNum) {
    return heroes[heroNum].h->cs_.getStrength() >=1;
}

void Board::destroyWall(int x, int y) {
        board_[x][y].changeType(Type::emptyField);
    return;
}


void Board::takeGift(size_t deltaDexterity, int heroNum) {
    board_[heroes[heroNum].x][heroes[heroNum].y].changeType(Type::emptyField);
    heroes[heroNum].h->cs_.setDexterity(heroes[heroNum].h->cs_.getDexterity() + deltaDexterity);
}


void Board::changeOneFieldType(size_t i, size_t j, Type type) {
    board_[i][j].changeType(type);
}

destroyableWall Board::check(int heroNum) {
    int X = heroes[heroNum].x;
    int Y = heroes[heroNum].y;
    std::vector<destroyableWall> cords;
    cords.push_back({"left", X + 1, Y});
    cords.push_back({"right", X - 1, Y});
    cords.push_back({"up", X, Y + 1});
    cords.push_back({"down", X, Y - 1});
    for (auto c : cords) {
        if (c.x < 0 || c.x >= amountOfEncounters_ ||
            c.y < 0 || c.y >= amountOfEncounters_) {
                continue;
            }
        if (board_[c.x][c.y].getType() == Type::destroyableWall) {
                return c;
        }
    }
    return {"", -1, -1};
}

void Board::takeItem(int x, int y, int heroNum) {
    if (board_[x][y].getType() == Type::key) {
        heroes[heroNum].h->bp_.addItem(Item(ItemType::triangle_key));
        board_[x][y].changeType(Type::emptyField);
    }
}

bool Board::canOpenDoor(int heroNum) {
    return heroes[heroNum].h->bp_.findItem(ItemType::triangle_key);
}


void Board::makeTurn(Direction direction, int heroNum) {
    int X = heroes[heroNum].x;
    int Y = heroes[heroNum].y;
    if (direction == Direction::down) {
            if (board_[X][Y + 1].getType() != Type::emptyField) {
                if (board_[X][Y + 1].getType() == Type::obstacle || board_[X][Y + 1].getType() == Type::destroyableWall) {
                    return;
                }
            }
        heroes[heroNum].y++;
        if (heroes[heroNum].y >= amountOfEncounters_)
            heroes[heroNum].y--;
    }
    if (direction == Direction::up) {
        if (heroes[heroNum].y <= 0)
            return;
        if (board_[X][Y - 1].getType() != Type::emptyField) {
            if (board_[X][Y - 1].getType() == Type::obstacle || board_[X][Y - 1].getType() == Type::destroyableWall) {
                return;
            }
        }
        heroes[heroNum].y--;
        if (heroes[heroNum].y < 0)
            heroes[heroNum].y++;
    }
    if (direction == Direction::right) {
            if (board_[X + 1][Y].getType() != Type::emptyField) {
                if (board_[X + 1][Y].getType() == Type::obstacle || board_[X + 1][Y].getType() == Type::destroyableWall) {
                    return;
                }
            }
        heroes[heroNum].x++;
        if (heroes[heroNum].x >= amountOfEncounters_)
            heroes[heroNum].x--;
    }
    if (direction == Direction::left) {
        if (heroes[heroNum].x <= 0)
            return;
        if (board_[X - 1][Y].getType() != Type::emptyField) {
            if (board_[X - 1][Y].getType() == Type::obstacle || board_[X - 1][Y].getType() == Type::destroyableWall) {
                return;
            }
        }
        heroes[heroNum].x--;
        if (heroes[heroNum].x < 0)
            heroes[heroNum].x++;
    }
}
