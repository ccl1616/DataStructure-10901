#include <iostream>
class StackNode{
private:
    int data;
    StackNode *next;
public:
    StackNode():data(0){
        next = 0;
    }
    StackNode(int x):data(x){
        next = 0;
    }
    StackNode(int x, StackNode *nextNode):data(x),next(nextNode){};
    friend class StackList;
};

class StackList{
private:
    StackNode *top;     // remember the address of top element 
    int size;           // number of elements in Stack
public:                 
    StackList():size(0),top(0){};
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackList::Push(int x)
{
    if(IsEmpty()){
        top = new StackNode(x);
        size ++;
        return ;
    }
    // 利用constructor 把newnode 接在top 的上面 (newnode->next = top)
    StackNode *newnode = new StackNode(x,top);
    top = newnode;
    size ++;
}
void StackList::Pop()
{
    if(IsEmpty()){
        std::cout << "stack is empty\n";
        return;
    }
    StackNode *del = top;
    top = top ->next;
    delete del;
    del = 0;
    size --;
}
bool StackList::IsEmpty()
{
    return (size == 0);
}
int StackList::Top()
{
    // get the top data
    if(IsEmpty()){
        std::cout << "stack is empty\n";
        return -1;
    }
    return top->data;
}
int StackList::getSize()
{
    return size;
}
int main(){

    StackList s;
    s.Pop();
    s.Push(32);
    s.Push(4);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;        
    s.Push(15);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;         
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;          
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;

    return 0;
}

