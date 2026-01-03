#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int minAbs = abs(nums[0] - nums[1]);
        for (int i = 0; i < nums.size(); i++)
        {
            int num1 = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                int num2 = nums[j];
                if (abs(num2 - num1) == minAbs)
                {
                    ans.push_back({num1, num2});
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {40, 11, 26, 27, -20};
    cout << "Minimum Absolute Difference : " << endl;
    vector<vector<int>> ans = s.minimumAbsDifference(nums);
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