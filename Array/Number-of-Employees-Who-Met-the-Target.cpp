#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int metTarget = 0;
        for (auto hour : hours)
        {
            if (hour >= target)
                metTarget++;
        }
        return metTarget;
    }
};
int main()
{
    Solution s;
    vector<int> hours = {0, 1, 2, 3, 4};
    int target = 2;
    cout << "Number of Employees Who Met the Target : " << s.numberOfEmployeesWhoMetTarget(hours, target) << endl;
    return 0;
}