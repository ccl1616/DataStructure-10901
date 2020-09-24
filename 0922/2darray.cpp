/*
0922 Q11 Q12
    Q11Write a piece of code to generate a 3x4 2-dimensional array using “new” :
(Dynamic Memory Allocation in C++)
    Q12Write down your code to delete the 2-dimensional array created by using “delete” :
(Dynamic Memory Allocation in C++)
*/

#include <iostream>
using namespace std;
#define rownum 3
#define colnum 4

int main()
{
    // construct array
    int **a;
    a = new int*[rownum];
    for(int i = 0; i < rownum; i ++)
        a[i] = new int[colnum];

    // some test
    a[0][0] = 100;
    cout << a[0][0] << endl;

    // delete array
    for(int i = 0; i < rownum; i ++)
        delete [] a[i];
    delete a;

    return 0;
}