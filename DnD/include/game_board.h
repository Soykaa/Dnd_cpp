#ifndef DND_GAME_BOARD_H
#define DND_GAME_BOARD_H

#include <QGraphicsView>
#include <QKeyEvent>
#include "utility.h"
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
	Player2* player2_;
	std::vector<Dice*> dices_;
	std::vector<GiftCord> gifts_;
	std::vector<ObstacleCord> obstacles_;
	void makeGifts(int amount);
	void makeObstacles(int amount);
	void makeGift(int giftNum, int x, int y);
	void makeObstacle(int obstNum, int x, int y);
	void makeGame();
	Board b;
	void keyPressEvent(QKeyEvent *event);
	bool gameIsFinished = false;
	int start_x = 0;
	int start_y = 0;
	const int board_size = 1000;
	const int window_width = 1000;
	const int window_height = 1000;
	const int cell_width = board_size / b.getAmountOfEncounters();
};

#endif //DND_GAME_BOARD_H