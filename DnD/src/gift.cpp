#include "include/gift.h"

Gift::Gift(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap("images/gift.png"));
	is_taken = false;
}
