#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeBrute(vector<vector<int>> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int st = nums[i][0];
            int end = nums[i][1];
            if (!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j][0] <= end)
                {
                    end = max(end, nums[j][1]);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({st, end});
        }

        return ans;
    }

    vector<vector<int>> mergeBetter(vector<vector<int>> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int st = nums[i][0];
            int end = nums[i][1];
            if (!ans.empty() && end <= ans.back()[1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j][0] <= end)
                {
                    end = max(end, nums[j][1]);
                }
                else
                {
                    i = j - 1; // Skip to the next non-overlapping interval
                    break;
                }
            }
            ans.push_back({st, end});
        }

        return ans;
    }
    vector<vector<int>> mergeOptimal(vector<vector<int>> &nums)
    {
        if (nums.empty())
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (ans.empty() || nums[i][0] > ans.back()[1])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }
            // No need to check for the end condition, as we always merge overlapping intervals
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums = {{1, 3}, {2, 4}, {8, 16}, {17, 18}, {2, 6}};
    vector<vector<int>> merged = s.mergeOptimal(nums);
    cout << "{";
    for (auto nums : merged)
    {
        cout << "(";
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << ")" << endl;
    }
    cout << "}";
    cout << endl;
    return 0;
}