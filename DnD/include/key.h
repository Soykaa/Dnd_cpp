#ifndef DND_KEY_H
#define DND_KEY_H

#include <QGraphicsPixmapItem>


class Key : public QGraphicsPixmapItem {
public:
    explicit Key(QGraphicsItem *parent = 0);
    bool is_taken;
    void setKey(const QString str, int x, int y, int locationNum);
};

#endif //DND_KEY_H'
