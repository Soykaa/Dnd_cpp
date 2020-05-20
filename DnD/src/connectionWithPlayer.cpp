#include "include/connectionWithPlayer.h"
#include "include/game_board.h"
#include <QTextEdit>
#include <cstring>

extern GameBoard *game;

Window::Window(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Window::setWindow(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->start_x - game->cell_width, game->window_height));
    setPos(0, 0);
    game->scenes[locationNum]->addItem(this);
}

Master::Master(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Master::setMaster(const QString str, int locationNum) {
    setPixmap(QPixmap(str));
    setPos(35, 0);
    game->scenes[locationNum]->addItem(this);
}

WindowForText::WindowForText(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void WindowForText::setWindowForText(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->start_x - game->cell_width, 350));
    setPos(0, 450);
    game->scenes[locationNum]->addItem(this);
}

WindowForText_D::WindowForText_D(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void WindowForText_D::setWindowForText_D(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->window_width, game->extract_height));
    setPos(0, game->window_height);
    game->scenes[locationNum]->addItem(this);
}

MessForPlayer::MessForPlayer(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
	    game->scenes[0]->addItem(this);
}

void MessForPlayer::setMessForPlayer(const QString str, int x, int y, int locationNum) {
	std::string s1 = "aa";
	std::string s2 = "bb";
	std::string s = s1 + s2;
    setHtml(str);
    //setHtml("<html><style>.ex {background: #fffff5;}</style><body><p class='ex' align='center' Ntrcn</body></html>");
    setPos(x, y);
}