#include <iostream>
using namespace std;
class Solution
{
public:
    int missingNum(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
            ans ^= i + 1;
        }
        ans ^= n + 1;
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 5};
    cout << "missing Num " << s.missingNum(nums) << endl;
    return 0;
}