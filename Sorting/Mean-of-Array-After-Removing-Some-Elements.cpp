#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    double trimMean(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        double ans = 0;

        int start = (nums.size() * 5) / 100;
        int end = (nums.size() * 95) / 100;

        for (int i = start; i < end; i++)
        {
            ans += nums[i];
        }
        ans = ans / (nums.size() - 2 * start);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
    cout << "Mean of Array After Removing Some Elements : " << s.trimMean(nums) << endl;
    return 0;
}