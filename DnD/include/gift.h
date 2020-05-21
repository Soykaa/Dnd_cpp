#ifndef DND_GIFT_H
#define DND_GIFT_H

#include <QGraphicsPixmapItem>


class Gift : public QGraphicsPixmapItem {
public:
    explicit Gift(QGraphicsItem *parent = 0);
    void setGift(int x, int y, int locationNum);
};

#endif //DND_GIFT_H
