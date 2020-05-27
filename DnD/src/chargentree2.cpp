#include <QtGui>
#include <QDesktopWidget>

#include "include/chargentree2.h"
#include "include/game_board.h"
#include "ui_chargentree2.h"


extern GameBoard *game;

CharacterTreeNode* cur_node2;

CharGenTree2::CharGenTree2(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CharGenTree2) {
    ui->setupUi(this);

    setFixedSize(650, 560);

    chgs = new CharGenSkills();

    QPixmap pic("../images/a.svg");
    CharGenTree2::ui->bg->setScaledContents(true);
    CharGenTree2::ui->bg->setPixmap(pic);

    QPixmap picqst("../images/gst_bg");
    CharGenTree2::ui->qstbg->setScaledContents(true);
    CharGenTree2::ui->qstbg->setPixmap(picqst);
    QPixmap q("../images/qst.png");
    CharGenTree2::ui->qst->setScaledContents(true);
    CharGenTree2::ui->qst->setPixmap(q);

    connect(CharGenTree2::ui->yes_button, SIGNAL(clicked()), this, SLOT(on_next_yes_button_clicked()));
    connect(CharGenTree2::ui->no_button, SIGNAL(clicked()), this, SLOT(on_next_no_button_clicked()));
    t2.buildTree();
    cur_node2 = t2.getCharacterTreeRoot();
    CharGenTree2::ui->qst_t->setText(cur_node2->getQst().c_str());

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

CharGenTree2::~CharGenTree2() {
    delete ui;
}

void CharGenTree2::on_yes_button_clicked() {
    chck_yes = true;
    if (cur_node2->getLeftNode() == nullptr && cur_node2->getRightNode() == nullptr) {
        chck_yes = false;
        return;
    }

    cur_node2 = cur_node2->getLeftNode();
    CharGenTree2::ui->qst_t->setText(cur_node2->getQst().c_str());
}

void CharGenTree2::on_no_button_clicked() {
    chck_yes = true;
    if (cur_node2->getLeftNode() == nullptr && cur_node2->getRightNode() == nullptr) {
        chck_no = false;
        return;
    }
    cur_node2 = cur_node2->getRightNode();
    CharGenTree2::ui->qst_t->setText(cur_node2->getQst().c_str());
}

void CharGenTree2::on_next_step_clicked() {
    CharacterSkills cs;
    Backpack bp;
    game->boards[0].heroes[1].h = new Hero(cs, bp);
    t2.generateChar(game->boards[0].heroes[1].h, cur_node2);
    game->boards[1].heroes[1].h = game->boards[0].heroes[1].h;
    int num = game->charIm.char1;
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
    game->charIm.char2 = num;
    chgs->setParams(game->charIm.chars[game->charIm.char1], game->charIm.chars[game->charIm.char2], game->boards[0].heroes[0].h, game->boards[0].heroes[1].h);
    chgs->show();
    this->close();
}

