#include <iostream>
using namespace std;
class Solution
{
public:
// Brute force solution
vector<int> getFinalStateBrute(vector<int> &nums, int k, int multiplier)
{
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = nums[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int minOfAns = INT_MAX;
        int index = -1;
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j] < minOfAns)
            {
                minOfAns = ans[j];
                index = j;
            }
        }
        ans[index] *= multiplier;
    }
    return ans;
}
// Optimal solution
vector<int> getFinalStateOptimal(vector<int> &nums, int k, int multiplier)
{
    for (int i = 0; i < k; i++)
    {
        int index = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < nums[index])
            {
                index = j;
            }
        }
        nums[index] *= multiplier;
    }
    return nums;
}
};
int main()
{
    Solution s;
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5, multiplier = 2;
    vector<int> ans = s.getFinalStateOptimal(nums, k, multiplier);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}