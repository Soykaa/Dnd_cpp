#include <QtGui>
#include <QDesktopWidget>

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

    QPixmap pic("../images/char_bg.png");
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
    CharGen2::ui->randomMode->setText("Герерирую...");
    sleep(100);
    CharGen2::ui->randomMode->setText("Сгенерировано");
    CharGen2::ui->randomMode->setEnabled(false);
    CharGen2::ui->nextStep->show();
}

void CharGen2::on_nextStep_clicked() {
    hide();
    game->makeGame();
}

void CharGen2::on_standardMode_clicked() {
    chgt2->show();
    this->close();
}
