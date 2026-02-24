#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4}, index = {0, 1, 2, 2, 1};
    cout << "Create Target Array in the Given Order : " << endl;
    vector<int> ans = s.createTargetArray(nums, index);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}