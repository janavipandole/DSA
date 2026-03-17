#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= nums[i])
                st.pop();

            if (!st.empty())
            {
                ans[i] = st.size();
            }

            st.push(nums[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 0, 1};
    cout << "Count of Smaller Numbers After Self : " << endl;
    vector<int> ans = s.countSmaller(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}