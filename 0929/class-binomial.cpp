#include <iostream>
using namespace std;

int func(int n, int m)
{
    if(m == 0 || n == m) return 1;
    else return func(n-1, m)+func(n-1,m-1);
}

int main()
{
    cout << "hello\n";
    cout << func(5,3) << endl;
    return 0;
}