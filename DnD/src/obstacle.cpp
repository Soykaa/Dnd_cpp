#include "include/obstacle.h"
#include <QGraphicsPixmapItem>

Obstacle::Obstacle(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("images/obstacle.png"));
}