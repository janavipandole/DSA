#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        int maximum = nums[n - 1];
        ans.push_back(maximum);
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= maximum)
            {
                ans.push_back(nums[i]);
                maximum = nums[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    cout << "Leaders in an array : " << endl;
    vector<int> ans = s.leaders(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}