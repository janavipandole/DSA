#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return {};
        sort(nums.begin(), nums.end());

        vector<int> ans;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << "Find All Duplicates in an Array : " << endl;
    vector<int> ans = s.findDuplicates(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}