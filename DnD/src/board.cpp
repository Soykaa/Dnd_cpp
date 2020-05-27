#include "include/board.h"
#include <QDebug>
#include <algorithm>
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

ItemType Board::getFieldItemType(size_t i, size_t j) {
    return board_[i][j].getItem();
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
    int a = std::min(heroes[0].h->cs_.getStrength(), heroes[1].h->cs_.getStrength()) + 1;
    int b = std::max(heroes[0].h->cs_.getStrength(), heroes[1].h->cs_.getStrength());
    return heroes[heroNum].h->cs_.getStrength() >= a + rand()%(b-a) || canUseNotUniqueItems(heroNum, ItemType::gift);
}

void Board::destroyWall(int x, int y) {
    board_[x][y].changeType(Type::emptyField);
    return;
}


void Board::takeGift(size_t deltaDexterity, int heroNum) {
    board_[heroes[heroNum].x][heroes[heroNum].y].changeType(Type::emptyField);
    heroes[heroNum].h->cs_.setDexterity(heroes[heroNum].h->cs_.getDexterity() + deltaDexterity);
}

bool Board::canUseNotUniqueItems(int heroNum, ItemType item) {
    return heroes[heroNum].h->bp_.countItems(item) >= 3;
}

void Board::changeOneFieldType(size_t i, size_t j, Type type, ItemType item) {
    board_[i][j].changeType(type, item);
}

destroyableWall Board::check(int heroNum) {
    int X = heroes[heroNum].x;
    int Y = heroes[heroNum].y;
    std::vector<destroyableWall> cords;
    cords.push_back({"right", X + 1, Y});
    cords.push_back({"left", X - 1, Y});
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

std::pair<bool, int> Board::takeItems(int x, int y, int heroNum) {
    ItemType item = board_[x][y].getItem();
    int num = heroes[heroNum].h->bp_.countItems(item);
    if (num == 3)
        return {0, 3};
    heroes[heroNum].h->bp_.addItem(Item(item));
    board_[x][y].changeType(Type::emptyField);
    return {1, num + 1};
}

bool Board::takeUniqItem(int x, int y, int heroNum) {
    ItemType item = board_[x][y].getItem();
    if (heroes[heroNum].h->bp_.findItem(item))
        return 0;
    heroes[heroNum].h->bp_.addItem(Item(item));
    board_[x][y].changeType(Type::emptyField);
    return 1;
}

bool Board::canOpenDoor(int heroNum) {
    return 1;
    // return heroes[heroNum].h->bp_.findItem(ItemType::triangle_key) ||
    //         heroes[heroNum].h->bp_.findItem(ItemType::square_key);
}


void Board::makeTurn(Direction direction, int heroNum) {
    int X = heroes[heroNum].x;
    int Y = heroes[heroNum].y;
    if (direction == Direction::down) {
            if (board_[X][Y + 1].getType() != Type::emptyField) {
                Type t = board_[X][Y + 1].getType();
                bool canNotGo = (t != Type::item) && (t != Type::start) && (t != Type::finnish) && (t != Type::door);
                if (canNotGo) {
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
            Type t = board_[X][Y - 1].getType();
            bool canNotGo = (t != Type::item) && (t != Type::start) && (t != Type::finnish) && (t != Type::door);
            if (canNotGo) {
                return;
            }
        }
        heroes[heroNum].y--;
        if (heroes[heroNum].y < 0)
            heroes[heroNum].y++;
    }
    if (direction == Direction::right) {
        if (board_[X + 1][Y].getType() != Type::emptyField) {
            Type t = board_[X + 1][Y].getType();
            bool canNotGo = (t != Type::item) && (t != Type::start) && (t != Type::finnish) && (t != Type::door);
            if (canNotGo) {
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
            Type t = board_[X - 1][Y].getType();
            bool canNotGo = (t != Type::item) && (t != Type::start) && (t != Type::finnish) && (t != Type::door);
            if (canNotGo) {
                return;
            }
        }
        heroes[heroNum].x--;
        if (heroes[heroNum].x < 0)
            heroes[heroNum].x++;
    }
}
