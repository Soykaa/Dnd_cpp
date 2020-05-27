#include "include/well.h"
#include "include/game_board.h"

extern GameBoard *game;

WellItem::WellItem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void WellItem::setWellItem(int x, int y, int locationNum, bool isRope) {
    if (isRope) {
        setPixmap(QPixmap("../images/rope.png").scaled(game->cell_width, game->cell_width));
        setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
        game->scenes[locationNum]->addItem(this);
    } else {
        setPixmap(QPixmap("../images/well3.png").scaled(3*game->cell_width, 3 *game->cell_width));
        setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
        game->scenes[locationNum]->addItem(this);
    }
}
