#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &nums)
    {
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                s.push(nums[i]);
            }
            else
            {
                while (!s.empty() && s.top() > 0 && abs(nums[i]) > s.top())
                {
                    s.pop();
                }
                if (!s.empty() && abs(nums[i]) == s.top()) s.pop();
                else if (s.empty() || s.top() < 0) s.push(nums[i]);
            }
        }
        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0 && !s.empty(); i--)
        {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {10, 5, -5};
    cout << "Asteroid Collision : " << endl;
    vector<int> ans = s.asteroidCollision(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}