#ifndef CHARGENTREE_H
#define CHARGENTREE_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include<QPushButton>
#include <QTime>

#include "chargen2.h"
#include "include/character_tree.h"

namespace Ui {
class CharGenTree;
}

class CharGenTree : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGenTree(QWidget* parent = 0);
    ~CharGenTree();
 	void generate_char(Hero* h);

private slots:
    void on_next_step_clicked();
    void on_next_no_button_clicked();
    void on_next_yes_button_clicked();

private:
    Ui::CharGenTree* ui;
    CharGen2* chg;
    CharacterTree t1;
    Hero* h;
	QPushButton* no_button;
    QPushButton* yes_button;
    bool chck_no, chck_yes;
};

#endif // CHARGENTREE_H
