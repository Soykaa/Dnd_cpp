#ifndef DND_ENEMY_H
#define DND_ENEMY_H

#include <QGraphicsPixmapItem>


class EnemyIm : public QGraphicsPixmapItem {
public:
    explicit EnemyIm(QGraphicsItem *parent = 0);
    void setEnemyIm(QString str, int x, int y, int locationNum);
};

#endif //DND_ENEMY_H
