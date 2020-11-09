#include <iostream>
#include <algorithm>    
#include <vector>       
#include <stdlib.h>
#include <time.h>

#define employee_number 10
#define hourlyRate_max 100
#define time_max 100
using namespace std;

class employee{
	private:
		int index;      //員工編號 
		int time;      //工作時間 
		int hourlyRate; //時薪
	public:
		employee():index(0),time(0),hourlyRate(0){}
		employee(int index,int time,int hourlyRate):index(index),time(time),hourlyRate(hourlyRate){}
		int getSalary(){
			return time*hourlyRate*0.95; 
		}
		int getIndex(){
			return this->index;
		}
};

// to-do
bool salaryComparison(employee lhs, employee rhs)
{
    return lhs.getSalary() < rhs.getSalary();
};


int main () {
	 srand((int)time(NULL));
	 
     vector<employee> Microsoft;
     for( int i=0 ; i<employee_number ; i++ ){
     	Microsoft.push_back(employee(i,rand()%time_max,rand()%hourlyRate_max));
	 }
	 
	 cout<<"列出所有員工的薪水"<<endl;
	 for( vector<employee>::iterator it=Microsoft.begin(); it!=Microsoft.end() ; ++it ){
	 	cout<<"員工編號: "<<it->getIndex()<<" ; 薪水: "<<it->getSalary() <<endl ;
	 }
	 cout<<endl;

	 
     cout<<"將員工薪水做排序"<<endl;
     sort (Microsoft.begin(), Microsoft.end(), salaryComparison ); 
     for( vector<employee>::iterator it=Microsoft.begin(); it!=Microsoft.end() ; ++it ){
	 	cout<<"員工編號: "<<it->getIndex()<<" ; 薪水: "<<it->getSalary() <<endl ;
	 }
	 cout<<endl;
     
     return 0;
}
