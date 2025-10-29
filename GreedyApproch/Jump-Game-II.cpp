#include <iostream>
using namespace std;
class Solution
{
public:
    // This solution gives a TLE (Time Limit Exceeded).
    // The optimal solution uses Dynamic Programming (DP),
    // so we'll solve the optimal version later after we understand the DP logic.

    int game(int index, vector<int> &nums, int j)
    {
        if (index >= nums.size() - 1) return j;

        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++)
        {
            mini = min(mini, game(index + i, nums, j + 1));
        }
        return mini;
    }
    int jump(vector<int> &nums)
    {
        int cnt = game(0, nums, 0);
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Jump Game II : " << s.jump(nums) << endl;
    return 0;
}