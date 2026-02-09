#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        vector<long long> ans;
        stack<long long> st;
        for (int i = 0; i < nums.size(); i++)
        {
            long long current = nums[i];
            while (!st.empty() && st.top() == current)
            {
                current = current + st.top();
                st.pop();
            }

            st.push(current);
        }
        while (st.size() > 0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 1, 1, 2};

    cout << "Merge Adjacent Equal Elements : " << endl;

    vector<long long> ans = s.mergeAdjacent(nums);

    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
