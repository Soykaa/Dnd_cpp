#include <QtGui>
#include <QDesktopWidget>

#include "chargen.h"
#include "ui_chargen2.h"
#include "sleep.h"

CharGen2::CharGen2(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::CharGen2) {
    ui->setupUi(this);

    setFixedSize(400, 460);

    QPixmap pic(":/img/char_bg.png");
    CharGen2::ui->bg->setScaledContents(true);
    CharGen2::ui->bg->setPixmap(pic);

    CharGen2::ui->nextStep->hide();

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

CharGen2::~CharGen2()
{
    delete ui;
}

void CharGen2::on_randomMode_clicked()
{
    CharGen2::ui->standardMode->setEnabled(false);
    CharGen2::ui->randomMode->setText("Generating...");
    sleep(2000);
    CharGen2::ui->randomMode->setText("Generated");
    CharGen2::ui->randomMode->setEnabled(false);
    CharGen2::ui->nextStep->show();
}


