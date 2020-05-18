#ifndef DND_CONNECTION_WITH_PLAYER_H
#define DND_CONNECTION_WITH_PLAYER_H

#include <QGraphicsPixmapItem>

class Window : public QGraphicsPixmapItem {
public:
    explicit Window(QGraphicsItem *parent = 0);
    void setWindow(const QString str, int locationNum);
};

class Master : public QGraphicsPixmapItem {
public:
    explicit Master(QGraphicsItem *parent = 0);
    void setMaster(const QString str, int locationNum);
};

class WindowForText : public QGraphicsPixmapItem {
public:
    explicit WindowForText(QGraphicsItem *parent = 0);
    void setWindowForText(const QString str, int locationNum);
};


#endif //DND_KEY_H
