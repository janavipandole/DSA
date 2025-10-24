#include <iostream>
using namespace std;

void printOneSubSeq(vector<int> &nums, int k, vector<int> &ans, vector<vector<int>> &result, int index)
{

    if (index == nums.size())
    {
        if (k == 0)
        {
            result.push_back(ans);
            return;
        }
        return;
    }

    if (result.size() == 1)
    {
        return;
    }

    ans.push_back(nums[index]);
    printOneSubSeq(nums, k - nums[index], ans, result, index + 1);

    ans.pop_back();
    printOneSubSeq(nums, k, ans, result, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 1};
    int k = 3;

    vector<int> ans;
    vector<vector<int>> result;

    printOneSubSeq(nums, k, ans, result, 0);

    for (auto res : result)
    {
        for (auto num : res)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}