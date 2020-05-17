#include "chargenskills.h"
#include "ui_chargenskills.h"

CharGenSkills::CharGenSkills(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharGenSkills)
{
    ui->setupUi(this);
}

CharGenSkills::~CharGenSkills()
{
    delete ui;
}
