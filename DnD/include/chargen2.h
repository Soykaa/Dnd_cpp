#ifndef CHARGEN2_H
#define CHARGEN2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

#include "chargentree2.h"
#include "chargenskills.h"

namespace Ui {
class CharGen2;
}

class CharGen2 : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGen2(QWidget *parent = nullptr);
    ~CharGen2() override;

private slots:
    void on_randomMode_clicked();
    void on_standardMode_clicked();
    void on_nextStep_clicked();

private:
    Ui::CharGen2* ui;
    CharGenTree2* chgt2;
    CharGenSkills* chgs;
};

#endif // CHARGEN2_H
