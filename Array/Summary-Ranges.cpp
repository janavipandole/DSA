#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        if (nums.size() < 1) return result;

        int n = nums.size(), start = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (start == nums[i - 1]) result.push_back(to_string(start));
                else result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
        
                start = nums[i];
            }
        }
        // Add last range
        if (start == nums.back()) result.push_back(to_string(start));
        else result.push_back(to_string(start) + "->" + to_string(nums.back()));

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    cout << "Summary Ranges : " << endl;
    vector<string> ans = s.summaryRanges(nums);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}