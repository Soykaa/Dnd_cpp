#include <QCoreApplication>
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include "include/board.h"
#include "include/game_menu.h"
#include "ui_game_menu.h"
#include "include/chargen.h"

extern GameBoard *game;

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWindow) {
    ui->setupUi(this);
    QPixmap pix("../images/dungeon.webp");
    ui->label->setPixmap(pix.scaled(750, 750));
    chg = new CharGen();
    game = new GameBoard();
}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::on_pushButton_clicked() {
    chg->show();
    this->close();
}

void GameWindow::on_pushButton_3_clicked() {
    QApplication::quit();
}
