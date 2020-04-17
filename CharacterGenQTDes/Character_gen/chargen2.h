#ifndef CHARGEN2_H
#define CHARGEN2_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTime>

namespace Ui {
class CharGen2;
}

class CharGen2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharGen2(QWidget *parent = 0);
    ~CharGen2();

private slots:
    void on_randomMode_clicked();

private:
    Ui::CharGen2 *ui;
};

#endif // CHARGEN2_H
