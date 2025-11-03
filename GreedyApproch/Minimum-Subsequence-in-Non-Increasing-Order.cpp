#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        vector<int> ans;
        int newSum = 0;
        sort(nums.rbegin(), nums.rend());

        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum >= newSum)
            {
                newSum += nums[i];
                sum -= nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 3, 10, 9, 8};
    cout << "Minimum Subsequence in Non-Increasing Order : " << endl;
    vector<int> ans = s.minSubsequence(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}