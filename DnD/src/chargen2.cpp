#include <QtGui>
#include <QDesktopWidget>

#include <cstdlib>
#include "include/chargen.h"
#include "ui_chargen2.h"
#include "include/sleep.h"
#include "include/game_board.h"

extern GameBoard *game;

CharGen2::CharGen2(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::CharGen2) {
    ui->setupUi(this);

    setFixedSize(400, 460);
    chgt2 = new CharGenTree2();
    chgs = new CharGenSkills();

    QPixmap pic("../images/a.svg");
    CharGen2::ui->bg->setScaledContents(true);
    CharGen2::ui->bg->setPixmap(pic);

    CharGen2::ui->nextStep->hide();

    //moving window to the center
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(this);
    QPoint center = rect.center();

    int coord_x = center.x() - (width()/2);
    int coord_y = center.y() - (height()/2);

    center.setX(coord_x);
    center.setY(coord_y);
    move(center);
}

CharGen2::~CharGen2() {
    delete ui;
}

void CharGen2::on_randomMode_clicked() {
    CharacterSkills cs;
    Backpack bp;
    game->boards[0].heroes[1].h = new Hero(cs, bp);
    game->boards[1].heroes[1].h = game->boards[0].heroes[1].h;
    CharGen2::ui->standardMode->setEnabled(false);
    CharGen2::ui->randomMode->setText("Генерирую...");
    int num = game->charIm.char1;
    srand(time(nullptr));
    if (game->boards[0].heroes[1].h->getRace() == CharRace::dragonborn) {
        while (num == game->charIm.char1) {
            num = rand() % 3;
        }
    }
    if (game->boards[0].heroes[1].h->getRace() == CharRace::human) {
        while (num == game->charIm.char1) {
            num = (rand() % 4) + 3;
        }
    }
    if (game->boards[0].heroes[1].h->getRace() == CharRace::elf) {
        while (num == game->charIm.char1) {
            num = (rand() % 3) + 7;
        }
    }
    for (int i = 0; i < 10; i++) {
        QString str = game->charIm.chars[i];
        CharGen2::ui->chpic->setPixmap(QPixmap(str).scaled(200, 200));
        sleep(100);
    }
    game->charIm.char2 = num;
    CharGen2::ui->chpic->setPixmap(QPixmap(game->charIm.chars[game->charIm.char2]).scaled(200, 200));
    CharGen2::ui->randomMode->setText("Сгенерировано");
    CharGen2::ui->randomMode->setEnabled(false);
    CharGen2::ui->nextStep->show();
}

void CharGen2::on_nextStep_clicked() {
    hide();
    chgs->setParams(game->charIm.chars[game->charIm.char1], game->charIm.chars[game->charIm.char2], game->boards[0].heroes[0].h, game->boards[0].heroes[1].h);
    chgs->show();
}

void CharGen2::on_standardMode_clicked() {
    chgt2->show();
    this->close();
}
