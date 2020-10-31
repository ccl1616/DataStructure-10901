#include <iostream>
#include <queue>
using namespace std;

// C++ code
/* 
    4 orders traversals
    destructor
    threaded implementation
*/
class Tree;
class TreeNode{
    public:
        TreeNode *left;   // 以下表示每一個node有四個pointer指向child
        TreeNode *right;
        TreeNode *parent;   // good for back-tracking implementation
        int data;             // node所攜帶的information
        bool leftthread;
        bool rightthread;
        TreeNode(int input) : left(0),right(0),data(input){};    // constructor
    friend class Tree;     // 讓class Tree能夠存取TreeNode的private data
};
class BinaryTree{
public:
    TreeNode *root;         // 以root作為存取整棵樹的起點
    BinaryTree():root(0){};
    BinaryTree(TreeNode *node):root(node){};
    void Preorder(TreeNode *current);
    void Inorder(TreeNode *current);
    void Postorder(TreeNode *current);
    void Levelorder();
    ~BinaryTree();
};

void BinaryTree::Preorder(TreeNode *current)
{
    if(current){
        cout << current->data << endl;
        Preorder(current->left);
        Preorder(current->right);
    }
}
void BinaryTree::Inorder(TreeNode *current)
{
    if(current){
        Inorder(current->left);
        cout << current->data << endl;
        Inorder(current->right);
    }
}
void BinaryTree::Postorder(TreeNode *current)
{
    if(current){
        Postorder(current->left);
        Postorder(current->right);
        cout << current->data << endl;
    }
}
void BinaryTree::Levelorder()
{
    
    std::queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* cur = q.front();
        cout << cur->data << endl;
        q.pop();
        if(cur->left!= NULL)
            q.push(cur->left);
        if(cur->right!= NULL)
            q.push(cur->right);
    }
}

void destroynode(TreeNode *cur){
    if(cur == NULL) {
        cout << "impossible case\n";
        return;
    }
    if(cur->left == NULL && cur->right == NULL){
        cout << cur->data << endl;
        delete cur;
    }
    else if(cur->left != NULL && cur->right != NULL){
        destroynode(cur->left);
        destroynode(cur->right);
        delete cur;
    }
    else if(cur->left != NULL){
        destroynode(cur->left);
        delete cur;
    }
    else if(cur->right != NULL){
        destroynode(cur->right);
        delete cur;
    }
    return;
}

BinaryTree::~BinaryTree(){
    destroynode(root);
}

/*
T* ThreadInorderIterator::Next()
{
    node *temp = cur->right
    if(!cur->rightthread)
        while(!temp->leftthread) temp = temp->left
    cur = temp;
    if(cur == root) return 0
    else return &cur->data
}

another function is about insertion
(skip)

*/

int main()
{
    TreeNode *a = new TreeNode(1);
    BinaryTree T(a);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    cout << "inorder:\n";
    T.Inorder(T.root);
    cout << "end of inorder\n";

    cout << "preorder:\n";
    T.Preorder(T.root);
    cout << "end of preorder\n";

    cout << "postorder:\n";
    T.Postorder(T.root);
    cout << "end of Postorder\n";

    cout << "levelorder:\n";
    T.Levelorder();
    cout << "end of Levelorder\n";

    cout << "destruct auto\n";
    //T.~BinaryTree(); the destructor would called automatically by system!
    return 0;
}