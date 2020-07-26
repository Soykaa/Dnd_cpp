#include "include/player.h"
#include <QDebug>
#include <QKeyEvent>
#include "include/game_board.h"
#include "include/message.h"

extern GameBoard *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Player::setPlayer(const QString& str) {
    int size = game->cell_width;
    setPixmap(QPixmap(str).scaled(size, size));
}
