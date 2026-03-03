#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ans;
        unordered_set<int> notSame;
        for (int i = 0; i < nums.size(); i++)
        {
            if (notSame.find(nums[i]) != notSame.end())
            {
                ans.push_back({notSame.begin(), notSame.end()});
                notSame.erase(notSame.begin(), notSame.end());
            }
            notSame.insert(nums[i]);
        }
        if (!notSame.empty()) ans.push_back({notSame.begin(), notSame.end()});
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {8,8,8,8,2,4,4,2,4};
    cout << "Convert an Array Into a 2D Array With Conditions : " << endl;
    vector<vector<int>> ans = s.findMatrix(nums);
    for (auto num : ans)
    {
        for (auto n : num)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}