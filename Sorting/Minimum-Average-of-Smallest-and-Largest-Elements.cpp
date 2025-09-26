#include <iostream>
using namespace std;
class Solution
{
public:
    double minimumAverage(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        double ans = INT_MAX;
        for (int i = 0; i < n / 2; i++)
        {
            ans = min(ans, ((double)nums[i] + (double)nums[n - i - 1]) / 2.0);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {7, 8, 3, 4, 15, 13, 4, 1};
    cout << "Minimum Average of Smallest and Largest Elements : " << s.minimumAverage(nums) << endl;
    return 0;
}