#ifndef CHARACTER_TREE_H_INCLUDED
#define CHARACTER_TREE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <iosfwd>

class CharacterTreeNode {
public:
    CharacterTreeNode(std::string qst, CharacterTreeNode* right, CharacterTreeNode* left);
    std::string getQst() const;
    CharacterTreeNode* getLeftNode() const;
    CharacterTreeNode* getRightNode() const;
    void deleteCharacterTreeNode();
private:
    std::string _qst;
    CharacterTreeNode* _left;
    CharacterTreeNode* _right;
};

class CharacterTree {
public:
    CharacterTree();
    ~CharacterTree();
    CharacterTree(const CharacterTree&) = default;
    CharacterTree& operator=(CharacterTree) = delete;
    CharacterTreeNode* getCharacterTreeRoot() const;
    void buildTree();
private:
    CharacterTreeNode* _root;
};

#endif
