#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "gift.h"
#include "obstacle.h"

enum class Type {
	emptyField,
	obstacle,
	door,
	start,
	finnish,
	gift,
	// TODO
};

enum class Direction {
	up,
	down,
	left,
	right,
};

struct GiftCord {
	Gift* gift;
	int x;
	int y;
};

struct ObstacleCord {
	Obstacle* obst;
	int x;
	int y;
};

#endif