// implement stack by array
#include <iostream>
using namespace std;
class StackArray{
private:
    int top;                 // index of top element
    int capacity;            // allocated memory space of array
    int *stack;              // array representing stack
    void DoubleCapacity();   // double the capacity of stack
public:
    StackArray():top(-1),capacity(1){    // constructor
        stack = new int[capacity];       // initial state: top=-1, capacity=1
    }
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void StackArray::DoubleCapacity(){
    capacity *= 2;
    // create a new stack with new capacity
    int *newstack = new int[capacity];
    for(int i = 0; i < capacity; i ++)
        newstack[i] = stack[i];
    delete []stack;
    stack = newstack;
}
void StackArray::Push(int x){
    // check capacity
    if(top == capacity-1)
        DoubleCapacity();
    // put into stack
    // add the top index and put element into that place
    stack[++top] = x;
}
void StackArray::Pop(){
    if(IsEmpty()){
       cout << "stack is empty\n";
       return; 
    }
    top --;
}
bool StackArray::IsEmpty(){
    // if top == -1, means the stack is empty
    return (top == -1);
}
int StackArray::Top(){
    if(IsEmpty()){
       cout << "stack is empty\n";
       return -1; 
    }
    return stack[top];
}
int StackArray::getSize(){
    // +1 cause the "top" is the id of array, which starts from 0 
    return top+1;
}

int main()
{
    StackArray s;
    s.Pop();
    s.Push(14);
    s.Push(9);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Push(7);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    s.Pop();
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl; 
    s.Pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.getSize() << std::endl;
    return 0;
}
