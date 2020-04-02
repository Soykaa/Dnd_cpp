/********************************************************************************
** Form generated from reading UI file 'game_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_MENU_H
#define UI_GAME_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(800, 600);
        pushButton = new QPushButton(GameWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(225, 255, 300, 70));
        pushButton->setStyleSheet(QLatin1String("font: 63 11pt \"Ubuntu\";\n"
"font-size:27px;\n"
"background-color: rgb(136, 138, 133);\n"
"color: rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(GameWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(225, 355, 300, 70));
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(136, 138, 133);\n"
"font: 57 11pt \"Ubuntu\";\n"
"font-size:25px;\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(GameWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 750, 750));
        label->raise();
        pushButton->raise();
        pushButton_3->raise();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GameWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("GameWindow", "\320\237\320\276\320\272\320\270\320\275\321\203\321\202\321\214 \320\277\320\276\320\264\320\267\320\265\320\274\320\265\320\273\321\214\320\265", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_MENU_H
