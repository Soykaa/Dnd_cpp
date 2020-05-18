#include "include/connectionWithPlayer.h"
#include "include/game_board.h"

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
