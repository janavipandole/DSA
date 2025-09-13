#include <iostream>
using namespace std;
vector<int> addOne(vector<int> &nums)
{
    vector<int> ans;
    int carry = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        carry += nums[i];
        ans.push_back((carry) % 10);
        carry /= 10;
    }
    if (carry)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> nums = {9, 9, 9, 9};
    vector<int> ans = addOne(nums);
    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}