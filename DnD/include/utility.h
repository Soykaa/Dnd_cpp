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

enum class Type {
    emptyField,
    obstacle,
    door,
    start,
    finnish,
    gift,
    destroyableWall,
    key
    // TODO
};

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

#endif
