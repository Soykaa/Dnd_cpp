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

     //Text
    CharGenSkills::ui->skills11->setText("Интеллект:");
    CharGenSkills::ui->skills12->setText("Мудрость:");
    CharGenSkills::ui->skills13->setText("Сила:");
    CharGenSkills::ui->skills14->setText("Гибкость");
    CharGenSkills::ui->skills15->setText("Телосложение:");
    CharGenSkills::ui->skills16->setText("Харизма:");
    CharGenSkills::ui->skills17->setText("Класс:");
    CharGenSkills::ui->skills18->setText("Раса:");
    CharGenSkills::ui->skills19->setText("Cпособность:");

    CharGenSkills::ui->skills21->setText("Интеллект:");
    CharGenSkills::ui->skills22->setText("Мудрость:");
    CharGenSkills::ui->skills23->setText("Сила:");
    CharGenSkills::ui->skills24->setText("Гибкость");
    CharGenSkills::ui->skills25->setText("Телосложение:");
    CharGenSkills::ui->skills26->setText("Харизма:");
    CharGenSkills::ui->skills27->setText("Класс:");
    CharGenSkills::ui->skills28->setText("Раса:");
    CharGenSkills::ui->skills29->setText("Способность:");

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

void CharGenSkills::setParams(QString str1, QString str2, Hero* h1, Hero* h2) {
    /* first hero */
    QPixmap hero1(str1);
    CharGenSkills::ui->img1->setScaledContents(true);
    CharGenSkills::ui->img1->setPixmap(hero1.scaled(120, 180));

    CharGenSkills::ui->skills11->setText(CharGenSkills::ui->skills11->text() + "           " + QString::number(h1->cs_.getIntelligence()));
    CharGenSkills::ui->skills12->setText(CharGenSkills::ui->skills12->text() + "            " + QString::number(h1->cs_.getWisdom()));
    CharGenSkills::ui->skills13->setText(CharGenSkills::ui->skills13->text() + "                   " + QString::number(h1->cs_.getStrength()));
    CharGenSkills::ui->skills14->setText(CharGenSkills::ui->skills14->text() + "              " + QString::number(h1->cs_.getDexterity()));
    CharGenSkills::ui->skills15->setText(CharGenSkills::ui->skills15->text() + "      " + QString::number(h1->cs_.getConstitution()));
    CharGenSkills::ui->skills16->setText(CharGenSkills::ui->skills16->text() + "               " + QString::number(h1->cs_.getCharisma()));

    if (h1->getClass() == CharClass::wizard)
        CharGenSkills::ui->skills17->setText(CharGenSkills::ui->skills17->text() + "                               Маг");
    if (h1->getClass() == CharClass::druid)
        CharGenSkills::ui->skills17->setText(CharGenSkills::ui->skills17->text() + "                           Друид");
    if (h1->getClass() == CharClass::fighter)
        CharGenSkills::ui->skills17->setText(CharGenSkills::ui->skills17->text() + "                           Воин");

    if (h1->getRace() == CharRace::dragonborn)
        CharGenSkills::ui->skills18->setText(CharGenSkills::ui->skills18->text() + "             Драконорожденный");
    if (h1->getRace() == CharRace::elf)
        CharGenSkills::ui->skills18->setText(CharGenSkills::ui->skills18->text() + "                                Эльф");
    if (h1->getRace() == CharRace::human) 
        CharGenSkills::ui->skills18->setText(CharGenSkills::ui->skills18->text() + "                           Человек");

    if (h1->getSP() == SuperPowers::acrobatics)
        CharGenSkills::ui->skills19->setText(CharGenSkills::ui->skills19->text() + "     Сверхгибкость");
    if (h1->getSP() == SuperPowers::athletics)
        CharGenSkills::ui->skills19->setText(CharGenSkills::ui->skills19->text() + "          Сверхсила");
    if (h1->getSP() == SuperPowers::persuasion) 
        CharGenSkills::ui->skills19->setText(CharGenSkills::ui->skills19->text() + "   Убедительность");


    /* second hero */
    QPixmap hero2(str2);
    CharGenSkills::ui->img2->setScaledContents(true);
    CharGenSkills::ui->img2->setPixmap(hero2.scaled(120, 180));

    CharGenSkills::ui->skills21->setText(CharGenSkills::ui->skills21->text() + "          " + QString::number(h2->cs_.getIntelligence()));
    CharGenSkills::ui->skills22->setText(CharGenSkills::ui->skills22->text() + "            " + QString::number(h2->cs_.getWisdom()));
    CharGenSkills::ui->skills23->setText(CharGenSkills::ui->skills23->text() + "                   " + QString::number(h2->cs_.getStrength()));
    CharGenSkills::ui->skills24->setText(CharGenSkills::ui->skills24->text() + "              " + QString::number(h2->cs_.getDexterity()));
    CharGenSkills::ui->skills25->setText(CharGenSkills::ui->skills25->text() + "      " + QString::number(h2->cs_.getConstitution()));
    CharGenSkills::ui->skills26->setText(CharGenSkills::ui->skills26->text() + "               " + QString::number(h2->cs_.getCharisma()));

    if (h2->getClass() == CharClass::wizard)
        CharGenSkills::ui->skills27->setText(CharGenSkills::ui->skills27->text() + "                               Маг");
    if (h2->getClass() == CharClass::druid)
        CharGenSkills::ui->skills27->setText(CharGenSkills::ui->skills27->text() + "                           Друид");
    if (h2->getClass() == CharClass::fighter) 
        CharGenSkills::ui->skills27->setText(CharGenSkills::ui->skills27->text() + "                           Воин");

    if (h2->getRace() == CharRace::dragonborn) 
        CharGenSkills::ui->skills28->setText(CharGenSkills::ui->skills28->text() + "             Драконорожденный");
    if (h2->getRace() == CharRace::elf)
        CharGenSkills::ui->skills28->setText(CharGenSkills::ui->skills28->text() + "                                Эльф");
    if (h2->getRace() == CharRace::human)
        CharGenSkills::ui->skills28->setText(CharGenSkills::ui->skills28->text() + "                           Человек");

    if (h2->getSP() == SuperPowers::acrobatics) 
        CharGenSkills::ui->skills29->setText(CharGenSkills::ui->skills29->text() + "     Сверхгибкость");
    if (h2->getSP() == SuperPowers::athletics)
        CharGenSkills::ui->skills29->setText(CharGenSkills::ui->skills29->text() + "          Сверхсила");
    if (h2->getSP() == SuperPowers::persuasion) 
        CharGenSkills::ui->skills29->setText(CharGenSkills::ui->skills29->text() + "   Убедительность");
}

CharGenSkills::~CharGenSkills() {
    delete ui;
}

void CharGenSkills::on_nextStep_clicked() {
    hide();
    game->makeGame();
}
