#include <iostream>
#include <set>
#include <math.h>
using namespace std;

void combinationSum(vector<int> &nums, vector<vector<int>> &result, vector<int> &combin, int k, int index)
{
    if (index == nums.size() || k < 0)
        return;

    if (k == 0)
    {
        result.push_back(combin);
        return;
    }

    combin.push_back(nums[index]);
    combinationSum(nums, result, combin, k - nums[index], index);

    combin.pop_back();
    combinationSum(nums, result, combin, k, index + 1);
}

void combinationSumIIBruteforce(vector<int> &nums, set<vector<int>> &result, vector<int> &combin, int k, int index)
{
    if (k == 0)
    {
        sort(combin.begin(), combin.end());
        if (result.find(combin) == result.end())
        {
            result.insert(combin);
        }
        return;
    }
    if (index == nums.size() || k < 0)
    {
        return;
    }

    combin.push_back(nums[index]);
    combinationSumIIBruteforce(nums, result, combin, k - nums[index], index + 1);

    combin.pop_back();
    combinationSumIIBruteforce(nums, result, combin, k, index + 1);
}

void combinationSumIIOptimal(vector<int> &nums, vector<vector<int>> &answer, vector<int> &combin, int target, int index)
{
    if (target == 0)
    {
        answer.push_back(combin);
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] > target)
        {
            break;
        }

        combin.push_back(nums[i]);
        combinationSumIIOptimal(nums, answer, combin, target - nums[i], i + 1);

        combin.pop_back();
    }
}
int main()
{
    vector<int> nums = {7, 4, 10, 20, 11, 14, 4, 7, 2, 6, 11, 5, 20, 17, 13, 20, 13};
    int k = 16;

    sort(nums.begin(), nums.end());
    vector<int> combin;
    vector<vector<int>> answer;

    combinationSumIIOptimal(nums, answer, combin, k, 0);

    for (auto num : answer)
    {
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}