#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int a = nums[nums.size() - 1];
        int b = nums[nums.size() - 2];

        int c = nums[0];
        int d = nums[1];

        return (a * b) - (c * d);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {5, 6, 2, 7, 4};
    cout << "Maximum Product Difference Between Two Pairs : " << s.maxProductDifference(nums) << endl;

    return 0;
}