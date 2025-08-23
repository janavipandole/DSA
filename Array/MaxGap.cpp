#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxGap(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxi = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i] - nums[i - 1]);
    }
    return maxi;
}

vector<int> findArray(vector<int> &nums)
{
    int xor1 = 0;
    vector<int> ans;
    for (auto num : nums)
    {
        if (ans.size() == 0)
        {
            ans.push_back(xor1 ^ num);
        }
        else
        {
            xor1 = xor1 ^ ans.back();
            ans.push_back(xor1 ^ num);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 2, 0, 3, 1};
    // cout << "max Gap : " << maxGap(nums) << endl;

    vector<int> ans = findArray(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}