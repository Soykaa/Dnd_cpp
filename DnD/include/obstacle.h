#ifndef DND_OBSTACLE_H
#define DND_OBSTACLE_H

#include <QGraphicsPixmapItem>

class Obstacle : public QGraphicsPixmapItem {
public:
    explicit Obstacle(QGraphicsItem *parent = 0);
    void setObstacle(const QString str, int x, int y, int locationNum);
    void setForFrame(const QString str, int x, int y, int locationNum);
};

#endif //DND_OBSTACLE_H
