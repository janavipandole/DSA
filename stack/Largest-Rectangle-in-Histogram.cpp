#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
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
            while (!s.empty() && nums[s.top()] >= nums[i])
            {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleAreaBrute(vector<int> &nums)
    {
        int maxArea = 0;
        vector<int> left = PSE(nums);
        vector<int> right = NSE(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            maxArea = max(maxArea, (right[i] - left[i] - 1) * nums[i]);
        }
        return maxArea;
    }

    int largestRectangleAreaOptimal(vector<int> &nums)
    {
        int maxArea = 0;
        int n = nums.size();
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] > nums[i])
            {
                int element = nums[s.top()];
                s.pop();
                int NSE = i;
                int PSE = s.empty() ? -1 : s.top();
                maxArea = max(element * (NSE - PSE - 1), maxArea);
            }
            s.push(i);
        }
        
        while (!s.empty())
        {
            int NSE = n;
            int element = nums[s.top()];
            s.pop();
            int PSE = s.empty() ? -1 : s.top();
            maxArea = max(element * (NSE - PSE - 1), maxArea);
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle in Histogram : " << s.largestRectangleAreaOptimal(nums) << endl;
    return 0;
}