#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        if (nums.size() < 3)
            return -1;

        int minDist = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        for (auto val : mp)
        {
            if (val.second.size() < 3)
                continue;
            auto indices = val.second;
            if (val.second.size() >= 3)
            {
                for (int i = 0; i + 2 < indices.size(); i++)
                {
                    int a = indices[i], b = indices[i + 1], c = indices[i + 2];
                    int dist = abs(a - b) + abs(b - c) + abs(c - a);
                    minDist = min(minDist, dist);
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 3, 5, 5, 5};
    cout << "Minimum Distance Between Three Equal Elements I and II : " << s.minimumDistance(nums) << endl;
    return 0;
}