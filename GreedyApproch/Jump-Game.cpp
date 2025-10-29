#include <iostream>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxReach = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << "Jump Game : " << s.canJump(nums) << endl;
    return 0;
}