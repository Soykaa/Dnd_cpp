#ifndef CHARGEN_H
#define CHARGEN_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

#include "chargen2.h"
#include "chargentree.h"

namespace Ui {
class CharGen;
}

class CharGen : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGen(QWidget* parent = 0);
    ~CharGen();

private slots:
    void on_randomMode_clicked();

    void on_nextStep_clicked();

    void on_standardMode_clicked();

private:
    Ui::CharGen* ui;
    CharGen2* chg;
    CharGenTree* chgt;
};

#endif // CHARGEN_H
