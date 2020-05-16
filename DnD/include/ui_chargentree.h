/********************************************************************************
** Form generated from reading UI file 'chargentree.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGENTREE_H
#define UI_CHARGENTREE_H

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

class Ui_CharGenTree {
public:
    QLabel *bg;
    QLabel *qstbg;
    QPushButton *yes_button;
    QPushButton *no_button;
    QCommandLinkButton *next_step;
    QLabel *qst;

    void setupUi(QWidget *CharGenTree) {
        if (CharGenTree->objectName().isEmpty())
            CharGenTree->setObjectName(QStringLiteral("CharGenTree"));
        CharGenTree->resize(650, 560);
        bg = new QLabel(CharGenTree);
        bg->setObjectName(QStringLiteral("bg"));
        bg->setGeometry(QRect(0, 0, 650, 560));
        bg->setPixmap(QPixmap(QString::fromUtf8("../dnd_prj/Dnd_cpp/CharacterGenTreeQTDes/char_bg.png")));
        qstbg = new QLabel(CharGenTree);
        qstbg->setObjectName(QStringLiteral("qstbg"));
        qstbg->setGeometry(QRect(25, 25, 600, 100));
        yes_button = new QPushButton(CharGenTree);
        yes_button->setObjectName(QStringLiteral("yes_button"));
        yes_button->setGeometry(QRect(50, 390, 150, 60));
        no_button = new QPushButton(CharGenTree);
        no_button->setObjectName(QStringLiteral("no_button"));
        no_button->setGeometry(QRect(450, 390, 150, 60));
        next_step = new QCommandLinkButton(CharGenTree);
        next_step->setObjectName(QStringLiteral("next_step"));
        next_step->setGeometry(QRect(480, 490, 120, 40));
        next_step->setAutoFillBackground(true);
        next_step->setIconSize(QSize(30, 30));
        qst = new QLabel(CharGenTree);
        qst->setObjectName(QStringLiteral("qst"));
        qst->setGeometry(QRect(200, 140, 240, 370));

        retranslateUi(CharGenTree);

        QMetaObject::connectSlotsByName(CharGenTree);
    } // setupUi

    void retranslateUi(QWidget *CharGenTree) {
        CharGenTree->setWindowTitle(QApplication::translate("CharGenTree", "CharGenTree", Q_NULLPTR));
        bg->setText(QString());
        qstbg->setText(QString());
        yes_button->setText(QApplication::translate("CharGenTree", "\320\224\320\260", Q_NULLPTR));
        no_button->setText(QApplication::translate("CharGenTree", "\320\235\320\265\321\202", Q_NULLPTR));
        next_step->setText(QApplication::translate("CharGenTree", "\320\224\320\260\320\273\320\265\320\265", Q_NULLPTR));
        qst->setText(QString());
    } // retranslateUi
};

namespace Ui {
    class CharGenTree: public Ui_CharGenTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGENTREE_H
