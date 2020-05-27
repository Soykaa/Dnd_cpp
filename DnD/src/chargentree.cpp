#include <QtGui>
#include <QDesktopWidget>
#include <QDebug>
#include "include/chargentree.h"
#include "ui_chargentree.h"
#include "include/game_board.h"

extern GameBoard *game;


CharGenTree::CharGenTree(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CharGenTree) {
    ui->setupUi(this);

    chg = new CharGen2();

    setFixedSize(650, 560);

    QPixmap pic("../images/a.svg");
    CharGenTree::ui->bg->setScaledContents(true);
    CharGenTree::ui->bg->setPixmap(pic);

    QPixmap picqst("../images/gst_bg");
    CharGenTree::ui->qstbg->setScaledContents(true);
    CharGenTree::ui->qstbg->setPixmap(picqst);

    QPixmap q("../images/qst.png");
    CharGenTree::ui->qst->setScaledContents(true);
    CharGenTree::ui->qst->setPixmap(q);

    //CharGenTree::ui->next_step->hide();

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

CharGenTree::~CharGenTree() {
    delete ui;
}

void CharGenTree::on_next_step_clicked() {
    CharacterSkills cs;
    Backpack bp;
    game->boards[0].heroes[0].h = new Hero(cs, bp);
    game->boards[1].heroes[0].h = game->boards[0].heroes[0].h;
    chg->show();
    this->close();
}
