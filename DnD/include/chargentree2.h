#ifndef CHARGENTREE2_H
#define CHARGENTREE2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>
#include <QWidget>

#include "chargenskills.h"

namespace Ui {
class CharGenTree2;
}

class CharGenTree2 : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGenTree2(QWidget* parent = 0);
    ~CharGenTree2();

private:
    Ui::CharGenTree2* ui;
    CharGenSkills* chgs;

private slots:
    void on_next_step_clicked();
};

#endif // CHARGENTREE2_H
