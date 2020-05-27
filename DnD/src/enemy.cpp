#include "include/enemy.h"
#include "include/game_board.h"

extern GameBoard *game;

EnemyIm::EnemyIm(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void EnemyIm::setEnemyIm(QString str, int x, int y, int locationNum) {
    int k = game->cell_width;
    setPixmap(QPixmap(str).scaled(k, k));
    setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
    game->scenes[locationNum]->addItem(this);
}