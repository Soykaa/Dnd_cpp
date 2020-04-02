#ifndef DND_DICE_H
#define DND_DICE_H

#include <QGraphicsTextItem>

class Dice : public QGraphicsTextItem {
public:
	Dice(QGraphicsItem *parent = 0);
	void throw_dice();
	int get_number() {return dice_number_;}
private:
	int dice_number_;
};

#endif //DND_DICE_H