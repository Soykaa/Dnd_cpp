#include "include/key.h"
#include "include/game_board.h"

extern GameBoard *game;

Key::Key(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    is_taken = false;
}

void Key::setKey(const QString str, int x, int y, int locationNum) {
    int k = game->cell_width;
    setPixmap(QPixmap(str).scaled(k, k));
    setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
    game->scenes[locationNum]->addItem(this);
}
