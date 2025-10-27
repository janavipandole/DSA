#include <iostream>
using namespace std;
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());

        int st = 0, end = nums.size() - 1;
        while (st < end)
        {
            ans += nums[end] - nums[st];
            st++;
            end--;
        }
        if(nums.size() % 2 != 0) ans += nums[end];
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout<<"Maximum Alternating Sum of Squares : " << s.maxAlternatingSum(nums) << endl;
    return 0;
}