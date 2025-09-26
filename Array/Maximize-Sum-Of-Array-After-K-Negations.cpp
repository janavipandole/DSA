#include <iostream>
using namespace std;
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < k; i++)
        {
            nums[0] *= -1;
            sort(nums.begin(), nums.end());
        }
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, -1, 0, 2};
    int k = 3;
    cout << "Maximize Sum Of Array After K Negations : " << s.largestSumAfterKNegations(nums, 1) << endl;
    return 0;
}