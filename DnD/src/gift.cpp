#include "include/gift.h"
//#include "include/key.h"
#include "include/game_board.h"

extern GameBoard *game;

Gift::Gift(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    is_taken = false;
}

void Gift::setGift(int x, int y, int locationNum) {
    int k = game->cell_width;
    setPixmap(QPixmap("../images/gift.png").scaled(k, k));
    setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
    game->scenes[locationNum]->addItem(this);
}
