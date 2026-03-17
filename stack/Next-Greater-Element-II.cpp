#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> NGEIIBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        bool isFound = false;

        // right NGE
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                ans[i] = nums[j];
                isFound = true;
                break;
            }
        }

        // isFound is false that mean not found NGE at right search in left part
        if (isFound == false)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] < nums[j])
                {
                    ans[i] = nums[j];
                    isFound = true;
                    break;
                }
            }
        }
    }
    return ans;
}

vector<int> NGEIIBetter(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n + i; j++)
        {
            if (nums[i] < nums[j % n])
            {
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}
vector<int> NGEIIOtimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (!st.empty()) ans[i % n] = st.top();

        st.push(nums[i % n]);
    }
    return ans;
}
int main()
{
    cout << "Next Greater Element II : " << endl;
    vector<int> nums = {1, 2, 1};
    vector<int> ans = NGEIIOtimal(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}