#include <iostream>
using namespace std;
int bs(int* A, const int x, const int n)
{
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(A[mid] == x) return mid;
        if(x > A[mid]) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int bsr(int* A, const int x, const int left, const int right)
{   
    // if(left > right) return -1;
    int middle = (left+right)/2;
    while(left <= right){
        if(x > A[middle]) return bsr(A, x, middle,right);
        else if(x < A[middle]) return bsr(A, x, left, middle);
        else return middle;
    }
    return -1;
}

int main()
{
    int A[10];
    for(int i = 0; i < 10; i ++)
        A[i] = 10+i;

    cout << bs(A,0,10) << endl;
    cout << bs(A,15,10) << endl;
    cout << bsr(A,15,0,9) << endl;
    return 0;
}