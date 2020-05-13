#ifndef CHARGENTREE2_H
#define CHARGENTREE2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>
#include <QWidget>

namespace Ui {
class CharGenTree2;
}

class CharGenTree2 : public QMainWindow {
    Q_OBJECT

public:
    explicit CharGenTree2(QWidget *parent = 0);
    ~CharGenTree2();

private:
    Ui::CharGenTree2 *ui;
};

#endif // CHARGENTREE2_H
