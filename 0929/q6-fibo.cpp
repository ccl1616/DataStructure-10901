#include <iostream>
using namespace std;

int fibo(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else {
		int ans = 0;
		int pp = 1;
		int p = 1;
		for( int i=3; i <= n; i ++){
			ans = pp + p;
			pp = p;
			p = ans;
		}
		return ans;
    }
}

int fibor(int n)
{
    if(n == 1) return 1;
    else if(n == 2) return 1;
    else{
        return fibor(n-1)+fibo(n-2);
    }
}

int main()
{
    cout << fibor(1) << endl;
    cout << fibor(2) << endl;
    cout << fibor(3) << endl;
    cout << fibor(4) << endl;
    cout << fibor(5) << endl;
    return 0;
}