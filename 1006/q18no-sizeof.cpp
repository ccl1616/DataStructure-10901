// #include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
  
int main() 
{ 
    int  arr[] = {1, 2, 3, 4, 5, 6}; 
    int size;
	//TODO
    size = *(&arr +1) -arr;
    cout << "Number of elements in arr[] is "
         << size; 
    return 0; 
} 
