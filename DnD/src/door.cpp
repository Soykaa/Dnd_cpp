#include <include/door.h>
#include <include/game_board.h>

extern GameBoard *game;

Door::Door(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), player1(false), player2(false) {}

void Door::setDoor() {
    int size = game->cell_width;
    setPixmap(QPixmap("images/door.png").scaled(size, size));
};
