#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

// to-do
class A{ 
    private:
        int add;
    public:
        // A(val) would call this and this is constructor
        A(int val){
            cout << "initialize\n";
            add = val;
        }

        // this function is write for for_each function
        void operator()(int ori){
            cout << "operator overload\n";
            cout << ori+add << " " << endl;
        }

}; 
int main() 
{ 
    std::vector<int> v = { 1, 2, 3, 4, 5 }; 
    int val = 10; 
    for_each(v.begin(), v.end(), A(val)); // 11 12 13 14 15 
    return 0;
}
