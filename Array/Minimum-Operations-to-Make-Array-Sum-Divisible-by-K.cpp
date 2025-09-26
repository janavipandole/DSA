#include <iostream>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }

        if (sum % k == 0)
            return 0;
        return sum % k;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 1, 3};
    int k = 4;
    cout << "Minimum Operations to Make Array Sum Divisible by K : " << s.minOperations(nums, k) << endl;
    return 0;
}