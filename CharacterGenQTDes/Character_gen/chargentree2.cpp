#include <QtGui>
#include <QDesktopWidget>

#include "chargentree2.h"
#include "ui_chargentree2.h"

CharGenTree2::CharGenTree2(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CharGenTree2) {
    ui->setupUi(this);

    setFixedSize(650, 560);

    QPixmap pic(":/img/char_bg.png");
    CharGenTree2::ui->bg->setScaledContents(true);
    CharGenTree2::ui->bg->setPixmap(pic);

    QPixmap picqst(":/img/gst_bg");
    CharGenTree2::ui->qstbg->setScaledContents(true);
    CharGenTree2::ui->qstbg->setPixmap(picqst);

    QPixmap q(":/img/qst.png");
    CharGenTree2::ui->qst->setScaledContents(true);
    CharGenTree2::ui->qst->setPixmap(q);

    //CharGenTree2::ui->next_step->hide();

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

CharGenTree2::~CharGenTree2() {
    delete ui;
}
