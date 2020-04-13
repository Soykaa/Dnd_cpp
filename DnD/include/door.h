#ifndef DND_DOOR_H
#define DND_DOOR_H

#include <QGraphicsPixmapItem>

class Door : public QGraphicsPixmapItem {
public:
    Door(QGraphicsItem *parent = 0);
    void setDoor();
    bool player1, player2;
};

#endif //DND_DOOR_H
