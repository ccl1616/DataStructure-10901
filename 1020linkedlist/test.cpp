#include<iostream>
#include <cstdlib>

using namespace std;

typedef struct _node{
    int data;
    struct _node* next; 
}node; 

int main()
{
    node* a = new node;
    node* b = new node;
    node* anext = new node;
    a->data = 10;
    anext->data = 20;
    a->next = anext;
    cout << "hi\n";
    b->data = 0;
    b->next = a;
    cout << a->data << " " << a->next << endl;
    cout << b->data << " " << b->next << endl;
    *b = *a;
    cout << b->data << " " << b->next << endl;
    return 0;
}