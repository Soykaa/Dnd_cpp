#ifndef CHARGENTREE_H
#define CHARGENTREE_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

#include "chargentree2.h"

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
    CharGenTree2* chgt2;
};

#endif // CHARGENTREE_H
