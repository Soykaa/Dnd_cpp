#include <iostream>
#include <utility>

#include "include/character_tree.h"

/* Class CharacterTreeNode */
CharacterTreeNode::CharacterTreeNode(std::string qst, CharacterTreeNode* right, CharacterTreeNode* left, int ans)
    : _qst(std::move(qst)), _right(right), _left(left), _ans(ans)
    {}

std::string CharacterTreeNode::getQst() const {
    return _qst;
}

int CharacterTreeNode::getAns() const {
    return _ans;
}

CharacterTreeNode* CharacterTreeNode::getLeftNode() const {
    return _left;
}

CharacterTreeNode* CharacterTreeNode::getRightNode() const {
    return _right;
}

void CharacterTreeNode::deleteCharacterTreeNode() {
    this->_right->deleteCharacterTreeNode();
    this->_left->deleteCharacterTreeNode();
    delete this;
}

/* Class CharacterTree */
CharacterTree::CharacterTree()
    : _root(nullptr)
    {}

CharacterTree::~CharacterTree() {
    _root->deleteCharacterTreeNode();
}

CharacterTreeNode* CharacterTree::getCharacterTreeRoot() const {
    return _root;
}

void CharacterTree::buildTree() {
    CharacterTreeNode* nodes[54];
    nodes[52] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 10);
    nodes[51] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 9);
    nodes[50] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 8);
    nodes[49] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 7);
    nodes[48] = new CharacterTreeNode("Ваш персонаж крупный?", nodes[52], nodes[51], 0);
    nodes[47] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 12);
    nodes[46] = new CharacterTreeNode("Ваш персонаж мускулистый?", nodes[50], nodes[49], 0);
    nodes[45] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 11);
    nodes[44] = new CharacterTreeNode("Ваш персонаж болтлив?", nodes[48], nodes[47], 0);
    nodes[43] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[46], nodes[45], 0);
    nodes[42] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 16);
    nodes[41] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 15);
    nodes[40] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[42], nodes[41], 0);
    nodes[39] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 18);
    nodes[38] = new CharacterTreeNode("Ваш персонаж хорошо знает математику?", nodes[44], nodes[43], 0);
    nodes[37] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[40], nodes[39], 0);
    nodes[36] = new CharacterTreeNode("Ваш персонаж умеет колдовать?", nodes[38], nodes[37], 0);
    nodes[35] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 6);
    nodes[34] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 5);
    nodes[33] = new CharacterTreeNode("Ваш персонаж любит драться?", nodes[35], nodes[34], 0);
    nodes[32] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 4);
    nodes[31] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 3);
    nodes[30] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 2);
    nodes[29] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[33], nodes[32], 0);
    nodes[28] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[31], nodes[30], 0);
    nodes[27] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 1);
    nodes[26] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[28], nodes[27], 0);
    nodes[25] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 14);
    nodes[24] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 13);
    nodes[23] = new CharacterTreeNode("Ваш персонаж крупный?", nodes[25], nodes[24], 0);
    nodes[22] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 17);
    nodes[21] = new CharacterTreeNode("Ваш персонаж увлекается астрономией?", nodes[29], nodes[26], 0);
    nodes[20] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[23], nodes[22], 0);
    nodes[19] = new CharacterTreeNode("Ваш персонаж умеет колдовать?", nodes[21], nodes[20], 0);
    nodes[18] = new CharacterTreeNode("Ваш персонаж дружит с драконами?", nodes[36], nodes[19], 0);
    nodes[17] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 22);
    nodes[16] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 21);
    nodes[15] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 20);
    nodes[14] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 19);
    nodes[13] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[17], nodes[16], 0);
    nodes[12] = new CharacterTreeNode("Ваш персонаж мускулистый?", nodes[15], nodes[14], 0);
    nodes[11] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 26);
    nodes[10] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 25);
    nodes[9] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 24);
    nodes[8] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 23);
    nodes[7] = new CharacterTreeNode("Ваш персонаж болтлив?", nodes[13], nodes[11], 0);
    nodes[6] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[12], nodes[10], 0);
    nodes[5] = new CharacterTreeNode("Ваш персонаж крупный?", nodes[9], nodes[8], 0);
    nodes[4] = new CharacterTreeNode("Сгенерировано", nullptr, nullptr, 27);
    nodes[3] = new CharacterTreeNode("Ваш персонаж увлекается наукой?", nodes[7], nodes[6], 0);
    nodes[2] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[5], nodes[4], 0);
    nodes[1] = new CharacterTreeNode("Ваш персонаж обладает магическими способностями?", nodes[3], nodes[2], 0);
    nodes[0] = new CharacterTreeNode("Ваш персонаж - фантастическое существо?", nodes[1], nodes[18], 0);
    _root = nodes[0];
}

void CharacterTree::generateChar(Hero* h, CharacterTreeNode* n) {
    switch (n->getAns()) {
        case 1:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::elf);
            break;
        case 2:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::elf);
            break;
        case 3:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::elf);
            break;
        case 4:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::elf);
            break;
        case 5:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::elf);
            break;
        case 6:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::elf);
            break;
        case 7:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::dragonborn);
            break;
        case 8:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::dragonborn);
            break;
        case 9:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::dragonborn);
            break;
        case 10:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::dragonborn);
            break;
        case 11:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::dragonborn);
            break;
        case 12:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::dragonborn);
            break;
        case 13:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::elf);
            break;
        case 14:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::elf);
            break;
        case 15:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::dragonborn);
            break;
        case 16:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::dragonborn);
            break;
        case 17:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::elf);
            break;
        case 18:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::dragonborn);
            break;
        case 19:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::human);
            break;
        case 20:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::human);
            break;
        case 21:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::human);
            break;
        case 22:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::human);
            break;
        case 23:
            h->setSP(SuperPowers::athletics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::human);
            break;
        case 24:
            h->setSP(SuperPowers::acrobatics);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::human);
            break;
        case 25:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::human);
            break;
        case 26:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::fighter);
            h->setRace(CharRace::human);
            break;
        case 27:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::wizard);
            h->setRace(CharRace::human);
            break;
        default:
            h->setSP(SuperPowers::persuasion);
            h->setClass(CharClass::druid);
            h->setRace(CharRace::elf);
            break;
    }
    /* SuperPowers */
    if (h->getSP() == SuperPowers::persuasion)
        h->cs_.setCharisma(18);
    if (h->getSP() == SuperPowers::athletics)
        h->cs_.setStrength(18);
    if (h->getSP() == SuperPowers::acrobatics)
        h->cs_.setDexterity(18);
    /* Class */
    if (h->getClass() == CharClass::wizard) {
        h->cs_.setIntelligence(9);
        h->cs_.setWisdom(14);
        h->cs_.setStrength(9);
        h->cs_.setDexterity(8);
        h->cs_.setConstitution(6);
        h->cs_.setCharisma(12);
    }
    if (h->getClass() == CharClass::druid) {
        h->cs_.setIntelligence(14);
        h->cs_.setWisdom(10);
        h->cs_.setStrength(7);
        h->cs_.setDexterity(7);
        h->cs_.setConstitution(8);
        h->cs_.setCharisma(9);
    }
    if (h->getClass() == CharClass::fighter) {
        h->cs_.setIntelligence(5);
        h->cs_.setWisdom(7);
        h->cs_.setStrength(14);
        h->cs_.setDexterity(12);
        h->cs_.setConstitution(11);
        h->cs_.setCharisma(9);
    }
}
