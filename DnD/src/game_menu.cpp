#include <QCoreApplication>
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include "include/board.h"
#include "include/game_menu.h"
#include "ui_game_menu.h"

extern GameBoard *game;

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    QPixmap pix("../images/dungeon.webp");
    ui->label->setPixmap(pix.scaled(750, 750));

}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::on_pushButton_clicked() {
    hide();
    game = new GameBoard();
    game->makeGame();
}

void GameWindow::on_pushButton_3_clicked() {
    QApplication::quit();
}
