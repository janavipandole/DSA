#include <iostream>
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &nums)
    {
        if (nums.size() != target.size())
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        int n = target.size();

        for (int i = 0; i < n; i++)
        {
            if (target[i] != nums[i]) return false;
        }

        return true;
    }
};
int main()
{
    Solution s;
    vector<int> target = {1, 2, 3, 4}, nums = {2, 4, 1, 3};
    cout << "Make Two Arrays Equal by Reversing Subarrays : " << s.canBeEqual(target, nums) << endl;

    return 0;
}