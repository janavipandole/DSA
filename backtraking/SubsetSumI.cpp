#include <iostream>
using namespace std;

// void SubsetSumI(vector<int> &nums, int index, vector<int> &ds, vector<int> &ans)
// {
//     if (index == nums.size())
//     {
//         int sum = 0;
//         for (auto val : ds)
//         {
//             sum += val;
//         }
//         ans.push_back(sum);
//         return;
//     }

//     ds.push_back(nums[index]);
//     SubsetSumI(nums, index + 1, ds, ans);

//     ds.pop_back();
//     SubsetSumI(nums, index + 1, ds, ans);
// }

void SubsetSumI(vector<int> &nums, int index, int sum, vector<int> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(sum);
        return;
    }

    SubsetSumI(nums, index + 1, sum + nums[index], ans);

    SubsetSumI(nums, index + 1, sum, ans);
}
int main()
{
    vector<int> nums = {1, 2, 1};
    // vector<int> ds;
    vector<int> ans;

    // SubsetSumI(nums, 0, ds, ans);

    SubsetSumI(nums, 0 , 0 , ans);

    for (auto num : ans)
    {
        cout << num<<" ";
    }
    cout << endl;

    return 0;
}