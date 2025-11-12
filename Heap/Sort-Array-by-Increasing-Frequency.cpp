#include <iostream>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {

        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    }
    vector<int> frequencySort(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        unordered_map<int, int> mpp;
        vector<pair<int, int>> v;

        for (int num : nums)
        {
            mpp[num]++;
        }

        for (auto &val : mpp)
        {
            v.push_back({val.second, val.first});
        }

        sort(v.begin(), v.end(), cmp);
        int index = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].first; j++)
            {
                ans[index] = v[i].second;
                index++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 1, 3, 2};
    cout << "Sort Array by Increasing Frequency : " << endl;
    vector<int> ans = s.frequencySort(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}