/********************************************************************************
** Form generated from reading UI file 'chargen2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEN2_H
#define UI_CHARGEN2_H

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

class Ui_CharGen2 {
public:
    QLabel *bg;
    QPushButton *standardMode;
    QPushButton *randomMode;
    QCommandLinkButton *nextStep;

    void setupUi(QWidget *CharGen2) {
        if (CharGen2->objectName().isEmpty())
            CharGen2->setObjectName(QStringLiteral("CharGen2"));
        CharGen2->resize(400, 460);
        bg = new QLabel(CharGen2);
        bg->setObjectName(QStringLiteral("bg"));
        bg->setGeometry(QRect(0, 0, 400, 460));
        bg->setLineWidth(0);
        standardMode = new QPushButton(CharGen2);
        standardMode->setObjectName(QStringLiteral("standardMode"));
        standardMode->setGeometry(QRect(35, 275, 130, 50));
        randomMode = new QPushButton(CharGen2);
        randomMode->setObjectName(QStringLiteral("randomMode"));
        randomMode->setGeometry(QRect(235, 275, 130, 50));
        nextStep = new QCommandLinkButton(CharGen2);
        nextStep->setObjectName(QStringLiteral("nextStep"));
        nextStep->setGeometry(QRect(265, 385, 100, 40));
        nextStep->setAutoFillBackground(true);
        nextStep->setIconSize(QSize(30, 30));

        retranslateUi(CharGen2);

        QMetaObject::connectSlotsByName(CharGen2);
    } // setupUi

    void retranslateUi(QWidget *CharGen2) {
        CharGen2->setWindowTitle(QApplication::translate("CharGen2", "Form", Q_NULLPTR));
        bg->setText(QString());
        standardMode->setText(QApplication::translate("CharGen2", "Standard mode", Q_NULLPTR));
        randomMode->setText(QApplication::translate("CharGen2", "Random mode", Q_NULLPTR));
        nextStep->setText(QApplication::translate("CharGen2", "Start", Q_NULLPTR));
    } // retranslateUi
};

namespace Ui {
    class CharGen2: public Ui_CharGen2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEN2_H
