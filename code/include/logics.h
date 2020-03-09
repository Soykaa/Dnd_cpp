#ifndef LOGICS_H_INCLUDED
#define LOGICS_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <array>

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
	forward,
	back,
	left,
	right,
};

struct EndOfTheMove {
	size_t x;
	size_t y;
	Type type;

};

class Encounter {
private:
	Type type_;
public:
	Encounter() : type_(Type::emptyField) {};
	Encounter(Type type);
	Encounter(Encounter& other);
	Encounter& operator=(const Encounter& other);
	//bool operator!=(Encounter& other);
	~Encounter() {};
	Type getType() {return type_; };
	void changeType(Type type);
};

class Character {
	int name;
};

class Board {
private:
	static const int size_ = 5;
	std::array<std::array<Encounter, size_>, size_> board_;
	size_t characterPosition_X = 2;
	size_t characterPosition_Y = 2;
	bool canWin = false;
public:
	Board() {};
	Encounter getField(size_t i, size_t j);
	size_t getSize();
	void Print();
	size_t getCharacterPosition_X();
	size_t getCharacterPosition_Y();
	bool getCanWin();
	EndOfTheMove isSomethingOnTheWay(Direction direction, int amountOfFields);
	Type makeTurn(Direction direction, int amountOfFields);
	void changeOneFieldType(size_t i, size_t j, Type type);
	~Board() {};
};

class Game {
public:
	Board location_;
	Character& hero_; 
public:
	Game(Character& hero) : hero_(hero) {};
	void runGame();
};

#endif	