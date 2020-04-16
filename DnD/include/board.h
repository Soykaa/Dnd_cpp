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
    static const int amountOfEncounters_ = 20;
    std::array<std::array<Encounter, amountOfEncounters_>, amountOfEncounters_> board_;
    int characterPosition_X_1 = 0;
    int characterPosition_Y_1 = 0;
    int characterPosition_X_2 = 0;
    int characterPosition_Y_2 = 0;
    CharacterSkills cs;
    Character *h1;
    Character *h2;

public:
    Board();
    Encounter getField(size_t i, size_t j);
    Type getFieldType(size_t i, size_t j);
    size_t getAmountOfEncounters();
    int getCharacterPosition_X_1();
    int getCharacterPosition_Y_1();
    int getCharacterPosition_X_2();
    int getCharacterPosition_Y_2();
    bool canWin_1();
    bool canWin_2();
    void makeTurn_1(Direction direction);
    void makeTurn_2(Direction direction);
    void takeGift_1(size_t deltaDexterity);
    void takeGift_2(size_t deltaDexterity);
    void changeOneFieldType(size_t i, size_t j, Type type);
    ~Board() {}
};

#endif
