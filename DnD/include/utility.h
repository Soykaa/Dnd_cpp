#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <vector>
#include <string>
#include "gift.h"
#include "obstacle.h"
#include "character.h"
#include "key.h"
#include "connectionWithPlayer.h"
#include "BackpackIm.h"
#include "well.h"
#include "door.h"

enum class Direction {
    up,
    down,
    left,
    right,
};

struct HeroCord {
    Hero* h = nullptr;
    int x = 0;
    int y = 0;
};

struct GiftCord {
    Gift* gift;
    int x;
    int y;
};

struct ObstacleCord {
    Obstacle* obst;
    int x;
    int y;
};

struct KeyCord {
    Key* key;
    int x;
    int y;
};

struct ConnectionWindow {
    Window* window;
    Master* master;
    WindowForText* wft_l;
    WindowForText_D* wft_b;
    MessForPlayer* mess;
    MessForPlayer* hint;
    MessForPlayer* hint2;
    MessForPlayer* hint3;
    MessForPlayer* hint4;
    MessForPlayer* hint5;
    ItemBack* char1;
    ItemBack* char2;
};

struct BackpackIm {
    BackgroundIm* bi1;
    BackgroundIm* bi2;
    std::vector<ItemBack*> itb;
};

struct destroyableWall {
    std::string dir;
    int x;
    int y;
};

struct CharIm{
    int char1;
    int char2;
    std::vector<QString> chars;
};

struct RopeCord {
    WellItem* rope;
    int x;
    int y;
};

struct Well {
    WellItem* well;
    std::vector<RopeCord> ropes;
};

struct Doors {
    Door* door0;
    int x0, y0;
    Door* door1;
    int x1, y1;
};

#endif
