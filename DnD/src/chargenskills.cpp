#include <QtGui>
#include <QDesktopWidget>

#include "include/chargenskills.h"
#include "ui_chargenskills.h"
#include "include/game_board.h"

extern GameBoard *game;

CharGenSkills::CharGenSkills(QWidget *parent) :
    QWidget(parent), ui(new Ui::CharGenSkills) {
    ui->setupUi(this);

    setFixedSize(650, 560);
    //int num = game->charIm.char2;

    QPixmap pic("../images/a.svg");
    CharGenSkills::ui->bg->setScaledContents(true);
    CharGenSkills::ui->bg->setPixmap(pic.scaled(650, 560));

    QPixmap pic1("../images/text.png");
    CharGenSkills::ui->bg_text1->setScaledContents(true);
    CharGenSkills::ui->bg_text1->setPixmap(pic1.scaled(650, 560));

    CharGenSkills::ui->bg_text11->setScaledContents(true);
    CharGenSkills::ui->bg_text11->setPixmap(pic1.scaled(650, 560));

    CharGenSkills::ui->bg_text2->setScaledContents(true);
    CharGenSkills::ui->bg_text2->setPixmap(pic1.scaled(650, 560));

    CharGenSkills::ui->bg_text21->setScaledContents(true);
    CharGenSkills::ui->bg_text21->setPixmap(pic1.scaled(650, 560));

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

void CharGenSkills::setImages(QString str1, QString str2) {
    QPixmap hero1(str1);
    CharGenSkills::ui->img1->setScaledContents(true);
    CharGenSkills::ui->img1->setPixmap(hero1.scaled(120, 180));

    QPixmap hero2(str2);
    CharGenSkills::ui->img2->setScaledContents(true);
    CharGenSkills::ui->img2->setPixmap(hero2.scaled(120, 180));
}

CharGenSkills::~CharGenSkills() {
    delete ui;
}

void CharGenSkills::on_nextStep_clicked() {
    hide();
    game->makeGame();
}
