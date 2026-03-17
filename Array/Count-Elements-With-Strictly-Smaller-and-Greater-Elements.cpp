#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool equal(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1]) return false;
        }
        return true;
    }
    int countElements(vector<int> &nums)
    {
        if (equal(nums)) return 0;

        int n = nums.size();
        int countMin = 0;
        int countMax = 0;
        int Min = INT_MAX, Max = INT_MIN;
        for (auto num : nums)
        {
            Min = min(Min, num);
            Max = max(Max, num);
        }
        for (auto num : nums)
        {
            if (Min == num) countMin++;

            if (Max == num) countMax++;
        }
        return n - countMin - countMax;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {8, 8, 8, 8, 2, 4, 4, 2, 4};
    cout << "Count Elements With Strictly Smaller and Greater Elements : " << s.countElements(nums) << endl;
    return 0;
}