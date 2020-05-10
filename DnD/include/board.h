#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <array>
#include <vector>
#include <utility>
#include "utility.h"
#include "encounter.h"
#include "character.h"
#include "character_skills.h"

class Board {
private:
    static const int amountOfEncounters_ = 10;
    std::array<std::array<Encounter, amountOfEncounters_>, amountOfEncounters_> board_;

public:
    std::vector<HeroCord> heroes;
    Board();
    Encounter getField(size_t i, size_t j);
    Type getFieldType(size_t i, size_t j);
    size_t getAmountOfEncounters();
    int getCharacterPosition_X(int heroNum);
    int getCharacterPosition_Y(int heroNum);
    void takeItem(int x, int y, int heroNum);
    bool canOpenDoor(int heroNum);
    bool canWin(int heroNum);
    bool canDestroyWall(int heroNum);
    void destroyWall(int x, int y);
    std::pair<int, int> check(int heroNum);
    void makeTurn(Direction direction, int heroNum);
    void takeGift(size_t deltaDexterity, int heroNum);
    void changeOneFieldType(size_t i, size_t j, Type type);
    ~Board() {}
};

#endif
