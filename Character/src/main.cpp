/* Author: Itsenko Ekaterina */

//! Some kind of tmp file

#include <iostream>
#include "Character.h"
#include "Backpack.h"

int main() {
    CharacterSkills cs;
    Backpack bp;
    Hero h(cs, bp);
    std::cout << h.getName();
	return 0;
}