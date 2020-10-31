#include <iostream>
// focus of constructing tree by input array
class BinaryTree;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    char data;
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),data('x'){};
    TreeNode(char s):leftchild(0),rightchild(0),parent(0),data(s){};

    friend class BinaryTree;
};

class BinaryTree{
private:
    TreeNode *root;
public:
    BinaryTree():root(0){};
    BinaryTree(const char* str);

    void LevelorderConstruct(std::stringstream &ss);
    void InsertLevelorder(char data);

    TreeNode* leftmost(TreeNode *current);
    TreeNode* InorderSuccessor(TreeNode *current);
    void Inorder_by_parent();
};
