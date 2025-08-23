#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

bool twoSumBrute(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {

            if (nums[i] + nums[j] == k && i != j)
            {
                return true;
            }
        }
    }
    return false;
}
bool twoSumBetter(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            return true;
        }
        else if (nums[i] + nums[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
bool twoSumOptimal(vector<int> &nums, int k)
{
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        int frist = nums[i];
        int second = k - frist;
        if (s.find(second) != s.end())
        {
            return true;
        }
        s.insert(frist);
    }
    return false;
}

vector<int> twoSumBruteIdx(vector<int> &nums, int k)
{
    vector<int> ans(2, -1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == k)
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}
vector<int> twoSumOptimalIdx(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        int f = nums[i];
        int s = k - f;
        if (m.find(s) != m.end())
        {
            return {m[s], i};
        }
        m[f] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 6, 5, 8, 11};
    int k = 14;
    // vector<int> ans = twoSumBruteIdx(nums, k);
    // for (auto num : ans)
    // {
    //     cout << num << " ";
    // }
    cout << "two Sum better : " << twoSumOptimal(nums, k) << endl;
    return 0;
}