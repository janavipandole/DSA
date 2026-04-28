#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    long long minOperations(vector<int> &nums)
    {
        long long maxNum = INT_MIN, minNum = INT_MAX;

        for (auto num : nums)
        {
            if(num > maxNum) maxNum = num;
            
            if(num < minNum) minNum = num;
        }
        return maxNum - minNum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 3, 2, 1};
    cout << "Minimum Operations to Make Array Non Decreasing : " << s.minOperations(nums) << endl;
    return 0;
}