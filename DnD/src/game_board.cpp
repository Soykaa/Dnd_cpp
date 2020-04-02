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
	//cs = new CharacterSkills();
	//h = new Character(cs);
	b.changeOneFieldType(4, 4, Type::finnish);

	scene_ = new QGraphicsScene();
	scene_->setSceneRect(0, 0, size_, size_);
	setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
	setScene(scene_);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(size_, size_);

	player_ = new Player();
	player_->setPos(30, 0);
	player_->setFlag(QGraphicsItem::ItemIsFocusable);
	player_->setFocus();
	scene_->addItem(player_);

	dice_ = new Dice();
	//dice_->setPos(750, 250);
	//scene_->addItem(dice_);

	obstacle_ = new Obstacle();
	b.changeOneFieldType(2, 1, Type::obstacle);
	obstacle_->setPos(300, 150);
	scene_->addItem(obstacle_);

	gift_ = new Gift();
	b.changeOneFieldType(2, 2, Type::gift);
	gift_->setPos(300, 300);
	scene_->addItem(gift_);

	show();
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
	const int start_x = 30, start_y = 0, cell_width = 150, cells_in_row = 5;
	int obstacle_width = cell_width;
	//qDebug() << start_x;

	if (event->key() == Qt::Key_Left) {
			b.makeTurn(Direction::left);
	}
	if (event->key() == Qt::Key_Right) {
			b.makeTurn(Direction::right);
	}
	if (event->key() == Qt::Key_Up) {
			b.makeTurn(Direction::up);
	}
	if (event->key() == Qt::Key_Down) {
			b.makeTurn(Direction::down);
	}
	int x = b.getCharacterPosition_X();
	int y = b.getCharacterPosition_Y();
	player_->setPos(start_x + x * cell_width, start_y + y * cell_width);
	if (b.getFieldType(b.getCharacterPosition_X(), b.getCharacterPosition_Y()) == Type::gift) {
		b.takeGift(18);
		game->gift_->~Gift();
	}

	if (b.getFieldType(b.getCharacterPosition_X(), b.getCharacterPosition_Y()) == Type::finnish and b.canWin()) {
		Message *text = new Message();
		text->setPos(30, 300);
		game->scene_->addItem(text);
	}

	if (event->key() == Qt::Key_Any) {
		QApplication::quit();
	}
}