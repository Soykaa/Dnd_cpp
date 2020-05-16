#ifndef CHARGEN2_H
#define CHARGEN2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

#include "chargentree2.h"

namespace Ui {
class CharGen2;
}

class CharGen2 : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGen2(QWidget *parent = 0);
    ~CharGen2();

private slots:
    void on_randomMode_clicked();
    void on_standardMode_clicked();
    void on_nextStep_clicked();

private:
    Ui::CharGen2* ui;
    CharGenTree2* chgt2;
};

#endif // CHARGEN2_H
