#ifndef DND_OBSTACLE_H
#define DND_OBSTACLE_H

#include <QGraphicsPixmapItem>

class Obstacle : public QGraphicsPixmapItem {
public:
    Obstacle(QGraphicsItem *parent = 0);
    void setObstacle(int x, int y);
};

#endif //DND_OBSTACLE_H
