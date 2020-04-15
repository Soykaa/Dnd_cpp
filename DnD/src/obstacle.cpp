#include <QGraphicsPixmapItem>
#include "include/obstacle.h"
#include "include/game_board.h"


extern GameBoard *game;

Obstacle::Obstacle(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Obstacle::setObstacle(int x, int y) {
	int k = game->cell_width;
 	setPixmap(QPixmap("../images/obstacle.png").scaled(k, k));
 	setPos(x * game->cell_width, y * game->cell_width);
	game->scene_->addItem(this);
}