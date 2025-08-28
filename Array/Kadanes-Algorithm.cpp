#include <iostream>
using namespace std;
int maxSubarraySum(vector<int> &nums)
{
    int sum = INT_MIN;
    int currentSum = 0;
    for (auto num : nums)
    {
        currentSum += num;
        sum = max(sum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return sum;
}
int main()
{
    vector<int> nums = {2, 3, -8, 7, -1, 2, 3};
    cout << "max Subarray Sum : " << maxSubarraySum(nums) << endl;
    return 0;
}