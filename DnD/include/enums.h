#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

enum class Type {
    emptyField,
    obstacle,
    door,
    item,
    start,
    finnish,
    well,
    destroyableWall,
    enemy,
    // TODO
};

enum class ItemType {
    none,
    rope,
    gift,    //must-have to win the game
    triangle_key,
    square_key
};

enum class CharRace {
    dragonborn,
    elf,
    human
};

enum class CharClass {
    fighter,
    druid,
    wizard,
    enemy //special one!
};

enum class SuperPowers {
    athletics,
    acrobatics,
    persuasion
};

#endif
