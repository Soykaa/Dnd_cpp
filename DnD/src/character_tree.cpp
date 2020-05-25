#include <iostream>
#include <utility>

#include "include/character_tree.h"

/* Class CharacterTreeNode */
CharacterTreeNode::CharacterTreeNode(std::string qst, CharacterTreeNode* right, CharacterTreeNode* left)
        : _qst(std::move(qst)), _right(right), _left(left)
{}

std::string CharacterTreeNode::getQst() const {
    return _qst;
}

CharacterTreeNode* CharacterTreeNode::getLeftNode() const {
    return _left;
}

CharacterTreeNode* CharacterTreeNode::getRightNode() const {
    return _right;
}

void CharacterTreeNode::deleteCharacterTreeNode() {
    if (this == nullptr)
        return;
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
    nodes[52] = new CharacterTreeNode("10", nullptr, nullptr);
    nodes[51] = new CharacterTreeNode("9", nullptr, nullptr);
    nodes[50] = new CharacterTreeNode("8", nullptr, nullptr);
    nodes[49] = new CharacterTreeNode("7", nullptr, nullptr);
    nodes[48] = new CharacterTreeNode("Ваш персонаж имеет крупный?", nodes[52], nodes[51]);
    nodes[47] = new CharacterTreeNode("12", nullptr, nullptr);
    nodes[46] = new CharacterTreeNode("Ваш персонаж мускулистый?", nodes[50], nodes[49]);
    nodes[45] = new CharacterTreeNode("11", nullptr, nullptr);
    nodes[44] = new CharacterTreeNode("Ваш персонаж болтлив?", nodes[48], nodes[47]);
    nodes[43] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[46], nodes[45]);
    nodes[42] = new CharacterTreeNode("16", nullptr, nullptr);
    nodes[41] = new CharacterTreeNode("15", nullptr, nullptr);
    nodes[40] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[42], nodes[41]);
    nodes[39] = new CharacterTreeNode("18", nullptr, nullptr);
    nodes[38] = new CharacterTreeNode("Ваш персонаж хорошо знает математику?", nodes[44], nodes[43]);
    nodes[37] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[40], nodes[39]);
    nodes[36] = new CharacterTreeNode("Ваш персонаж умеет колдовать?", nodes[38], nodes[37]);
    nodes[35] = new CharacterTreeNode("6", nullptr, nullptr);
    nodes[34] = new CharacterTreeNode("5", nullptr, nullptr);
    nodes[33] = new CharacterTreeNode("Ваш персонаж любит драться?", nodes[35], nodes[34]);
    nodes[32] = new CharacterTreeNode("4", nullptr, nullptr);
    nodes[31] = new CharacterTreeNode("3", nullptr, nullptr);
    nodes[30] = new CharacterTreeNode("2", nullptr, nullptr);
    nodes[29] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[33], nodes[32]);
    nodes[28] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[31], nodes[30]);
    nodes[27] = new CharacterTreeNode("1", nullptr, nullptr);
    nodes[26] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[28], nodes[27]);
    nodes[25] = new CharacterTreeNode("14", nullptr, nullptr);
    nodes[24] = new CharacterTreeNode("13", nullptr, nullptr);
    nodes[23] = new CharacterTreeNode("Ваш персонаж крупный?", nodes[25], nodes[24]);
    nodes[22] = new CharacterTreeNode("17", nullptr, nullptr);
    nodes[21] = new CharacterTreeNode("Ваш персонаж увлекается астрономией?", nodes[29], nodes[26]);
    nodes[20] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[23], nodes[22]);
    nodes[19] = new CharacterTreeNode("Ваш персонаж умеет колдовать?", nodes[21], nodes[20]);
    nodes[18] = new CharacterTreeNode("Ваш персонаж дружит с драконами?", nodes[36], nodes[19]);
    nodes[17] = new CharacterTreeNode("22", nullptr, nullptr);
    nodes[16] = new CharacterTreeNode("21", nullptr, nullptr);
    nodes[15] = new CharacterTreeNode("20", nullptr, nullptr);
    nodes[14] = new CharacterTreeNode("19", nullptr, nullptr);
    nodes[13] = new CharacterTreeNode("Ваш персонаж имеет крепкое телосложение?", nodes[17], nodes[16]);
    nodes[12] = new CharacterTreeNode("Ваш персонаж мускулистый?", nodes[15], nodes[14]);
    nodes[11] = new CharacterTreeNode("26", nullptr, nullptr);
    nodes[10] = new CharacterTreeNode("25", nullptr, nullptr);
    nodes[9] = new CharacterTreeNode("24", nullptr, nullptr);
    nodes[8] = new CharacterTreeNode("23", nullptr, nullptr);
    nodes[7] = new CharacterTreeNode("Ваш персонаж болтлив?", nodes[13], nodes[11]);
    nodes[6] = new CharacterTreeNode("Ваш персонаж любит спорить?", nodes[12], nodes[10]);
    nodes[5] = new CharacterTreeNode("Ваш персонаж крупный?", nodes[9], nodes[8]);
    nodes[4] = new CharacterTreeNode("27", nullptr, nullptr);
    nodes[3] = new CharacterTreeNode("Ваш персонаж увлекается наукой?", nodes[7], nodes[6]);
    nodes[2] = new CharacterTreeNode("Ваш персонаж любит поговорить?", nodes[5], nodes[4]);
    nodes[1] = new CharacterTreeNode("Ваш персонаж обладает магическими способностями?", nodes[3], nodes[2]);
    nodes[0] = new CharacterTreeNode("Ваш персонаж - фантастическое существо?", nodes[1], nodes[18]);
    _root = nodes[0];
}