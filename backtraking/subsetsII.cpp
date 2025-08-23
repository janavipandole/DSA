#include <iostream>
using namespace std;

// BETTER Solution

// void getAllSubset(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &result)
// {
//     if (i == nums.size())
//     {
//         result.push_back({ans});
//         return;
//     }
//     ans.push_back(nums[i]);
//     getAllSubset(nums, ans, i + 1, result);
//     ans.pop_back();
//     int index = i + 1;
//     while (index < nums.size() && nums[index] == nums[index - 1])
//     {
//         index++;
//     }
//     getAllSubset(nums, ans, index + 1, result);
// }
// vector<vector<int>> subsetsWithDup(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> result;
//     vector<int> ans;
//     getAllSubset(nums, ans, 0, result);
//     return result;
// }

void subSetsIIOptimal(vector<int> &nums,
                      int index, vector<int> &ds,
                      vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }
        ds.push_back(nums[i]);
        ans.push_back(ds);
        subSetsIIOptimal(nums, i + 1, ds, ans);
        ds.pop_back();
    }
}
int main()
{
    vector<int> nums = {1, 2, 2};
    vector<int> ds;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    ans.push_back(ds);
    subSetsIIOptimal(nums, 0, ds, ans);

    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}