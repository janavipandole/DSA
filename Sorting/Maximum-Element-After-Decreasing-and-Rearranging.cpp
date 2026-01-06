#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        nums[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = min(nums[i], nums[i - 1] + 1);
        }
        return nums[nums.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {100, 1, 1000};
    cout << "Maximum Element After Decreasing and Rearranging : " << s.maximumElementAfterDecrementingAndRearranging(nums) << endl;
    return 0;
}