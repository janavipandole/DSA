#include <iostream>
using namespace std;
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxSum = 0, i = 0, n = nums.size();

        while (i < n / 2)
        {
            maxSum = max(maxSum, nums[i] + nums[n - i - 1]);
            i++;
        }
        return maxSum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 5, 4, 2, 4, 6};
    cout << "Minimize Maximum Pair Sum in Array : " << s.minPairSum(nums) << endl;
    return 0;
}