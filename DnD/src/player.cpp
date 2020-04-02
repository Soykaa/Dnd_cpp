#include "include/player.h"
#include <QDebug>
#include <QKeyEvent>
#include "include/game_board.h"
#include "include/message.h"

extern GameBoard *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("../images/player.png"));
}