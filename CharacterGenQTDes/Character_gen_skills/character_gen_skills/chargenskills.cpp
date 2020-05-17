#include "chargenskills.h"
#include "ui_chargenskills.h"

chargenskills::chargenskills(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chargenskills)
{
    ui->setupUi(this);
}

chargenskills::~chargenskills()
{
    delete ui;
}
