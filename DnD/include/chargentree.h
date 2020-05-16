#ifndef CHARGENTREE_H
#define CHARGENTREE_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

#include "chargen2.h"

namespace Ui {
class CharGenTree;
}

class CharGenTree : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGenTree(QWidget* parent = 0);
    ~CharGenTree();

private slots:
    void on_next_step_clicked();

private:
    Ui::CharGenTree* ui;
    CharGen2* chg;
};

#endif // CHARGENTREE_H
