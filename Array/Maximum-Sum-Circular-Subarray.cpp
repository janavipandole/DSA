#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = 0;

        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;

        for (int num : nums)
        {

            total += num;

            curMax += num;
            maxSum = max(maxSum, curMax);
            if (curMax < 0) curMax = 0;

            curMin += num;
            minSum = min(minSum, curMin);
            if (curMin > 0) curMin = 0;
        }

        if (maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, -3, 5};
    cout << "Maximum Sum Circular Subarray : "<<s.maxSubarraySumCircular(nums) << endl;
    return 0;
}