#include <QtGui>
#include <QDesktopWidget>

#include "chargen.h"
#include "ui_chargen.h"
#include "sleep.h"

CharGen::CharGen(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::CharGen) {
    ui->setupUi(this);

    chg = new CharGen2();

    setFixedSize(400, 460);

    QPixmap pic(":/img/char_bg.png");
    CharGen::ui->bg->setScaledContents(true);
    CharGen::ui->bg->setPixmap(pic);

    CharGen::ui->nextStep->hide();

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

CharGen::~CharGen()
{
    delete ui;
}

void CharGen::on_randomMode_clicked()
{
    CharGen::ui->standardMode->setEnabled(false);
    CharGen::ui->randomMode->setText("Генерирую...");
    sleep(2000);
    CharGen::ui->randomMode->setText("Сгенерировано");
    CharGen::ui->randomMode->setEnabled(false);
    CharGen::ui->nextStep->show();
}

void CharGen::on_nextStep_clicked()
{
    chg->show();
    this->close();
}
