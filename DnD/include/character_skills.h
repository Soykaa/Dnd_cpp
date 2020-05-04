/* Author: Itsenko Ekaterina */

#ifndef CHARACTER_SKILLS_H_
#define CHARACTER_SKILLS_H_

#include <cstddef>

//! @class CharacterSkills
class CharacterSkills {
public:
    CharacterSkills();
    CharacterSkills(size_t intelligence, size_t wisdom, size_t strength, size_t dexterity, size_t constitution, size_t charisma);
    size_t getIntelligence() const;
    size_t getWisdom() const;
    size_t getStrength() const;
    size_t getDexterity() const;
    size_t getConstitution() const;
    size_t getCharisma() const;

    void setIntelligence(size_t intelligence);
    void setWisdom(size_t wisdom);
    void setStrength(size_t strength);
    void setDexterity(size_t dexterity);
    void setConstitution(size_t constitution);
    void setCharisma(size_t charisma);
private:
    size_t strength_;
    size_t dexterity_;
    size_t constitution_;
    size_t intelligence_;
    size_t wisdom_;
    size_t charisma_;
};

#endif //DND_CPP_CHARACTER_SKILLS_H
