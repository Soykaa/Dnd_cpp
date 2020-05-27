#ifndef CHARGENTREE2_H
#define CHARGENTREE2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>
#include <QWidget>

#include "chargenskills.h"
#include "include/character_tree.h"

namespace Ui {
class CharGenTree2;
}

class CharGenTree2 : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGenTree2(QWidget* parent = 0);
    ~CharGenTree2();

private slots:
    void on_next_step_clicked();
    void on_no_button_clicked();
    void on_yes_button_clicked();

private:
    Ui::CharGenTree2* ui;
    CharGenSkills* chgs;
    CharacterTree t2;
    bool chck_no, chck_yes;
};

#endif // CHARGENTREE2_H
