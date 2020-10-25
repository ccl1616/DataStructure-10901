#include <iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *pre;
        Node *next;
    public:
        // Constructor
        Node():data(0),pre(0),next(0){}
        Node(int data):data(data),pre(0),next(0){}
        Node(int data, Node *pre):data(data),pre(pre),next(0){}
        Node(int data,Node *pre,Node *next):data(data),pre(pre),next(next){}
        // functions
        Node* getPre(){
            return pre; 
        }
        Node* getNext(){
            return next;
        }
        int getData(){
            return data;
        }
        void setData(int data){
            this->data=data;
        }
        void setPre(Node *pre){
            this->pre=pre;
        }
        void setNext(Node *next){
            this->next=next;
        }
};

class DoubleLinkedList{
    private:
        Node *firstNode;
        Node *lastNode;
    public:
        DoubleLinkedList():firstNode(0),lastNode(0){}
        DoubleLinkedList(Node *firstNode):firstNode(firstNode),lastNode(firstNode){}
        void printAll(){
            //TODO : print all the elements in linked list
            Node* temp = firstNode;
            while(temp != lastNode){
                cout << temp->getData() << endl;
                temp = temp->getNext();
            }
            cout << temp->getData() << endl;
        }
        void push_back(Node *node){
            //TODO : push new element in the last of linked list
            Node* newnode = new Node(node->getData() );
            lastNode->setNext(newnode);
            newnode->setPre(lastNode);
            lastNode = newnode;
        }
};
