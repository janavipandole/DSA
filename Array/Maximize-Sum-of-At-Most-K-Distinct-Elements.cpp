#include <iostream>
#include <set>
using namespace std;
vector<int> maxKDistinct(vector<int> &nums, int k)
{
    vector<int> ans;
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < nums.size(); i++)
    {
        if (k == 0)
            return ans;

        if (ans.empty() || nums[i] != ans.back())
        {
            ans.push_back(nums[i]);
            k--;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {84, 93, 100, 77, 90};
    int k = 3;
    vector<int> ans = maxKDistinct(nums, k);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}