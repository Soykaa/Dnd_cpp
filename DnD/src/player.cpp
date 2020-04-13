#include "include/player.h"
#include <QDebug>
#include <QKeyEvent>
#include "include/game_board.h"
#include "include/message.h"

extern GameBoard *game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Player::setPlayer() {
	int size = game->cell_width;
 	setPixmap(QPixmap("images/dragonborn.png").scaled(size, size));
}

Player2::Player2(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Player2::setPlayer2() {
	int size = game->cell_width;
 	setPixmap(QPixmap("images/character.png").scaled(size, size));
}