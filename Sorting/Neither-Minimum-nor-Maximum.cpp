#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        if (nums.size() < 3)
            return -1;

        sort(nums.begin(), nums.end());

        return nums[1];
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1, 4};
    cout << "Neither Minimum nor Maximum : " << s.findNonMinOrMax(nums) << endl;

    return 0;
}