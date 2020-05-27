#ifndef CHARGENSKILLS_H
#define CHARGENSKILLS_H

#include <QWidget>
#include "include/character.h"

namespace Ui {
class CharGenSkills;
}

class CharGenSkills : public QWidget {
    Q_OBJECT

public:
    explicit CharGenSkills(QWidget *parent = 0);
    void setImages(QString str1, QString str2, Hero* h1 = nullptr);
    ~CharGenSkills();

private slots:
    void on_nextStep_clicked();


private:
    Ui::CharGenSkills *ui;
};

#endif // CHARGENSKILLS_H
