//
// Created by Milyausha on 30/03/2020.
//

#ifndef DND_MESSAGE_H
#define DND_MESSAGE_H

#include <QGraphicsTextItem>

class Message : public QGraphicsTextItem {
public:
    explicit Message(QGraphicsItem *parent = 0);
    void setMessage(int locationNum);
};


#endif //DND_MESSAGE_H
