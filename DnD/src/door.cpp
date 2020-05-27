#include <include/door.h>
#include <include/game_board.h>

extern GameBoard *game;

Door::Door(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), player1(false), player2(false) {}

void Door::setDoor(int x, int y, int locationNum, bool exit) {
    int size = game->cell_width;
    if (exit)
        setPixmap(QPixmap("../images/exit.jpg").scaled(size, size));
    else
        setPixmap(QPixmap("../images/door.jpg").scaled(size, size));
    setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
    game->scenes[locationNum]->addItem(this);
}
