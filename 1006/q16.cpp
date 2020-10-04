#include <iostream>
using namespace std;

void foo(int a[]) {
    a[0] += 1;
    a[1] += 2;
    a[2] += 3;
}
int main() {
/*
    int a[] = {1, 2, 3};
    cout << a[0] << a[1] << a[2] << endl;
    foo(a);
    cout << a[0] << a[1] << a[2] << endl;
*/
    int ar[41][51];
    cout << ar << endl;
    cout << ar[40][50] << endl;
    return 0;
}
