#include <QGraphicsPixmapItem>
#include "include/obstacle.h"
#include "include/game_board.h"

extern GameBoard *game;

Obstacle::Obstacle(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Obstacle::setObstacle(const QString& str, int x, int y, int locationNum) {
    int k = game->cell_width;
    setPixmap(QPixmap(str).scaled(k, k));
    setPos(x * game->cell_width + game->start_x, y * game->cell_width + game->start_y);
    game->scenes[locationNum]->addItem(this);
}

void Obstacle::setForFrame(const QString& str, int x, int y, int locationNum) {
    int k = game->cell_width;
    setPixmap(QPixmap(str).scaled(k, k));
    setPos(x, y);
    game->scenes[locationNum]->addItem(this);
}
