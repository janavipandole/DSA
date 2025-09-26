#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> addOne(vector<int> &nums)
    {
        vector<int> ans;
        int carry = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            carry += nums[i];
            ans.push_back((carry) % 10);
            carry /= 10;
        }
        if (carry)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {9, 9, 9, 9};
    vector<int> ans = s.addOne(nums);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}