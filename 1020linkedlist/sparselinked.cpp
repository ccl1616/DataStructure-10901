#include <iostream>
using namespace std;

struct Triple{ int row,col,val; };
class Matrix;
class MatrixNode{
    friend class Matrix;
    friend istream& operator>>(istream&, Matrix&);
    private:
        MatrixNode *down,*right;
        bool head;
        union {
            MatrixNode *next;
            Triple triple;
        };
        MatrixNode(bool,Triple*); //constructor
};
MatrixNode::MatrixNode(bool b, Triple *t){
    head = b;
    if(b)
        right = down = this;
    else triple = *t;
}
class Matrix{
    friend istream& operator>>(istream&,Matrix&);
    public:
        ~Matrix();
        MatrixNode* getfront();
    private:
        MatrixNode *headnode;
};

istream& operator>>(istream& is, Matrix& matrix){
    Triple s;
    is >> s.row >> s.col >> s.val;
    int p = max(s.row,s.col);
    // construct H
    matrix.headnode = new MatrixNode(false, &s);
    if(p == 0){
        matrix.headnode->right = matrix.headnode;
        return is;
    }

    MatrixNode **head = new MatrixNode *[p];
    for(int i = 0; i < p; i ++)
        head[i] = new MatrixNode(true,0); //Hi with null triple
    int currentRow = 0;
    MatrixNode *last = head[0];
    for(int i = 0; i < s.val; i ++){
        Triple t;
        is >> t.row >> t.col >> t.val;
        if(t.row > currentRow){
            last->right = head[currentRow];
            currentRow = t.row;
            last = head[currentRow];
        }
        last = last->right = new MatrixNode(false,&t);
        head[t.col]->next = head[t.col]->next->down = last;
    }
    last->right = head[currentRow];
    for(int i = 0; i < s.col; i ++)
        head[i]->next->down = head[i];
    for(int i = 0; i < p-1; i ++)
        head[i] ->next = head[i+1];
    head[p-1]->next = matrix.headnode;
    matrix.headnode->right = head[0];
    delete []head;
    return is;
}

Matrix::~Matrix(){
    /*
    回傳所有節點至av串列 串列是由right連結的
    av是指向av串列第一個節點的變數
    */
   MatrixNode *av = getfront();
    if(!headnode) return;
    MatrixNode *x = headnode->right;
    headnode->right = av;
    av = headnode;
    while(x != headnode){
        MatrixNode *y = x->right;
        x->right = av;
        av = y;
        x = x->next;
    }

}