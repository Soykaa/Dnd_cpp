#include "include/BackpackIm.h"
#include "include/game_board.h"

extern GameBoard *game;

BackgroundIm::BackgroundIm(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void BackgroundIm::setBackgroundIm(const QString str, int x, int y, int locationNum) {
    setPixmap(QPixmap(str).scaled(3*game->cell_width + 30, (game->window_height - 50)/ 2));
    setPos(x, y);
    game->scenes[locationNum]->addItem(this);
}

ItemBack::ItemBack(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void ItemBack::setItemBack(const QString str, int x, int y, int locationNum, bool gift) {
    if (!gift)
        setPixmap(QPixmap(str).scaled(3* game->cell_width -10, 100));
    else
        setPixmap(QPixmap(str).scaled(50, 50));
    setPos(x, y);
    game->scenes[locationNum]->addItem(this);
}
