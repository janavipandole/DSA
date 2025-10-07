#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int max_Sum(vector<int> &nums, int k)
    {
        int start = 0, end = k - 1, maxSum = INT_MIN, sum = 0;
        for (int i = start; i <= end; i++)  sum += nums[i];
        
        maxSum = max(sum, maxSum);
        while (end < nums.size())
        {
            sum -= nums[start];
            start++;
            end++;
            sum += nums[end];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 2, 3, 3, 4, 5, 1};
    int k = 4;
    cout << "Constant Window : " << s.max_Sum(nums, k) << endl;
    return 0;
}