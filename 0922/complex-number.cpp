/* 
0922 Q5
    Implement a class Complex, which represents the Complex Number data type. Implement the following operations
a.	A constructor (including a default constructor which creates the complex number 0+0i)
b.	Overload operator+ to add two complex numbers
c.	Overload operator* to multiply two complex numbers
d.	Overload << and >> to print and read complex numbers. To do this, you will need to decide what you want your input and output format to look like.
Write a program according to the following specifications: use the constructor to define two complex numbers: 3+2i and 0+0i. 
Input two complex numbers 5+3i and 0+0i using cin. 
Obtain the sum and product of all four complex numbers using operators + and *, respectively. 
Output the results using cout.

*/
#include<iostream>
using namespace std;

class Complex{
    public:
        Complex(int a = 0, int b = 0):A(a),B(b){ }
        Complex operator + (Complex rhs){
            Complex ans;
            ans.A = this->A + rhs.A;
            ans.B = this->B + rhs.B;
            return ans;
        }
        Complex operator * (Complex rhs){
            Complex ans;
            ans.A = this->A*rhs.A - this->B*rhs.B;
            ans.B = this->A*rhs.B + this->B*rhs.A;
            return ans;
        }
        Complex& operator = (const Complex rhs){
            this->A = rhs.A;
            this->B = rhs.B;
            return *this;
        }

        int A,B;
};

istream& operator >> (istream &is,Complex &num){
    char plus = '+';
    is >> num.A >> plus >> num.B;
    return is;
}

ostream& operator << (ostream &os,Complex &num){
    os << num.A << '+' << num.B << 'i' << endl;
    return os;
}

int main()
{
    Complex i(3,2);
    Complex j(0,0);
    Complex k;
    cin >> k;
    getchar();
    Complex l;
    cin >> l;
    getchar();

    Complex sum;
    sum = i+j+k+l;
    Complex product;
    product = i*j*k*l;

    cout << sum;
    cout << product;
    return 0;
}