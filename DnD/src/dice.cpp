#include "include/dice.h"
#include <QFont>

Dice::Dice(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
	dice_number_ = rand() % 4 + 1;
	setPlainText(QString("Выпавшее число: ") + QString::number(dice_number_));
	setDefaultTextColor(Qt::white);
	setFont(QFont("Helvetica", 25));
}

void Dice::throw_dice() {
	dice_number_ = rand() % 4 + 1;
	setPlainText(QString("Выпавшее число: ") + QString::number(dice_number_));
	setDefaultTextColor(Qt::white);
	setFont(QFont("Helvetica", 25));
}