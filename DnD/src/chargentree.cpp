#include <QtGui>
#include <QDesktopWidget>
#include <QDebug>
#include "include/chargentree.h"
#include "ui_chargentree.h"
#include "include/game_board.h"

extern GameBoard* game;

CharacterTreeNode* cur_node;

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
    connect(CharGenTree::ui->yes_button, SIGNAL(clicked()), this, SLOT(on_next_yes_button_clicked()));
    connect(CharGenTree::ui->no_button, SIGNAL(clicked()), this, SLOT(on_next_no_button_clicked()));
    t1.buildTree();
    cur_node = t1.getCharacterTreeRoot();
    CharGenTree::ui->qst_t->setText(cur_node->getQst().c_str());

    CharacterSkills cs;
    Backpack bp;
    h = new Hero(cs, bp);

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

void CharGenTree::on_next_yes_button_clicked() {
    chck_yes = true;
    if (cur_node->getLeftNode() == nullptr && cur_node->getRightNode() == nullptr) {
        chck_yes = false;
        return;
    }
    chck_no = false;
    cur_node = cur_node->getLeftNode();
    CharGenTree::ui->qst_t->setText(cur_node->getQst().c_str());
}

void CharGenTree::on_next_no_button_clicked() {
    chck_yes = true;
    if (cur_node->getLeftNode() == nullptr && cur_node->getRightNode() == nullptr) {
            chck_no = false;
            return;
    } else {
        chck_no = false;
        cur_node = cur_node->getRightNode();
        CharGenTree::ui->qst_t->setText(cur_node->getQst().c_str());
    }
}

void CharGenTree::on_next_step_clicked() {
    CharacterSkills cs;
    Backpack bp;
    game->boards[0].heroes[0].h = new Hero(cs, bp);
    CharacterTree::generateChar(game->boards[0].heroes[0].h, cur_node);
    game->boards[1].heroes[0].h = game->boards[0].heroes[0].h;
    int num;
    if (game->boards[0].heroes[0].h->getRace() == CharRace::dragonborn) {
        num = rand() % 3;
    }
    if (game->boards[0].heroes[0].h->getRace() == CharRace::human) {
        num = (rand() % 4) + 3;
    }
    if (game->boards[0].heroes[0].h->getRace() == CharRace::elf) {
        num = (rand() % 3) + 7;
    }
    game->charIm.char1 = num;
    chg->show();
    this->close();
}


