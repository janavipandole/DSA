#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int sumSubarrayMinsBrute(vector<int> &nums)
    {
        int value = (int)(1e9 + 7);
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int minVal = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                minVal = min(minVal, nums[j]);
                total += minVal % value;
            }
        }
        return total;
    }

    vector<int> NSE(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }

            ans[i] = s.empty() ? n : s.top();

            s.push(i);
        }

        return ans;
    }

    vector<int> PSE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }
        return ans;
    }
    int sumSubarrayMinsOptimal(vector<int> &nums)
    {
        int value = (int)(1e9 + 7);
        int total = 0;
        vector<int> NE = NSE(nums);
        vector<int> PE = PSE(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            int elemRight = NE[i] - i;
            int elemLeft = i - PE[i];

            total = (total + (elemRight * elemLeft * 1LL * nums[i])) % value;
        }
        return total;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {11, 81, 94, 43, 3};
    cout << "Sum of Subarray Minimums : " << s.sumSubarrayMinsOptimal(nums) << endl;
    return 0;
}