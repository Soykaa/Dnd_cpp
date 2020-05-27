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
    static const int amountOfEncounters_ = 15;
    std::array<std::array<Encounter, amountOfEncounters_>, amountOfEncounters_> board_;

public:
    std::vector<HeroCord> heroes;
    Board();
    Encounter getField(size_t i, size_t j);
    Type getFieldType(size_t i, size_t j);
    ItemType getFieldItemType(size_t i, size_t j);
    size_t getAmountOfEncounters();
    int getCharacterPosition_X(int heroNum);
    int getCharacterPosition_Y(int heroNum);
    bool takeUniqItem(int x, int y, int heroNum);
    int beatEnemy(int heroNum, Enemy* en);
    void reduce(int heroNum);
    void increase(int heroNum);
    std::pair<bool, int> takeItems(int x, int y, int heroNum);
    bool canUseOneItem(int heroNum, ItemType item);
    bool canUseNotUniqueItems(int heroNum, ItemType item = ItemType::gift);
    bool canWin(int heroNum);
    bool canDestroyWall(int heroNum);
    void destroy(int x, int y);
    destroyableObject check(int heroNum, Type type = Type::destroyableWall);
    void makeTurn(Direction direction, int heroNum);
    void takeGift(size_t deltaDexterity, int heroNum);
    void changeOneFieldType(size_t i, size_t j, Type type, ItemType item = ItemType::none);
    ~Board() {}
};

#endif
