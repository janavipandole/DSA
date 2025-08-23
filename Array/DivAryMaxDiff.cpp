#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i += 3)
    {
        if (nums[i + 2] - nums[i] > k)
            return {};
        ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    return ans;
}

bool isValidGroup(vector<int> &group, int k)
{
    int maxVal = *max_element(group.begin(), group.end());
    int minVal = *min_element(group.begin(), group.end());
    return maxVal - minVal <= k;
}
//(nums, used, k, result, 0, n / 3);
bool backtrack(vector<int> &nums, vector<bool> &used, int k, vector<vector<int>> &result, int groupsFormed, int totalGroups)
{
    if (groupsFormed == totalGroups) return true;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (used[i]) continue;

        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (used[j]) continue;

            for (int l = j + 1; l < nums.size(); ++l)
            {
                if (used[l]) continue;

                vector<int> group = {nums[i], nums[j], nums[l]};
                if (isValidGroup(group, k))
                {
                    used[i] = used[j] = used[l] = true;
                    result.push_back(group);

                    if (backtrack(nums, used, k, result, groupsFormed + 1, totalGroups)) return true;

                    // backtrack
                    used[i] = used[j] = used[l] = false;
                    result.pop_back();
                }
            }
        }
    }

    return false;
}

vector<vector<int>> divideArrayBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n % 3 != 0)
        return {};

    vector<bool> used(n, false);
    vector<vector<int>> result;

    if (backtrack(nums, used, k, result, 0, n / 3))
    {
        return result;
    }
    return {};
}

int main()
{
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    vector<vector<int>> ans = divideArrayBrute(nums, k);
    for (auto num : ans)
    {
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}