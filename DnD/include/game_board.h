#ifndef DND_GAME_BOARD_H
#define DND_GAME_BOARD_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "player.h"
#include "dice.h"
#include "obstacle.h"
#include "gift.h"
#include "board.h"
#include "message.h"
#include "character.h"
#include "character_skills.h"

class GameBoard : public QGraphicsView {
	//Q_OBJECT
public:
	GameBoard(QWidget *parent = 0);
	QGraphicsScene *scene_;
	Player *player_;
	Dice *dice_;
	Obstacle *obstacle_;
	Gift *gift_;
	Encounter e;
	Board b;
	void keyPressEvent(QKeyEvent *event);
	const int size_ = 750;
};

#endif //DND_GAME_BOARD_H