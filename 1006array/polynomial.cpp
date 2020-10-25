#include <iostream>
#define Maxdegree 10
/*
class Polynomial
{ 
    public:
        // Construct p(x) = 0
        Polynomial(void);
        // Return the sum of *this and poly
        Polynomial Add(Polynomial poly);
        // Return multiplication of *this and poly
        Polynomial Mult(Polynomial poly);
        // Return the evaluation result
        float Eval(float x ); private:
        // Array representation
        void NewTerm(float t, int exp){
            coef[exp] = t;
        }

    private:
        int degree;
        float coef[Maxdegree+1];
};*/

class Term {
    public: 
        friend Polynomial;
        float coef;
        int exp;
};

// store on;y nonzero terms
// version 2 of polynomial ADT
class Polynomial
{ 
    public:
        // Construct p(x) = 0
        Polynomial(void);
        // Return the sum of *this and poly
        Polynomial Add(Polynomial poly);
        // Return multiplication of *this and poly
        Polynomial Mult(Polynomial poly);
        // Return the evaluation result
        float Eval(float x ); private:
        // Array representation
        void NewTerm(float t, int exp){
            termArray[exp].coef = t;
            termArray[exp].exp = exp;
        }

    private:
        Term* termArray;
        int capacity; //size of termarray
        int terms; //# of nonzero terms
};

Polynomial Polynomial::Add(Polynomial b)
{
    Polynomial c;
    int aPos = 0, bPos = 0;
    while( (aPos<terms) && (bPos<b.terms) ){
        if(termArray[aPos].exp == b.termArray[bPos].exp){
            float t = termArray[aPos].coef + b.termArray[bPos].coef; 
            if(t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; 
            bPos++;
        }
        else if(termArray[aPos].exp < b.termArray[bPos].exp){
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++; 
        }
        else{ 
            c.NewTerm(termArray[aPos].coef,termArray[aPos].exp); 
            aPos++;
        }
    }
    for(; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp); // add in remaining terms of b
    for(; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}