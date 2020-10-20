#include <iostream>

class Term{
    friend class Polynomial;
    private:
        float coef;  //coefficient
        int exp;    //exponent
    public:
        Term():coef(0),exp(0){}
        Term(float coef, int exp):coef(coef),exp(exp){}
};

class Polynomial{
    private:
        Term *termArray;
        int capacity;  // capacity is the size of termArray
        int terms;    // terms is the number of elements
    public:
        Polynomial(int coefficient[], int size){
            // TODO
            termArray = new Term[size];
            for(int i = size-1; i >= 0; i --)
                termArray[i] = Term(coefficient[i],i);
        }
};

int main(){
    int coefficient[5]={ 2,0,0,4,2};  //This means 2x^4+4x^3+2
    Polynomial poly(coefficient,5);
}
