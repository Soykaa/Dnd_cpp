#ifndef CHARACTER_TREE_H_INCLUDED
#define CHARACTER_TREE_H_INCLUDED

#include <iostream>
#include <string>
#include <iosfwd>
#include "include/character.h"

class CharacterTreeNode {
public:
    CharacterTreeNode(std::string qst, CharacterTreeNode* right, CharacterTreeNode* left, int ans);
    std::string getQst() const;
    int getAns() const;
    CharacterTreeNode* getLeftNode() const;
    CharacterTreeNode* getRightNode() const;
    void deleteCharacterTreeNode();
private:
    std::string _qst;
    CharacterTreeNode* _right;
    CharacterTreeNode* _left;
    int _ans;
};

class CharacterTree {
public:
    CharacterTree();
    ~CharacterTree();
    CharacterTree(const CharacterTree&) = default;
    CharacterTree& operator=(CharacterTree) = delete;
    CharacterTreeNode* getCharacterTreeRoot() const;
    void buildTree();
    static void generateChar(Hero* h, CharacterTreeNode* n);

private:
    CharacterTreeNode* _root;
};

#endif
