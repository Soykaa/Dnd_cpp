#ifndef DND_PLAYER_H
#define DND_PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = 0);
    void setPlayer(const QString str);
};

class Player2 : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Player2(QGraphicsItem *parent = 0);
    void setPlayer2();
};

#endif //DND_PLAYER_H
