#include <QtGui>
#include <QDesktopWidget>

#include <cstdlib>
#include "include/chargen.h"
#include "ui_chargen.h"
#include "include/sleep.h"
#include "include/game_board.h"

extern GameBoard *game;

CharGen::CharGen(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::CharGen) {
    ui->setupUi(this);

    chg = new CharGen2();
    chgt = new CharGenTree();

    setFixedSize(400, 460);

    QPixmap pic("../images/a.svg");
    CharGen::ui->bg->setScaledContents(true);
    CharGen::ui->bg->setPixmap(pic.scaled(400, 460));

    CharGen::ui->nextStep->hide();

    //moving window to the center
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(this);
    QPoint center = rect.center();

    center.setX(center.x() - width() / 2);
    center.setY(center.y() - height() / 2);
    move(center);
}

CharGen::~CharGen() {
    delete ui;
}

void CharGen::on_randomMode_clicked() {
    CharacterSkills cs;
    Backpack bp;
    game->boards[0].heroes[0].h = new Hero(cs, bp);
    game->boards[1].heroes[0].h = game->boards[0].heroes[0].h;
    CharGen::ui->standardMode->setEnabled(false);
    CharGen::ui->randomMode->setText("Генерирую...");
    CharGen::ui->chpic->setScaledContents(true);
    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        QString str = game->charIm.chars[i];
        CharGen::ui->chpic->setPixmap(QPixmap(str).scaled(200, 200));
        sleep(100);
    }
    game->charIm.char1 = rand() % 10;
    CharGen::ui->chpic->setPixmap(QPixmap(game->charIm.chars[game->charIm.char1]).scaled(200, 200));
    CharGen::ui->randomMode->setText("Сгенерировано");
    CharGen::ui->randomMode->setEnabled(false);
    CharGen::ui->nextStep->show();
}

void CharGen::on_nextStep_clicked() {
    hide();
    chg->show();
}

void CharGen::on_standardMode_clicked() {
    hide();
    chgt->show();
}
