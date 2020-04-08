#include <QDebug>
#include <QApplication>
#include "include/game_board.h"
#include "include/player.h"
#include "include/obstacle.h"
#include "include/dice.h"
#include "include/character.h"
#include "include/character_skills.h"

extern GameBoard *game;

GameBoard::GameBoard(QWidget *parent) {
	b.changeOneFieldType(b.getAmountOfEncounters() - 1, b.getAmountOfEncounters() - 1, Type::finnish);

	scene_ = new QGraphicsScene();
	scene_->setSceneRect(0, 0, window_width, window_height);
	setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
	setScene(scene_);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(window_width, window_height);

	player_ = new Player();
	player2_ = new Player2();
}


void GameBoard::makeGift(int giftNum, int x, int y) {
	gifts_[giftNum].gift = new Gift();
	gifts_[giftNum].gift->setGift(x, y);
	gifts_[giftNum].x = x;
	gifts_[giftNum].y = y;
	b.changeOneFieldType(x, y, Type::gift);
}

void GameBoard::makeGame() {
	player_->setPlayer();
	player_->setPos(0, 0);
	player_->setFlag(QGraphicsItem::ItemIsFocusable);
	player_->setFocus();
	scene_->addItem(player_);
	player2_->setPlayer2();
	player2_->setPos(0, 0);
	player2_->setFlag(QGraphicsItem::ItemIsFocusable);
	player2_->setFocus();
	scene_->addItem(player2_);
	makeGifts(10);
	makeObstacles(100);
	show();
}


void GameBoard::makeGifts(int amount) {
	gifts_.resize(amount);
	for (int i = 0; i < amount; i++) {
		int x = rand() % b.getAmountOfEncounters();
		int y = rand() % b.getAmountOfEncounters();
		if (b.getFieldType(x, y) == Type::emptyField)
			makeGift(i, x, y);	
	}
}

void GameBoard::makeObstacle(int obstNum, int x, int y) {
	obstacles_[obstNum].obst = new Obstacle();
	obstacles_[obstNum].obst->setObstacle(x, y);
	obstacles_[obstNum].x = x;
	obstacles_[obstNum].y = y;
	b.changeOneFieldType(x, y, Type::obstacle);
}

void GameBoard::makeObstacles(int amount) {
	obstacles_.resize(amount);
	for (int i = 0; i < amount; i++) {
		int x = rand() % b.getAmountOfEncounters();
		int y = rand() % b.getAmountOfEncounters();
		if (b.getFieldType(x, y) == Type::emptyField)
			makeObstacle(0, x, y);	
	}
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Any) {
		QApplication::quit();
	}
	if (gameIsFinished)
		return;

	if (event->key() == Qt::Key_Left) {
			b.makeTurn_1(Direction::left);
	}
	if (event->key() == Qt::Key_Right) {
			b.makeTurn_1(Direction::right);
	}
	if (event->key() == Qt::Key_Up) {
			b.makeTurn_1(Direction::up);
	}
	if (event->key() == Qt::Key_Down) {
			b.makeTurn_1(Direction::down);
	}


	if (event->key() == Qt::Key_A) {
			b.makeTurn_2(Direction::left);
	}
	if (event->key() == Qt::Key_D) {
			b.makeTurn_2(Direction::right);
	}
	if (event->key() == Qt::Key_W) {
			b.makeTurn_2(Direction::up);
	}
	if (event->key() == Qt::Key_S) {
			b.makeTurn_2(Direction::down);
	}
	int x_1 = b.getCharacterPosition_X_1();
	int y_1 = b.getCharacterPosition_Y_1();
	player_->setPos(start_x + x_1 * cell_width, start_y + y_1 * cell_width);

	int x_2 = b.getCharacterPosition_X_2();
	int y_2 = b.getCharacterPosition_Y_2();
	player2_->setPos(start_x + x_2 * cell_width, start_y + y_2 * cell_width);

	if (b.getFieldType(b.getCharacterPosition_X_1(), b.getCharacterPosition_Y_1()) == Type::gift) {
		b.takeGift_1(18);
		for (GiftCord g: gifts_) {
			if (g.x == b.getCharacterPosition_X_1() && g.y == b.getCharacterPosition_Y_1())
				g.gift->~Gift();
		}
	}

	if (b.getFieldType(b.getCharacterPosition_X_2(), b.getCharacterPosition_Y_2()) == Type::gift) {
		b.takeGift_2(18);
		for (GiftCord g: gifts_) {
			if (g.x == b.getCharacterPosition_X_2() && g.y == b.getCharacterPosition_Y_2())
				g.gift->~Gift();
		}
	}

	if (b.getFieldType(b.getCharacterPosition_X_1(), b.getCharacterPosition_Y_1()) == Type::finnish and b.canWin_1()) {
		gameIsFinished = true;
		Message *text = new Message();
		text->setMessage(1);
		text->setPos(30, 300);
		player_->~Player();
		player2_->~Player2();
		// game->scene_->addItem(text);
	}
	else if(b.getFieldType(b.getCharacterPosition_X_2(), b.getCharacterPosition_Y_2()) == Type::finnish and b.canWin_2()) {
		gameIsFinished = true;
		Message *text = new Message();
		text->setMessage(2);
		text->setPos(30, 300);
		player_->~Player();
		player2_->~Player2();
	}

}