#include <iostream>
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int totalSubArray = (i + 1) * (n - i);

            int oddSubArray = (totalSubArray + 1) / 2;

            totalSum += nums[i] * oddSubArray;
        }

        return totalSum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 4, 2, 5, 3};
    cout << "Sum of All Odd Length Subarrays : " << s.sumOddLengthSubarrays(nums) << endl;
    return 0;
}