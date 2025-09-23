#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void NGE(int n, vector<int> &nums)
{
    stack<int> s;
    vector<pair<int, int>> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = {nums[i], -1};
        }
        else
        {
            ans[i] = {nums[i], s.top()};
        }

        s.push(nums[i]);
    }

    for (auto &val : ans)
    {
        cout << val.first << " " << val.second << endl;
    }
}
int main()
{
    cout<<"Next Greater Element : "<<endl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }
    NGE(n, nums);
    return 0;
}