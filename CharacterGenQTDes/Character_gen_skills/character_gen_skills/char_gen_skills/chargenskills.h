#ifndef CHARGENSKILLS_H
#define CHARGENSKILLS_H

#include <QWidget>

namespace Ui {
class CharGenSkills;
}

class CharGenSkills : public QWidget
{
    Q_OBJECT

public:
    explicit CharGenSkills(QWidget *parent = 0);
    ~CharGenSkills();

private:
    Ui::CharGenSkills *ui;
};

#endif // CHARGENSKILLS_H
