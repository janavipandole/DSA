#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> prevSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << "Previous Smaller Element : " << endl;
    vector<int> nums = {1, 6, 2};
    vector<int> ans = s.prevSmaller(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}