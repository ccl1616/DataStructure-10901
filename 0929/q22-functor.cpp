#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

// to-do
class A{ 
    private:
        int add;
    public:
        A(int val){
            cout << "initialize\n";
            add = val;
        }
        void operator()(int ori){
            cout << "operator overload\n";
            cout << ori+add << " ";
        }

}; 
int main() 
{ 
    std::vector<int> v = { 1, 2, 3, 4, 5 }; 
    int val = 10; 
    for_each(v.begin(), v.end(), A(val)); // 11 12 13 14 15 
    return 0;
}
