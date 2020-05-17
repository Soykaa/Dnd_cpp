#ifndef CHARGENSKILLS_H
#define CHARGENSKILLS_H

#include <QWidget>

namespace Ui {
class chargenskills;
}

class chargenskills : public QWidget
{
    Q_OBJECT

public:
    explicit chargenskills(QWidget *parent = 0);
    ~chargenskills();

private:
    Ui::chargenskills *ui;
};

#endif // CHARGENSKILLS_H
