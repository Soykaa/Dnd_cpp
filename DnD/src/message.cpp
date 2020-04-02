#include "include/message.h"
#include <QFont>

Message::Message(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
	setPlainText(QString("Победа!!!"));
	setDefaultTextColor(Qt::red);
	setFont(QFont("Lobster", 100));
}