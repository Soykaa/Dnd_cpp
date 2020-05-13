/********************************************************************************
** Form generated from reading UI file 'chargen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGEN_H
#define UI_CHARGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharGen
{
public:
    QWidget *centralWidget;
    QLabel *bg;
    QPushButton *standardMode;
    QPushButton *randomMode;
    QCommandLinkButton *nextStep;

    void setupUi(QMainWindow *CharGen)
    {
        if (CharGen->objectName().isEmpty())
            CharGen->setObjectName(QStringLiteral("CharGen"));
        CharGen->resize(400, 460);
        centralWidget = new QWidget(CharGen);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(400, 460));
        bg = new QLabel(centralWidget);
        bg->setObjectName(QStringLiteral("bg"));
        bg->setGeometry(QRect(0, 0, 400, 460));
        bg->setMaximumSize(QSize(400, 460));
        standardMode = new QPushButton(centralWidget);
        standardMode->setObjectName(QStringLiteral("standardMode"));
        standardMode->setGeometry(QRect(25, 275, 160, 50));
        randomMode = new QPushButton(centralWidget);
        randomMode->setObjectName(QStringLiteral("randomMode"));
        randomMode->setGeometry(QRect(210, 275, 160, 50));
        nextStep = new QCommandLinkButton(centralWidget);
        nextStep->setObjectName(QStringLiteral("nextStep"));
        nextStep->setGeometry(QRect(265, 385, 100, 40));
        nextStep->setAutoFillBackground(true);
        nextStep->setIconSize(QSize(30, 30));
        CharGen->setCentralWidget(centralWidget);

        retranslateUi(CharGen);

        QMetaObject::connectSlotsByName(CharGen);
    } // setupUi

    void retranslateUi(QMainWindow *CharGen)
    {
        CharGen->setWindowTitle(QApplication::translate("CharGen", "CharGen", Q_NULLPTR));
        bg->setText(QString());
        standardMode->setText(QApplication::translate("CharGen", "\320\241\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        randomMode->setText(QApplication::translate("CharGen", "\320\241\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        nextStep->setText(QApplication::translate("CharGen", "\320\224\320\260\320\273\320\265\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CharGen: public Ui_CharGen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGEN_H
