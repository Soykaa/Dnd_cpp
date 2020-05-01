#include <QFont>
#include "include/message.h"
#include "include/game_board.h"


extern GameBoard *game;

Message::Message(QGraphicsItem *parent) : QGraphicsTextItem(parent) {}

void Message::setMessage(int locationNum) {
    setPlainText(QString("Победа!!!"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Lobster", 70));
    game->scenes[locationNum]->addItem(this);
}
