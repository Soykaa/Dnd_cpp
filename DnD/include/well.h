#ifndef DND_WELL_H
#define DND_WELL_H

#include <QGraphicsPixmapItem>


class WellItem : public QGraphicsPixmapItem {
public:
    explicit WellItem(QGraphicsItem *parent = 0);
    void setWellItem(int x, int y, int locationNum, bool isRope);
};

#endif //DND_WELL_H
