#ifndef DND_BACKPACK_IM_H
#define DND_BACKPACK_IM_H

#include <QGraphicsPixmapItem>


class BackgroundIm : public QGraphicsPixmapItem {
public:
    explicit BackgroundIm(QGraphicsItem *parent = nullptr);
    void setBackgroundIm(const QString&, int x, int y, int locationNum);
};

class ItemBack : public QGraphicsPixmapItem {
public:
    explicit ItemBack(QGraphicsItem *parent = nullptr);
    void setItemBack(const QString&, int x, int y, int locationNum, bool gift);
};

#endif //DND_BACKPACK_IM_H
