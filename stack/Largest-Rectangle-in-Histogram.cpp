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
    int largestRectangleArea(vector<int> &nums)
    {
        int maxArea = 0;
        vector<int> left = PSE(nums);
        vector<int> right = NSE(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            int Area = (right[i] - left[i] - 1) * nums[i];
            maxArea = max(maxArea, Area);
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle in Histogram : " << s.largestRectangleArea(nums) << endl;
    return 0;
}