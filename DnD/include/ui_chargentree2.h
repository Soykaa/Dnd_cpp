/********************************************************************************
** Form generated from reading UI file 'chargentree2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGENTREE2_H
#define UI_CHARGENTREE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharGenTree2 {
public:
    QLabel *bg;
    QLabel *qstbg;
    QPushButton *yes_button;
    QPushButton *no_button;
    QLabel *qst;
    QCommandLinkButton *next_step;

    void setupUi(QWidget *CharGenTree2) {
        if (CharGenTree2->objectName().isEmpty())
            CharGenTree2->setObjectName(QStringLiteral("CharGenTree2"));
        CharGenTree2->resize(650, 560);
        bg = new QLabel(CharGenTree2);
        bg->setObjectName(QStringLiteral("bg"));
        bg->setGeometry(QRect(0, 0, 650, 560));
        qstbg = new QLabel(CharGenTree2);
        qstbg->setObjectName(QStringLiteral("qstbg"));
        qstbg->setGeometry(QRect(25, 25, 600, 100));
        yes_button = new QPushButton(CharGenTree2);
        yes_button->setObjectName(QStringLiteral("yes_button"));
        yes_button->setGeometry(QRect(50, 390, 150, 60));
        no_button = new QPushButton(CharGenTree2);
        no_button->setObjectName(QStringLiteral("no_button"));
        no_button->setGeometry(QRect(450, 390, 150, 60));
        qst = new QLabel(CharGenTree2);
        qst->setObjectName(QStringLiteral("qst"));
        qst->setGeometry(QRect(200, 140, 240, 370));
        next_step = new QCommandLinkButton(CharGenTree2);
        next_step->setObjectName(QStringLiteral("next_step"));
        next_step->setGeometry(QRect(480, 490, 120, 40));
        next_step->setAutoFillBackground(true);
        next_step->setIconSize(QSize(30, 30));

        retranslateUi(CharGenTree2);

        QMetaObject::connectSlotsByName(CharGenTree2);
    } // setupUi

    void retranslateUi(QWidget *CharGenTree2) {
        CharGenTree2->setWindowTitle(QApplication::translate("CharGenTree2", "CharGenTree", Q_NULLPTR));
        bg->setText(QString());
        qstbg->setText(QString());
        yes_button->setText(QApplication::translate("CharGenTree2", "\320\224\320\260", Q_NULLPTR));
        no_button->setText(QApplication::translate("CharGenTree2", "\320\235\320\265\321\202", Q_NULLPTR));
        qst->setText(QString());
        next_step->setText(QApplication::translate("CharGenTree2", "\320\224\320\260\320\273\320\265\320\265", Q_NULLPTR));
    } // retranslateUi
};

namespace Ui {
    class CharGenTree2: public Ui_CharGenTree2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGENTREE2_H
