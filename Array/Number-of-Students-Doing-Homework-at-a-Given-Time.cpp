#include <iostream>
using namespace std;
class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int count = 0;
        int n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> startTime = {1, 2, 3}, endTime = {3, 2, 7};
    int queryTime = 4;
    cout << "Number of Students Doing Homework at a Given Time : " << s.busyStudent(startTime, endTime, queryTime) << endl;
    return 0;
}