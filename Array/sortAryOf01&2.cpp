#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void sortAry(vector<int> &nums)
    {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                cnt0++;
            }
            else if (nums[i] == 1)
            {
                cnt1++;
            }
        }
        for (int i = 0; i < cnt0; i++)
        {
            nums[i] = 0;
        }
        for (int i = cnt0; i < cnt0 + cnt1; i++)
        {
            nums[i] = 1;
        }
        for (int i = cnt0 + cnt1; i < nums.size(); i++)
        {
            nums[i] = 2;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    s.sortAry(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}