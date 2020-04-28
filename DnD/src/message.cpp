#include <QFont>
#include "include/message.h"
#include "include/game_board.h"


extern GameBoard *game;

Message::Message(QGraphicsItem *parent) : QGraphicsTextItem(parent) {}

void Message::setMessage(int playerNum, int locationNum) {
    if (playerNum == 1)
        setPlainText(QString("Победа игрока 1!!!"));
    else
        setPlainText(QString("Победа игрока 2!!!"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Lobster", 70));
    game->scenes[locationNum]->addItem(this);
}
