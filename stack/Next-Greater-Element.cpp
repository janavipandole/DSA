#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> NGE(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums[i] && s.top() != -1)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(nums[i]);
    }

    return ans;
}
int main()
{
    cout << "Next Greater Element : " << endl;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = NGE(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}