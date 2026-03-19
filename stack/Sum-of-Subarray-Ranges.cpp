#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int Min = nums[i];
            int Max = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                Min = min(Min, nums[j]);
                Max = max(Max, nums[j]);

                ans += Max - Min;
            }
        }
        return ans;
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

    vector<int> NLE(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] <= nums[i])
            {
                s.pop();
            }
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> PLE(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i])
            {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();

            s.push(i);
        }
        return ans;
    }
    long long subArrayRangesOptimal(vector<int> &nums)
    {
        long long MaxSum = 0;
        long long MinSum = 0;

        vector<int> NE = NSE(nums);
        vector<int> PE = PSE(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            int elemRight = NE[i] - i;
            int elemLeft = i - PE[i];

            MinSum += (elemRight * elemLeft * 1LL * nums[i]);
        }
        NE = NLE(nums);
        PE = PLE(nums);
        for (int i = 0; i < nums.size(); i++)
        {
            int elemRight = NE[i] - i;
            int elemLeft = i - PE[i];

            MaxSum += (elemRight * elemLeft * 1LL * nums[i]);
        }

        return MaxSum - MinSum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 3};
    cout << "Sum of Subarray Ranges : " << s.subArrayRangesOptimal(nums) << endl;
    return 0;
}