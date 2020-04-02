#ifndef ENCOUNTER_H_INCLUDED
#define ENCOUNTER_H_INCLUDED
#include "utility.h"

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

#endif