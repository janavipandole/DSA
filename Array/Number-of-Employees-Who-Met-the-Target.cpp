#include <iostream>
using namespace std;
int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
{
    int metTarget = 0;
    for(auto hour : hours){
        if(hour >= target) metTarget++;
    }
    return metTarget;
}
int main()
{
    vector<int> hours = {0,1,2,3,4};
    int target = 2;
    cout<<"Number of Employees Who Met the Target : "<<numberOfEmployeesWhoMetTarget(hours, target)<<endl;
    return 0;
}